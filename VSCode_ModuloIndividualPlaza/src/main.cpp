#include <Arduino.h>

#include "RFID_MFRC522/MFRC522_Driver.h"
#include "OLED_DISPLAY/oled_display.h"
#include "RS485/RS485_Driver.h"
#include "ULTRASONICO_HCSR04/HCSR04_Driver.h"
#include "MEMORIA_EEPROM/EEPROM_functions.h"
#include "TIMER_TIC/Timer_tic.h"

#include "Debug_setup.h"

void setup()
{
    //-----> Puerto serie para debug.
    DEBUG_BEGIN
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
    //-----> Pin LED.
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    /**************** LOOPING FUNCTIONS ****************/
    MFRC522_loop();     // Lectura de tarjetas RFID.
    ultrasonico_loop(); // Lectura de sensor ultrasonico.
    rs485_loop();       // Recepción de mensajes RS485.
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

        digitalWrite(LED_BUILTIN, HIGH);
        delay(250); //Evitar usarlos.
        digitalWrite(LED_BUILTIN, LOW);
    }
}