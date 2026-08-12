#include <Arduino.h>
#include <SPI.h>

//#include "RFID_MFRC522/MFRC522_Driver.h"
#include "oled.h"
#include "rs485.h"
#include "ultrasonico.h"
#include "rc522_test.h"

void setup()
{
    Serial.begin(115200);
    Serial.println("Init: serial port");
    oled_init();
    Serial.println("Init: oled");
    rs485_init();
    Serial.println("Init: rs485");
   // MFRC522_begin();
   rc522_test(); 
   Serial.println("Init: rc522");
    ultrasonico_init();
    Serial.println("Init: ultrasonico");
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.println("Init: listo");
}

void loop()
{
    ultrasonico_loop();
    rs485_loop();
    ///MFRC522_loop();
    static unsigned long t = 0;

    if (millis() - t > 5000)
    {
        t = millis();

        digitalWrite(LED_BUILTIN, HIGH);
        delay(250);
        digitalWrite(LED_BUILTIN, LOW);

        Serial.println("Estoy aca");
    }
}