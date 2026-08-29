#include <Arduino.h>

#include "ESP32_PinsConfig.h"
#include "RFID_MFRC522/MFRC522_Driver.h"
#include "OLED_DISPLAY/oled_display.h"
#include "RS485/RS485_Driver.h"
#include "ULTRASONICO_HCSR04/HCSR04_Driver.h"
#include "MEMORIA_EEPROM/EEPROM_functions.h"
#include "TIMER_TIC/Timer_tic.h"
#include "NEXTION/NEXTION_Driver.h"

#include "Debug_setup.h"

void setup()
{
    //-----> Puerto serie para debug.
    DEBUG_BEGIN
    DEBUG("Version: 1.1")
    //-----> Timers.
    Ticker_begin();
    //-----> Memoria eeprom.
    eeprom_begin();
    //-----> Pantalla oled.
    oled_init();
    //-----> Comunicación RS485.
    rs485_init();
    //-----> Lector RFID.
    MFRC522_init();
    //-----> Sensor ultrasonico.
    ultrasonico_init();
    //-----> Nextion.
    nextion_init();
    //-----> Pin LED.
    pinMode(LED_PIN, OUTPUT);
    pinMode(RELAY_1, OUTPUT);
    pinMode(RELAY_2, OUTPUT);
    pinMode(RELAY_3, OUTPUT);
    digitalWrite(RELAY_1, HIGH);
    digitalWrite(RELAY_2, HIGH);
    digitalWrite(RELAY_3, HIGH);
}

void loop()
{
    /**************** LOOPING FUNCTIONS ****************/
    MFRC522_loop();     // Lectura de tarjetas RFID.
    ultrasonico_loop(); // Lectura de sensor ultrasonico.
    rs485_loop();       // Recepción de mensajes RS485.
    nextion_loop();     // Recepción de mensajes Nextion.
    /***************************************************/

    //-----> Registro nueva tarjeta rfid
    if (rfid_new_id)
    {
        rfid_new_id = false; // Deshabilito
        rs485_send("New rfid: " + rfid_serial_id);
        oled_rfid_new_id(rfid_serial_id);
        ultrasonico_tic = 5000; // Vuelvo a medir en 5 segundos.
    }

    //-----> Timer de ejemplo.
    if (!example_tic)
    {
        example_tic = 2000;

        digitalWrite(LED_PIN, HIGH);
        delay(250); // Evitar usarlos.
        digitalWrite(LED_PIN, LOW);

        //----> Reles
        static int x = 0;
        static int cont = 0;
        cont++;
        x++;
        if (x == 3)
        {
            x = 0;
            nextion_send("date.txt=\"" + String(cont) + "\"");
        }

        switch (x)
        {
        case 0:
            DEBUG("Case 0")
            digitalWrite(RELAY_1, HIGH);
            digitalWrite(RELAY_2, HIGH);
            digitalWrite(RELAY_3, LOW);
            break;

        case 1:
            DEBUG("Case 1")
            digitalWrite(RELAY_1, HIGH);
            digitalWrite(RELAY_2, LOW);
            digitalWrite(RELAY_3, HIGH);
            break;

        case 2:
            DEBUG("Case 2")
            digitalWrite(RELAY_1, LOW);
            digitalWrite(RELAY_2, HIGH);
            digitalWrite(RELAY_3, HIGH);
            break;

        default:
            break;
        }
    }
}