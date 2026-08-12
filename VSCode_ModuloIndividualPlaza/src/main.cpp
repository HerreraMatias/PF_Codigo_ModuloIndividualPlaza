#include <Arduino.h>
#include <SPI.h>

// #include "RFID_MFRC522/MFRC522_Driver.h"
#include "OLED_DISPLAY/oled_display.h"
#include "RS485/RS485_Driver.h"
#include "ULTRASONICO_HCSR04/HCSR04_Driver.h"
#include "MEMORIA_EEPROM/EEPROM_functions.h"

#include "rc522_test.h"
#include "Debug_setup.h"

void setup()
{
    DEBUG_BEGIN
    eeprom
    oled_init();
    rs485_init();
    // MFRC522_begin();
    rc522_test();
    ultrasonico_init();
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    ultrasonico_loop();
    rs485_loop();
    /// MFRC522_loop();
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