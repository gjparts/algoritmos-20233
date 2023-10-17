<?php
require_once("../globales.php");
require_once("../conexionSQL.php");
tratamientoInyeccionSQL_VariablePOST();

header('Content-Type: application/json');

//conectar al servidor de base de datos
$ws = new conexionSQL();

//verificar si clave unica es correcta
if ( $ws->claveUnica != $_POST["authkey"] )
{
    //no autenticado, no concuerdan las claves
    echo $ws->mensajeJSON(false,"No autorizado");

    exit(0);
}
if ( $ws->Autenticado == true )
{
    //crear objeto de encabezado
    $encabezado = new stdClass();
    $detalle = new stdClass();

    $ptmo = $ws->obtenerArray("
    SELECT a.PrestamoID, a.ClienteID, a.FechaInicio, a.Distribucion, a.MontoInicial, a.PlazoMeses, a.Tasa, a.Estado, a.FechaPosteriorDePago, b.Display as DistribucionNombre
    FROM Prestamo a
        INNER JOIN Item b ON b.Categoria = 'PrestamoDistribucion' AND b.Valor = a.Distribucion
    WHERE a.PrestamoID = ".$_POST["prestamoid"]);

    /*if( $ptmo[0]->Distribucion == "CNIVELADA" ) $ptmo[0]->Distribucion = "CUOTA_NIVELADA";
    if( $ptmo[0]->Distribucion == "CFIJACAP" ) $ptmo[0]->Distribucion = "CAPITAL_INTERES";
    if( $ptmo[0]->Distribucion == "CFIJACAP_INTANT" ) $ptmo[0]->Distribucion = "CAPITAL_INTERES_ANTICIPADO";*/
    if( $ptmo[0]->Estado == "PAGADO" ){
        echo $ws->mensajeJSON(false,"El préstamo ya fue cancelado.");
        exit(0);
    }

    //prestamo tiene fecha posterior de pago
    $etFechaPosteriorDePago = false;
    if( $ptmo[0]->FechaPosteriorDePago != NULL )
        $etFechaPosteriorDePago = true;

    //obtenemos los datos encontrados
    $encabezado->PrestamoID = (int)$ptmo[0]->PrestamoID;
    $encabezado->ClienteID = (int)$ptmo[0]->ClienteID;
    $encabezado->Monto = (float)$ptmo[0]->MontoInicial;
    $encabezado->Tasa = (float)$ptmo[0]->Tasa;
    $encabezado->PlazoMeses = (int)$ptmo[0]->PlazoMeses;
    $encabezado->FechaInicio = $ptmo[0]->FechaInicio;
    $encabezado->Distribucion = $ptmo[0]->DistribucionNombre;

    //variable para ubicar los intereses anticipados pendientes de calcular en prestamo CFIJACAP
    $InteresAnticipado = 0.00;
    //obtener los pagos hechos a este prestamo en el dia actual
    $dtPagos = $ws->obtenerArray("
    SELECT PagoID, CapitalVigente, CapitalVigentePagar, CapitalAtrasado, CapitalVencido, InteresAtrasadoCalculado, InteresVigenteCalculado,
           InteresAnticipadoCalculado, InteresVencido, Cargo1,Cargo2, Cargo3, Cargo4, Cargo5, Cargo6, Cargo7, Cargo8, Cargo9,
           Cargo10, Cargo11, Cargo12, Cargo13, Cargo14, Cargo15, InteresMoratorio
    FROM Pago
    WHERE PrestamoID = {$ptmo[0]->PrestamoID} AND Fecha = dbo.FechaCalendario('Prestamos') AND PrestamoTipoPagoID <> 'PAGOCUOTAS' AND Anulado = 0
    ORDER BY PagoID DESC");

    //obtener el ultimo saldo del prestamo
    $dtSaldos = $ws->obtenerArray("
    SELECT TOP(1) Fecha, CapitalVigente, CapitalVigentePagar, CapitalAtrasado, CapitalVencido, InteresAnticipado,
           InteresAtrasadoCalculado, InteresVigenteCalculado, InteresAnticipadoCalculado, InteresVencido, Cargo1,Cargo2, Cargo3,
           Cargo4, Cargo5, Cargo6, Cargo7, Cargo8, Cargo9, Cargo10, Cargo11, Cargo12, Cargo13, Cargo14, Cargo15,
           ( SELECT COUNT(Cuota) FROM PrestamoPlanPago WHERE PrestamoID = {$ptmo[0]->PrestamoID} AND Pagada = 0 ) as CuotasPendientes
    FROM PrestamoSaldo
    WHERE PrestamoID = {$ptmo[0]->PrestamoID}
    ORDER BY Fecha DESC
    ");

    //si la distribucion del prestamo es no es de Interes Anticipado entonces pone en cero ese textbox
    if( $ptmo[0]->Distribucion == "CFIJACAP" ){
        //pone en el TAG el valor de interes anticipado que debería ser, este valor será util para trabajar con cuotas adelantadas en CFIJACAP
        $InteresAnticipado = $dtSaldos[0]->InteresAnticipadoCalculado;
        $dtSaldos[0]->InteresAnticipadoCalculado = 0.0;
    }

    if( count($dtSaldos) == 0 ){
        echo $ws->mensajeJSON(false,"Préstamo no tiene saldos reflejados.");
        exit(0);
    }

    $iMoraPagados = 0.00;
    $CantidadCuotasCapitalPagadasPago = 0;
    $ValorCuotaCapitalEstePrestamo = 0.00;
    $CapitalAbonadoHoy = 0.00;

    $ValorCuotaCapitalEstePrestamo = $ws->obtenerEscalar("
    SELECT ISNULL(CuotaPago,0.00)+ISNULL(CuotaCapital,0.00)
    FROM Prestamo
    WHERE PrestamoID = ".$ptmo[0]->PrestamoID);

    for( $i = 0; $i < count($dtPagos); $i++ ){
        //intereses moratorios pagados en el dia
        $iMoraPagados += $dtPagos[$i]->InteresMoratorio;
        //sumar todo lo que se ha venido abonando a capitales
        $CapitalAbonadoHoy += $dtPagos[$i]->CapitalVigente+$dtPagos[$i]->CapitalVigentePagar+$dtPagos[$i]->CapitalAtrasado+$dtPagos[$i]->CapitalVencido;
    }
    //obtener la cantidad de cuotas abonadas por los pagos al dia de hoy que no se han procesado en cierre
    $CantidadCuotasCapitalPagadasPago = floor($CapitalAbonadoHoy/$ValorCuotaCapitalEstePrestamo);
    $CantidadCuotasCapitalPagadasPago = 0.00; //09/12/2019 (plan de pago ya no reflejará abonos al dia de hoy)

    $Monto = $dtSaldos[0]->CapitalVigente+$dtSaldos[0]->CapitalAtrasado+$dtSaldos[0]->CapitalVencido;
    $Tasa = (float)$ptmo[0]->Tasa;
    $Meses = $ws->obtenerEscalar("SELECT COUNT(Fecha) FROM PrestamoPlanPago WHERE PrestamoID = {$ptmo[0]->PrestamoID} AND Pagada = 0")-$CantidadCuotasCapitalPagadasPago;
    //obtener la fecha de la ultima cuota pagada
    $FechaInicio = $ws->obtenerEscalar("SELECT TOP(1) ISNULL(Fecha,( SELECT FechaInicio FROM Prestamo WHERE PrestamoID = {$ptmo[0]->PrestamoID} )) FROM PrestamoPlanPago WHERE PrestamoID = {$ptmo[0]->PrestamoID} AND Pagada = 1 ORDER BY Fecha DESC");
    //no hay una fecha de ultima cuota pagada
    if( date("Y",strtotime ( $FechaInicio )) == 1 ){
        //poner la fecha de inicio del prestamo como fecha de ultimopago
        $FechaInicio = $ptmo[0]->FechaInicio;
    }
    if( $ptmo[0]->DistribucionNombre == "Cuota Nivelada" ){
        $dt = $ws->obtenerArray("
        SELECT Cuota as NumeroPago, Fecha as FechaPago, NuevaFechaDePago as FechaDebePagar,
               0.00 as SaldoInicial, PagoFijoCuotaTotal as Pago,
               CuotaNiveladaCapital-CapitalPagado as Capital,
               CuotaNiveladaInteres-CuotaNiveladaInteresPagado as Interes, 0.00 as Cargos,
               0.00 as Saldo, 0.00 as InteresAcumulado
        FROM PrestamoPlanPago
        WHERE Pagada = 0 AND PrestamoID = {$ptmo[0]->PrestamoID}");

        $m = $Monto;
        $iacum = 0.00;
        $cc = 0.00;

        for( $i = 0; $i < count($dt); $i++ ){
            $dt[$i]->Capital = round($dt[$i]->Capital,2);
            $dt[$i]->Interes = round($dt[$i]->Interes,2);

            $cc += $dt[$i]->Capital;

            $dt[$i]->SaldoInicial = round($m,2);
            $dt[$i]->Cargos = (float)$ws->obtenerEscalar("SELECT Valor FROM PrestamoCargo WHERE PrestamoID = {$ptmo[0]->PrestamoID} AND Periodicidad = 'M'");
            $dt[$i]->Pago = $dt[$i]->Cargos+round($dt[$i]->Pago,2);
            $m = $m - $dt[$i]->Capital;
            $dt[$i]->Saldo = round($m,2);
            if( $dt[$i]->Saldo < 0 ) $dt[$i]->Saldo = 0.00;

            $iacum += round($dt[$i]->Interes,2);
            $dt[$i]->InteresAcumulado = $iacum;
            if( $dt[$i]->Capital+$dt[$i]->Interes+$dt[$i]->Cargos < $dt[$i]->Pago ){
                $dt[$i]->Pago = round($dt[$i]->Capital+$dt[$i]->Interes+$dt[$i]->Cargos,2);
            }
        }
        $detalle = $dt;
    }
    else{
        //generar plan de pago nuevo:

        // abrimos la sesión cURL
        $ch = curl_init();
        //var_dump($ptmo);
        // definimos la URL a la que hacemos la petición
        curl_setopt($ch, CURLOPT_URL,rutaLocal."query/projection.php");
        // indicamos el tipo de petición: POST
        curl_setopt($ch, CURLOPT_POST, TRUE);

        // definimos cada uno de los parámetros
        curl_setopt($ch, CURLOPT_POSTFIELDS,
            "desdeBanco=GJPARTS&authkey=".$_POST["authkey"]."&".
            "monto={$ptmo[0]->MontoInicial}&tasa={$ptmo[0]->Tasa}&meses={$ptmo[0]->PlazoMeses}&fechaInicio={$ptmo[0]->FechaInicio}&distribucion={$ptmo[0]->Distribucion}"
        );

        // recibimos la respuesta y la guardamos en una variable
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        $consulta = curl_exec ($ch);

        // cerramos la sesión cURL
        curl_close ($ch);

        //convertir el JSON a ARRAY
        $consulta = (json_decode("[".$consulta."]"));

        if( $consulta[0]->success == false )
        {
            echo $ws->mensajeJSON(false,$consulta[0]->response);
            return;
        }

        $dt = $consulta[0]->response;

        echo json_encode($dt);
    }

    $encabezado->detalle = $detalle;
    echo json_encode($encabezado);
}
else
{
    //no autenticado
    echo $ws->mensajeJSON(false,"No autenticado");
}
?>