#include <Arduino.h>

#define ULTRASONIC_TRIG 25
#define ULTRASONIC_ECHO 26

float medirDistancia();

void ultrasonico_init()
{
    pinMode(ULTRASONIC_TRIG, OUTPUT);
    pinMode(ULTRASONIC_ECHO, INPUT);

    // TRIG debe comenzar en LOW
    digitalWrite(ULTRASONIC_TRIG, LOW);

    delay(500);

    Serial.println("HC-SR04 iniciado");
}

void ultrasonico_loop()
{
    float distancia = medirDistancia();

    if (distancia < 0)
    {
        Serial.println("Sin respuesta del HC-SR04");
    }
    else
    {
        Serial.print("Distancia: ");
        Serial.print(distancia, 1);
        Serial.println(" cm");
    }

    delay(1500);
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