#include <Arduino.h>
#include "RS485_Driver.h"
#include "../ESP32_PinsConfig.h"
#include "../Debug_setup.h"

HardwareSerial RS485Serial(2);

void rs485_init()
{
    pinMode(RS485_EN, OUTPUT);

    // Comenzamos en recepción
    digitalWrite(RS485_EN, LOW);

    // UART RS485
    RS485Serial.begin(
        9600,
        SERIAL_8N1,
        RS485_RX,
        RS485_TX);
}

void rs485_loop()
{
    //-----> Recibir mensajes
    if (RS485Serial.available())
    {
        String mensaje = RS485Serial.readStringUntil('\n');

        DEBUG_("RS485 RX: ");
        DEBUG(mensaje);
    }
}

void rs485_send(String _data)
{
    // Comenzar a transmitir
    digitalWrite(RS485_EN, HIGH);

    RS485Serial.print(_data);

    // Esperar a que termine de transmitir
    RS485Serial.flush();

    DEBUG("RS485 send: " + _data)

    // Volver a recepción
    digitalWrite(RS485_EN, LOW);
}