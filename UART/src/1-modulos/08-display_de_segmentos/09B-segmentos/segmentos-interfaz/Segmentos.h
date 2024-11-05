/*******************************************************************************************************************************//**
 *
 * @file		segmentos.h
 * @brief		Breve descripción del objetivo del Módulo
 * @date		27 jul. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/

#ifndef SRC_I0_DISPLAY7SEGMENTOS_SEGMENTOS_H_
#define SRC_I0_DISPLAY7SEGMENTOS_SEGMENTOS_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
#include "tipos.h"

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

class Segmentos
{
	public:
		Segmentos(){};
		virtual bool SetSegmentos ( uint8_t ) = 0;
		virtual void ClrSegmentos ( void ) = 0;
		virtual ~Segmentos(){};
};

#endif /* SRC_I0_DISPLAY7SEGMENTOS_SEGMENTOS_H_ */