#include <Arduino.h>


HardwareSerial RS485Serial(2);

#define RS485_RX 17
#define RS485_TX 16
#define RS485_EN 4

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

    Serial.println("ESP32 iniciado");
}

void rs485_loop()
{
        // -------------------------
        // TRANSMITIR
        // -------------------------
     /*   static int index = 0;
        index++;
        digitalWrite(RS485_EN, HIGH);

        RS485Serial.println("Index: " + String(index));

        // Esperar a que termine de transmitir
        RS485Serial.flush();

        // Volver a recepción
        digitalWrite(RS485_EN, LOW);
    */

    // -------------------------
    // RECIBIR
    // -------------------------

    if (RS485Serial.available())
    {
        String mensaje = RS485Serial.readStringUntil('\n');

        Serial.print("RS485 RX: ");
        Serial.println(mensaje);
    }
}