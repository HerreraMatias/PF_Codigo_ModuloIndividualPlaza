#include <Arduino.h>
#include "HCSR04_Driver.h"
#include "../ESP32_PinsConfig.h"
#include "../Debug_setup.h"
#include "../TIMER_TIC/Timer_tic.h"
#include "../OLED_DISPLAY/oled_display.h"

float medirDistancia();

void ultrasonico_init()
{
    pinMode(ULTRASONIC_TRIG, OUTPUT);
    pinMode(ULTRASONIC_ECHO, INPUT);

    // TRIG debe comenzar en LOW
    digitalWrite(ULTRASONIC_TRIG, LOW);

    delay(500);

    DEBUG("HC-SR04 iniciado");
}

void ultrasonico_loop()
{
    if (!ultrasonico_tic)
    {
        ultrasonico_tic = 3000;
        float distancia = medirDistancia();

        if (distancia < 0)
        {
            DEBUG("Sin respuesta del HC-SR04");
        }
        else
        {
            DEBUG_("Distancia: ");
            DEBUG_(distancia);
            DEBUG(" cm");
        }
    }
}

float medirDistancia()
{
    // Aseguramos TRIG en LOW
    digitalWrite(ULTRASONIC_TRIG, LOW);
    delayMicroseconds(2);

    // Pulso de disparo de 10 us
    digitalWrite(ULTRASONIC_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRASONIC_TRIG, LOW);

    // Medimos duración del pulso ECHO.
    // Timeout = 30 ms para evitar que el programa quede bloqueado.
    unsigned long duracion =
        pulseIn(ULTRASONIC_ECHO, HIGH, 30000);

    // Timeout
    if (duracion == 0)
    {
        return -1;
    }

    // Velocidad del sonido ≈ 0.0343 cm/us
    // Se divide por 2 porque el sonido va y vuelve.
    float distancia = (duracion * 0.0343) / 2.0;

    return distancia;
}