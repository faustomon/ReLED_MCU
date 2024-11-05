/*******************************************************************************************************************************//**
 *
 * @file		EntradaDigital.h
 * @brief		Clase gpio
 * @date		27 may. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef DIGITAL_INPUTS_H_
#define DIGITAL_INPUTS_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
#include "systick.h"
#include "gpio.h"
#include "perifericotemporizado.h"

/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/
#define MAX_BOUNCE		4

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
 *** IMPLANTACION DE LA CLASE
 **********************************************************************************************************************************/
class DigitalInputs : protected Gpio , public PerifericoTemporizado
{
	private:
		uint8_t m_BufferEntrada ;
		uint8_t m_MaxBounce ;
		uint8_t m_CountBounce ;

	public:

		DigitalInputs( uint8_t puerto , uint8_t bit , uint8_t modo , uint8_t actividad , uint8_t MaxBounce = MAX_BOUNCE );
		uint8_t get ( void );
		explicit operator bool( ) ;
		bool operator!( void );

		// las virtuales puras deben ser si o si redefinidas
		void HandlerDelPeriferico ( void );
		virtual ~DigitalInputs( );
};

#endif /* DIGITAL_INPUTS_H_ */