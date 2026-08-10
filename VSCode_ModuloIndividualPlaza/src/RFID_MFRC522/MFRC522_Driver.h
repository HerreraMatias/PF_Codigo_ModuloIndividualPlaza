#include <Arduino.h>

#ifndef MFRC522_FUNCTIONS_H
#define MFRC522_FUNCTIONS_H

extern String respuestaPost2;
extern String remoteIP;
extern String remotePort;
//--------------------------------
extern bool flag_new_rfid;
extern long check_reader;
extern String rfid_serial;

void MFRC522_connect();
void SetDatosEnvio_RFID(String, String);
void MFRC522_begin();
void MFRC522_loop();

#endif