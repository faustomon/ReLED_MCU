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
#include "systick.h"

using namespace std;
/***********************************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 **********************************************************************************************************************************/
#define MAX_TICKS 	0xffffff

/***********************************************************************************************************************************
 *** MACROS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPOS DE DATOS PRIVADOS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TABLAS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** OBJETOS GLOBALES PUBLICOS
 *********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 **********************************************************************************************************************************/
volatile void (*sysTickCallback)( void ) = nullptr ;

void SysTick_Handler(void)
{
	if ( sysTickCallback )
		sysTickCallback( );
}

void SysTick_InstalarCallBack( void (*callBack)(void) )
{
	 sysTickCallback = (volatile void (*)(void))callBack;
}

uint32_t SysTick_Inicializar( uint32_t ms )
{
	uint32_t frecuenciaSystick , ticks ;
	frecuenciaSystick = 1000 / ms;				 	// frecuenciaSystick = 1 / ( ms * 0.001)

	ticks = FREQ_CLOCK / frecuenciaSystick;  		// ticks = Tsystic / Tclock ;

	if (ticks > MAX_TICKS)
		return 1 ;          						// Reload value fuera de rango

	SysTick->RELOAD = ticks - 1;  					// Cargamos la Cuenta

	SysTick->CURR = 0;   							// SysTick Counter en 0 para que se recargue

	SysTick->CTRL = 7;								// ENABLE = 1, TICKINT = 1, CLKSOURCE = 1;

	return 0;
}
