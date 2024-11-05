/*******************************************************************************************************************************//**
 *
 * @file		swhandler.cpp
 * @brief		funciones miembro de la clase swhandler
 * @date		27 may. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include "perifericotemporizado.h"
#include "systick.h"

/***********************************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 **********************************************************************************************************************************/
#define N_PERIFERICOS_TEMPORIZADOS		50

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
 *** VARIABLES GLOBALES PUBLICAS
 **********************************************************************************************************************************/
PerifericoTemporizado *g_perifericosTemporizados[ N_PERIFERICOS_TEMPORIZADOS ];
uint8_t PerifericoTemporizado::m_countPerifericosTemporizados = 0;

/***********************************************************************************************************************************
 *** IMPLEMENTACION DE LOS METODODS DE LA CLASE
 **********************************************************************************************************************************/
PerifericoTemporizado::PerifericoTemporizado(  )
{
}

PerifericoTemporizado::~PerifericoTemporizado() {
}

void PerifericoTemporizado::InstalarPerifericoTemporizado (PerifericoTemporizado * periferico)
{
	g_perifericosTemporizados[m_countPerifericosTemporizados] = periferico;
	m_countPerifericosTemporizados ++;

}