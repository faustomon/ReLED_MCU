/*
 * I2C.cpp
 *
 *  Created on: 5 nov. 2024
 *      Author: faust
 */

#include <1-modulos/13-I2C/I2C.h>
#include "swm.h"

#define SLAVE_ADDRESS 0x28 // Dirección I2C del esclavo (I2C1)


//void i2c0_init( void ){
//	// Configuración i2c
//
//	IOCON->PIO[7] = 0x80;
//	IOCON->PIO[8] = 0x80;
//	SYSCON->PRESETCTRL0 &= ~(1<<PRESETCTRL_I2C0);
//	SYSCON->PRESETCTRL0 |=(1<<PRESETCTRL_I2C0);
//	// clock
//	SYSCON->FCLKSEL[5] = 0x0;
//	SYSCON->SYSAHBCLKCTRL0 |= (1<<SYSAHBCLKCTRL0_I2C0);
//	I2C0->CLKDIV = 0;
//	I2C0->CLKDIV = 239;
//	I2C0->MSTTIME = 0;
//	I2C0->CFG |= (1<<0);
//
//	SYSCON->SYSAHBCLKCTRL0 |= (1<<7);
//	SWM0->PINENABLE0 &= ~(1<<12);
//	SWM0->PINENABLE0 &= ~(1<<13);
//	SYSCON->SYSAHBCLKCTRL0 &= ~(1<<7);
//
//}


I2C::I2C(unsigned char instance) {
    // Implementación del constructor
    // Asignar el valor de 'instance' o realizar la inicialización del objeto
    this->instance = instance;
}


void I2C::init() {
	this->i2c_pin_init();
	if (instance == 0) {
        // Inicialización de I2C0 (Maestro)
        IOCON->PIO[7] = 0x80;  // Configura SDA0
        IOCON->PIO[8] = 0x80;  // Configura SCL0
        SYSCON->PRESETCTRL0 &= ~(1 << PRESETCTRL_I2C0);
        SYSCON->PRESETCTRL0 |= (1 << PRESETCTRL_I2C0);
        SYSCON->FCLKSEL[5] = 0x0;
        SYSCON->SYSAHBCLKCTRL0 |= (1 << SYSAHBCLKCTRL0_I2C0);
        I2C0->CLKDIV = 500;  // Configura el reloj
        I2C0->MSTTIME = 0;   // Configura el tiempo
        I2C0->CFG |= (1 << 0);  // Configura como maestro
    }
    else if (instance == 1) {
        // Inicialización de I2C1 (Esclavo)
        IOCON->PIO[9] = 0x80;  // Configura SDA1
        IOCON->PIO[10] = 0x80; // Configura SCL1
        I2C1->SLVADR0 = (SLAVE_ADDRESS << 1);
        I2C1->SLVCTL = (1 << 0);  // Configura como esclavo
    }
}

void I2C::sendData(uint8_t *data, uint32_t length) {
	uint32_t timeout = 0;
	if (instance == 0) {
        // Modo maestro: envío de datos
        for (uint32_t i = 0; i < length; i++) {
            I2C0->MSTDAT = data[i];    // Envía un byte
            I2C0->MSTCTL = (1 << 0);   // Inicia la transmisión

            while (!(I2C0->STAT & (1 << 1)) && (timeout < TIMEOUT));
            timeout++; // Espera el ACK
        }
        if (timeout == TIMEOUT) {
        	// Manejo de error si no se recibe el ACK
        	LCD.Set("    TIME OUT    ", 1, 0);
}
        I2C0->MSTCTL = (1 << 2);  // Envia STOP
    }
}

void I2C::receiveData(uint8_t *buffer, uint32_t length) {
    if (instance == 1) {
        // Modo esclavo: recibir datos
        uint32_t i = 0;
        while (i < length) {
            while (!(I2C1->STAT & (1 << 0)));  // Espera hasta que un dato esté listo
            buffer[i] = I2C1->SLVDAT;  // Lee el dato
            I2C1->SLVCTL |= (1 << 0);  // Acepta el dato
            i++;
        }
    }
}

void I2C::configurePinOpenDrain(uint32_t pin) {
    // Configura el pin como GPIO
    IOCON->PIO[pin] &= ~(0x07);  // Borra los bits de función (bits 0-2)
    IOCON->PIO[pin] |= 0x01;     // Selecciona la función GPIO (Función 0)

    // Configura el pin en Open Drain
    IOCON->PIO[pin] |= (0x40);   // Activa el modo Open Drain (bit 6)
}

void I2C::i2c_pin_init(void) {
    // Configura los pines SDA y SCL para I2C0 como Open Drain
    configurePinOpenDrain(7);  // PIO7 para SDA (puedes cambiar el número del pin según tu configuración)
    configurePinOpenDrain(8);  // PIO8 para SCL (puedes cambiar el número del pin según tu configuración)
}
