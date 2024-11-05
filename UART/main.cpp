/*
===============================================================================
 Name        : main.c
 Author      : Ing.Marcelo Trujillo
 Description : Prueba Expansion 1
===============================================================================
*/
#include "aplicacion.h"
#include "inicializarInfotronic.h"

int main ( void )
{
	uint8_t tecla,inx;
	char aux[20];
	char aux1[20];

	InicializarInfotronic ( ) ;

	g_Display.SetDisplay(123, Display7Segmentos::DSP0);
	g_Display.SetDisplay(456, Display7Segmentos::DSP1);

	LCD.Set("   Hola Mundo   ", 0, 0 );
	LCD.Set("                ", 1, 0 );

	while ( 1 )
	{
		tecla = g_Teclado.GetKey();

		if ( (inx = uart0.Message(aux1, 8)) )
		{
			aux1[inx] = '\0';
			LCD.Set((const char*) aux1, 1, 0 );
		}
		if ( tecla != NO_KEY)
		{
			g_Display.SetDisplay(tecla, Display7Segmentos::DSP0);
			aux[2] = 'C';
			aux[3] = 'H';
			aux[4] = 'A';
			aux[5] = 'U';
			aux[0] = '\xd';
			aux[1] = '\xa';
			aux[6] = '\0';

			uart0.Transmit(aux);
		}

	}


}
