#include <Arduino.h>

#include "MFRC522_Driver.h"
#include "../Debug_setup.h"
#include "../ESP32_PinsConfig.h"
#include <SPI.h>
#include <MFRC522.h>

MFRC522 reader(RFID_SS, RFID_RST);

bool rfid_new_id;
String rfid_serial_id;


void MFRC522_init()
{
    DEBUG("MFRC522 init")
    SPI.begin(RFID_SCK, RFID_MISO, RFID_MOSI, RFID_SS);

    reader.PCD_Init();
    delay(100);

    reader.PCD_AntennaOff();
    delay(50);
    reader.PCD_AntennaOn();
    reader.PCD_SetAntennaGain(MFRC522::RxGain_max);

    byte version = reader.PCD_ReadRegister(MFRC522::VersionReg);

    DEBUG_("VersionReg = 0x");
    if (version < 0x10)
        DEBUG_("0");
    DEBUG(String(version, HEX));

    switch (version)
    {
    case 0x91:
        DEBUG("RC522 detectado correctamente (v1.0)");
        break;

    case 0x92:
        DEBUG("RC522 detectado correctamente (v2.0)");
        break;

    case 0x88:
        DEBUG("RC522 compatible (clon detectado)");
        break;

    case 0x00:
        DEBUG("ERROR: No responde (MISO en LOW)");
      
        break;

    case 0xFF:
        DEBUG("ERROR: No responde (MISO en HIGH)");
       
        break;

    default:
        DEBUG("ERROR: Version desconocida");
        
    }

    reader.PCD_DumpVersionToSerial();

}

void MFRC522_loop()
{
    if (!reader.PICC_IsNewCardPresent())
        return;


    if (!reader.PICC_ReadCardSerial())
    {
        DEBUG("ERROR: Se detectó una tarjeta pero no se pudo leer el UID.");
        return;
    }

    DEBUG_("UID: ");

    rfid_serial_id = "";

    for (byte i = 0; i < reader.uid.size; i++)
    {
        if (reader.uid.uidByte[i] < 0x10)
            rfid_serial_id += "0";

        rfid_serial_id += String(reader.uid.uidByte[i], HEX);

        if (i < reader.uid.size - 1)
            rfid_serial_id += "-";
    }

    rfid_serial_id.toUpperCase();

    rfid_new_id = true; //---> Activo flag de nueva rfid.

    DEBUG(rfid_serial_id);

    DEBUG_("Tipo: ");
    DEBUG(reader.PICC_GetTypeName(reader.PICC_GetType(reader.uid.sak)));

    reader.PICC_HaltA();
    reader.PCD_StopCrypto1();
}
