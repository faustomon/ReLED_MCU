/*
 * I2C.h
 *
 *  Created on: 5 nov. 2024
 *      Author: faust
 */

#ifndef SRC_1_MODULOS_13_I2C_I2C_H_
#define SRC_1_MODULOS_13_I2C_I2C_H_

#include "LPC845.h"
#include "Lcd.h"
#include "inicializarInfotronic.h"

#define SYSAHBCLKCTRL0_I2C0 5
#define SYSAHBCLKCTRL0_I2C1 21
#define SYSAHBCLKCTRL0_I2C2 22
#define SYSAHBCLKCTRL0_I2C3 23

#define PRESETCTRL_I2C0 5
#define PRESETCTRL_I2C1 21
#define PRESETCTRL_I2C2 22
#define PRESETCTRL_I2C3 23

#define IRQ_I2C0 8
#define IRQ_I2C1 7
#define IRQ_I2C2 21
#define IRQ_I2C3 22

#define TIMEOUT 10000

class I2C {
private:
	I2C_Type  *m_I2C;
public:
	typedef enum { I2C_0, I2C_1, I2C_2, I2C_3}I2C_Instance;

	I2C(uint8_t instance);
	void configurePinOpenDrain(uint32_t pin);
	void i2c_pin_init(void);
	void init();  // Función para inicializar la interfaz I2C
	void sendData(uint8_t *data, uint32_t length);  // Función para enviar datos (modo maestro)
	void receiveData(uint8_t *buffer, uint32_t length);  // Función para recibir datos (modo esclavo)

private:
    uint8_t instance;  // Instancia de I2C (0 o 1)

};

#endif /* SRC_1_MODULOS_13_I2C_I2C_H_ */
