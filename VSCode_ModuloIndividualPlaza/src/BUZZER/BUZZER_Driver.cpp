
#include <Arduino.h>
#include "BUZZER_Driver.h"
#include "../ESP32_PinsConfig.h"

void buzzer_init()
{
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN,LOW);
}

void buzzer_on()
{
    digitalWrite(BUZZER_PIN,HIGH);
}

void buzzer_off()
 {
     digitalWrite(BUZZER_PIN,LOW);
 }
