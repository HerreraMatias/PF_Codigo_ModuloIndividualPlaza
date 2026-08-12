#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

// VSPI
#define RFID_SCK   18
#define RFID_MISO  19
#define RFID_MOSI  23

// MFRC522
#define RFID_SS    32
#define RFID_RST   27

MFRC522 reader(RFID_SS, RFID_RST);

void rc522_test()
{
    Serial.println();
    Serial.println("=======================");
    Serial.println(" TEST MFRC522 - VSPI");
    Serial.println("=======================");

    // Inicializar VSPI
    SPI.begin(
        RFID_SCK,
        RFID_MISO,
        RFID_MOSI,
        RFID_SS
    );

    delay(100);

    // Inicializar MFRC522
    reader.PCD_Init();

    delay(100);

    // Leer versión
    byte version = reader.PCD_ReadRegister(MFRC522::VersionReg);

    Serial.print("VersionReg = 0x");

    if (version < 0x10)
        Serial.print("0");

    Serial.println(version, HEX);

    // Diagnóstico
    if (version == 0x91)
    {
        Serial.println("OK - MFRC522 v1.0 detectado");
    }
    else if (version == 0x92)
    {
        Serial.println("OK - MFRC522 v2.0 detectado");
    }
    else if (version == 0x88)
    {
        Serial.println("OK - Probable clon MFRC522");
    }
    else if (version == 0xFF)
    {
        Serial.println("ERROR - No hay respuesta del MFRC522 (MISO HIGH)");
    }
    else if (version == 0x00)
    {
        Serial.println("ERROR - No hay respuesta del MFRC522 (MISO LOW)");
    }
    else
    {
        Serial.println("Respuesta desconocida");
    }

    Serial.println();

    // Información adicional de la propia librería
    reader.PCD_DumpVersionToSerial();
}
