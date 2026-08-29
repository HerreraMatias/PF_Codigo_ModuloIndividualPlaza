#include <Arduino.h>
#include "NEXTION_Driver.h"
#include "../ESP32_PinsConfig.h"
#include "../Debug_setup.h"

HardwareSerial Nextion_Serial(1);

void nextion_init()
{

    // UART RS485
    Nextion_Serial.begin(
        9600,
        SERIAL_8N1,
        NEXTION_RX,
        NEXTION_TX);
}

void nextion_loop()
{
    //-----> Recibir mensajes
    if (Nextion_Serial.available())
    {
        String mensaje = Nextion_Serial.readStringUntil('\n');

        DEBUG_("Nextion RX: ");
        DEBUG(mensaje);
    }
}

void nextion_send(String _data)
{
    Nextion_Serial.print(_data);

    // Terminador de comando Nextion
    Nextion_Serial.write(0xFF);
    Nextion_Serial.write(0xFF);
    Nextion_Serial.write(0xFF);

    // Esperar a que termine de transmitir
    Nextion_Serial.flush();

    DEBUG("Nextion send: " + _data);
}