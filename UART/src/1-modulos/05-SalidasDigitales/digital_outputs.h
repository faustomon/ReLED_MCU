/*******************************************************************************************************************************//**
 *
 * @file		DigitalOutputs.h
 * @brief		Breve descripción del objetivo del Módulo
 * @date		12 jul. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/

#ifndef DIGITAL_OUTPUTS_H_
#define DIGITAL_OUTPUTS_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
#include "systick.h"
#include "gpio.h"
#include "perifericotemporizado.h"

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

class DigitalOutputs : protected Gpio, public PerifericoTemporizado
{
	uint8_t m_bufferOutputs;

	public:
		DigitalOutputs( uint8_t puerto , uint8_t bit , uint8_t modo , uint8_t actividad , uint8_t estado );
		int8_t set ( void );
		int8_t clr ( void );

		DigitalOutputs& operator= ( uint8_t estado );
		void HandlerDelPeriferico ( void );

		virtual ~DigitalOutputs(){};
};

#endif /* DIGITAL_OUTPUTS_H_ */
