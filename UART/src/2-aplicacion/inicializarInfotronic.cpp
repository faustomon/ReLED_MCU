/*******************************************************************************************************************************//**
 *
 * @file		inicializar.cpp
 * @brief		Descripcion del modulo
 * @date		5 jul. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/

#include "inicializarInfotronic.h"
#include "aplicacion.h"

/***********************************************************************************************************************************
 *** TABLAS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/**********************************************************************************
 *** OBJETOS GLOBALES PUBLICOS
 **********************************************************************************/

// Display de 7 segmentos #########################################################
// segmentos - I4511_segmentos---------------------------------------------------------
#ifdef KIT2022
	Gpio g_bcdA(  Gpio::PORT0 , 20 , Gpio::PUSHPULL ,  Gpio::OUTPUT , Gpio::HIGH );
	Gpio g_bcdB(  Gpio::PORT0 , 23 , Gpio::PUSHPULL ,  Gpio::OUTPUT , Gpio::HIGH );
	Gpio g_bcdC(  Gpio::PORT0 , 22 , Gpio::PUSHPULL ,  Gpio::OUTPUT , Gpio::HIGH );
	Gpio g_bcdD(  Gpio::PORT0 , 21 , Gpio::PUSHPULL ,  Gpio::OUTPUT , Gpio::HIGH );
	Gpio g_dp(  Gpio::PORT0 ,   12 , Gpio::PUSHPULL ,  Gpio::OUTPUT , Gpio::HIGH );
#else
	Gpio g_bcdA(  Gpio::PORT0 , 23 , Gpio::PUSHPULL ,  Gpio::OUTPUT , Gpio::HIGH );
	Gpio g_bcdB(  Gpio::PORT0 , 22 , Gpio::PUSHPULL ,  Gpio::OUTPUT , Gpio::HIGH );
	Gpio g_bcdC(  Gpio::PORT0 , 21 , Gpio::PUSHPULL ,  Gpio::OUTPUT , Gpio::HIGH );
	Gpio g_bcdD(  Gpio::PORT0 , 20 , Gpio::PUSHPULL ,  Gpio::OUTPUT , Gpio::HIGH );
	Gpio g_dp(  Gpio::PORT0 ,   12 , Gpio::PUSHPULL ,  Gpio::OUTPUT , Gpio::LOW );
#endif

Gpio *g_I4511_segmentos[] = { &g_bcdA,&g_bcdB,&g_bcdC,&g_bcdD,&g_dp};
I4511_Segmentos g_I4511Segmentos(g_I4511_segmentos);

// digitos - g_I4017_digitos ---------------------------------------------------------
Gpio g_rst(  Gpio::PORT0,  18 , Gpio::PUSHPULL ,  Gpio::OUTPUT , Gpio::HIGH );
Gpio g_clk(  Gpio::PORT0 , 19 , Gpio::PUSHPULL ,  Gpio::OUTPUT , Gpio::HIGH );

Gpio *g_I4017_digitos[] = { &g_rst,&g_clk,};
I4017_Barrido g_I4017Barrido( g_I4017_digitos );

GrupoDeDigitos Grupos[]=
{
	{ 0 , 3 },
	{ 3 , 3 },
	{-1 , -1 }
};

Display7Segmentos g_Display( &g_I4511Segmentos , &g_I4017Barrido , Grupos );

// ##################################################################################
// TECLADO -----------------------------------------------------------------------
#ifdef KIT2022
	Gpio g_ret0 ( Gpio::PORT0 ,  8 , Gpio::PULLUP , Gpio::INPUT , Gpio::LOW );
	Gpio g_ret1 ( Gpio::PORT0 , 31 , Gpio::PULLUP , Gpio::INPUT , Gpio::LOW );
	Gpio g_ret2 ( Gpio::PORT0 , 30 , Gpio::PULLUP , Gpio::INPUT , Gpio::LOW );

	Gpio g_scn0 ( Gpio::PORT0, 27, Gpio::PUSHPULL , Gpio::OUTPUT , Gpio::HIGH );
	Gpio g_scn1 ( Gpio::PORT0, 28, Gpio::PUSHPULL , Gpio::OUTPUT , Gpio::HIGH );
#else
	Gpio g_ret0 ( Gpio::PORT0 , 26 , Gpio::PULLUP , Gpio::INPUT , Gpio::LOW );
	Gpio g_ret1 ( Gpio::PORT0 , 15 , Gpio::PULLUP , Gpio::INPUT , Gpio::LOW );
	Gpio g_ret2 ( Gpio::PORT0 ,  8 , Gpio::PULLUP , Gpio::INPUT , Gpio::LOW );

	Gpio g_scn0 ( Gpio::PORT0, 27, Gpio::PUSHPULL , Gpio::OUTPUT , Gpio::HIGH );
	Gpio g_scn1 ( Gpio::PORT0, 28, Gpio::PUSHPULL , Gpio::OUTPUT , Gpio::HIGH );
#endif

Gpio *g_scn[] = {&g_scn0 , &g_scn1, nullptr};
Gpio *g_ret[] = {&g_ret0 , &g_ret1, &g_ret2,  nullptr};

Teclado g_Teclado( g_ret , g_scn );

//!<	ENTRADAS DIGITALES
#ifdef KIT2022
	Gpio g_in0( Gpio::PORT0 , 4 , Gpio::PUSHPULL ,  Gpio::INPUT , Gpio::LOW );
	Gpio g_in1( Gpio::PORT0 , 26 , Gpio::PUSHPULL ,  Gpio::INPUT , Gpio::LOW );
#else
	Gpio g_in0( Gpio::PORT0 , 4 , Gpio::PUSHPULL ,  Gpio::INPUT , Gpio::LOW );
	Gpio g_in1( Gpio::PORT0 , 3 , Gpio::PUSHPULL ,  Gpio::INPUT , Gpio::HIGH);
#endif

//!< GPIO ENTRADAS SALIDAS DE PROPOSITO GENERAL
Gpio g_out0( Gpio::PORT1 , 0 , Gpio::PUSHPULL ,  Gpio::OUTPUT , Gpio::HIGH );
Gpio g_out1( Gpio::PORT1 , 1 , Gpio::PUSHPULL ,  Gpio::OUTPUT , Gpio::HIGH );
Gpio g_out2( Gpio::PORT1 , 2 , Gpio::PUSHPULL ,  Gpio::OUTPUT , Gpio::HIGH );

//!<	LCD
Gpio g_d4 ( Gpio::PORT0,  9, Gpio::PUSHPULL , Gpio::OUTPUT , Gpio::HIGH );
Gpio g_d5 ( Gpio::PORT0, 10, Gpio::PUSHPULL , Gpio::OUTPUT , Gpio::HIGH );
Gpio g_d6 ( Gpio::PORT0, 11, Gpio::PUSHPULL , Gpio::OUTPUT , Gpio::HIGH );
Gpio g_d7 ( Gpio::PORT0, 13, Gpio::PUSHPULL , Gpio::OUTPUT , Gpio::HIGH );
Gpio g_rs ( Gpio::PORT0,  1, Gpio::PUSHPULL , Gpio::OUTPUT , Gpio::HIGH );
Gpio g_en ( Gpio::PORT0, 14, Gpio::PUSHPULL , Gpio::OUTPUT , Gpio::HIGH );

Gpio *BusLcd[] = { &g_d4 ,&g_d5 ,&g_d6 ,&g_d7 ,&g_rs,&g_en};
Lcd LCD(BusLcd);

// terminal MCUXpresso
Uart uart0(
		0 , 				// PortTx
        25, 				// Pin Tx
		0 ,					// PortRx
		24, 				// Pin Rx
		0 ,					// uart seleccionada
		9600 ,				// baudios
		Uart::ocho_bits ,	// bits de datos
		Uart::NoParidad ,	// tipo de paridad
		64,					// tamaño de buffer de Rx
		64 );				// tamaño de buffer de Tx

// salida exterior LPC
Uart uart1(
		0 , 				// PortTx
        16, 				// Pin Tx
		0 ,					// PortRx
		17, 				// Pin Rx
		1 ,					// uart seleccionada
		9600 ,				// baudios
		Uart::ocho_bits ,	// bits de datos
		Uart::NoParidad ,	// tipo de paridad
		64,					// tamaño de buffer de Rx
		64 );				// tamaño de buffer de Tx

void InicializarInfotronic ( void )
{
	Inicializar_PLL( );

	g_out1.ClrPin();
	g_out1.ClrPin();
	g_out1.ClrPin();

	SysTick_InstalarCallBack( Sheduller );
	SysTick_Inicializar(1);
}

