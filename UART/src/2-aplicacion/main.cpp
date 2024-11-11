/*
===============================================================================
 Name        : main.c
 Author      : Ing.Marcelo Trujillo
 Description : Prueba Expansion 1
===============================================================================
*/
#include "aplicacion.h"
#include "inicializarInfotronic.h"
#include "1-modulos/13-I2C/I2C.h"

int main(void)
{
    InicializarInfotronic();

    // Mostrar texto de bienvenida
    LCD.Set("    MIMIUXXX    ", 0, 0);
    LCD.Set("   FAUSTOXXXX   ", 1, 0);

    // Crear objetos para I2C
    I2C i2c0(0);  // Objeto I2C para maestro (I2C0)
    I2C i2c1(1);  // Objeto I2C para esclavo (I2C1)

    // Inicializar I2C
    i2c0.init();  // Inicializa I2C0 como maestro
    i2c1.init();  // Inicializa I2C1 como esclavo

    uint8_t dataToSend[] = {0x01, 0x02, 0x03};
    uint8_t receivedData[3];

    // Enviar datos desde el maestro
    i2c0.sendData(dataToSend, sizeof(dataToSend));

    // Recibir datos en el esclavo
    i2c1.receiveData(receivedData, sizeof(receivedData));

    // Verificar si los datos enviados son los mismos que los recibidos
    bool success = true;
    for (int i = 0; i < sizeof(dataToSend); i++) {
        if (dataToSend[i] != receivedData[i]) {
            success = false;
            break;
        }
    }

    // Mostrar el resultado en la pantalla LCD
    if (success) {
        LCD.Set("   CONEXION OK   ", 0, 0);
    } else {
        LCD.Set("   ERROR COMUNICACION   ", 0, 0);
    }

    while (1) {
        // Aquí puedes añadir cualquier otra lógica si es necesario
    }

    return 0;
}
