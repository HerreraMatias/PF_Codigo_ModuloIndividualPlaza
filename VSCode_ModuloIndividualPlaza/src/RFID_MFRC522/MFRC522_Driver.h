#include <Arduino.h>

#ifndef MFRC522_FUNCTIONS_H
#define MFRC522_FUNCTIONS_H

extern bool rfid_new_id;
extern String rfid_serial_id;

void MFRC522_init();
void MFRC522_loop();

#endif