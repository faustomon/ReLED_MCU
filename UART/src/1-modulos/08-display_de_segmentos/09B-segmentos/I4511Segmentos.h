/*******************************************************************************************************************************//**
 *
 * @file		I4511.h
 * @brief		Breve descripción del objetivo del Módulo
 * @date		27 jul. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/

#ifndef SRC_I0_DISPLAY7SEGMENTOS_I4511_H_
#define SRC_I0_DISPLAY7SEGMENTOS_I4511_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
#include <1-modulos/08-display_de_segmentos/09B-segmentos/segmentos-interfaz/Segmentos.h>
#include "Gpio.h"

/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** IMPLANTACION DE UNA CLASE
 **********************************************************************************************************************************/
class I4511_Segmentos : public Segmentos
{
	private:
		Gpio ** m_bcd ;
	public:
		I4511_Segmentos(Gpio **bcd):
		m_bcd (bcd){}
		bool SetSegmentos ( uint8_t ) ;
		void ClrSegmentos ( void );
		virtual ~I4511_Segmentos();
};


#endif /* SRC_I0_DISPLAY7SEGMENTOS_I4511_H_ */
