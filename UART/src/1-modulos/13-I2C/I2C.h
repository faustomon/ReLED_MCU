/*
 * I2C.h
 *
 *  Created on: 5 nov. 2024
 *      Author: faust
 */

#ifndef SRC_1_MODULOS_13_I2C_I2C_H_
#define SRC_1_MODULOS_13_I2C_I2C_H_

#include "LPC845.h"

class I2C {
private:
	I2C_Type  *m_I2C;
public:
	typedef enum { I2C_0 = 1 , I2C_1 = 2, I2C_2 = 3, I2C_3 = 4 }I2C_Instance;

	I2C(uint8_t  i2c);


};

#endif /* SRC_1_MODULOS_13_I2C_I2C_H_ */
