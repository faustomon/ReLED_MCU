/*
 * I2C.cpp
 *
 *  Created on: 5 nov. 2024
 *      Author: faust
 */

#include <1-modulos/13-I2C/I2C.h>
#include "swm.h"

#define SYSAHBCLKCTRL0_I2C0 5
#define SYSAHBCLKCTRL0_I2C1 21
#define SYSAHBCLKCTRL0_I2C2 22
#define SYSAHBCLKCTRL0_I2C3 23

I2C_Type*  I2Cs[]={ I2C0, I2C1, I2C2, I2C3 };

I2C::I2C(uint8_t  i2c){

	m_I2C = I2Cs[i2c];					// USART seleccionada

 switch ( i2c )
 	{
 		case I2C_0:

 			break;
 		case I2C_1:

 			break;
 		case I2C_2:

 			break;
 		case I2C_3:

 			break;
 	}
}
