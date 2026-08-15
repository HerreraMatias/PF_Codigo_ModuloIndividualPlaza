/*****************************************************************************
*  \file      EEPROM_functions.h 
*  \brief     This file contains all the functions for EEPROM 
*  \details   Put eeprom_begin() in setup() for the correct operation.
*  \author    Matias Herrera                                                
*  \version   1.0                                                           
*  \date      2024
*  \copyright (c) 2024 Adox. All rights reserved.
******************************************************************************/

#ifndef Eeprom_library
#define Eeprom_library

#include "Arduino.h"
#include "EEPROM.h"

/**
 * Variables
 */
extern int dir_datos_set;
extern int dir_mqtt_topic_name;
extern int dir_ssid;
extern int dir_pass;
extern int dir_ip_puerto_local;

/**
 * @brief Begin eeprom.
 */
void eeprom_begin();

/**
 * @brief Write data to eeprom.
 * @param addr memory address
 * @param data data to write
 * @return none
 */
void eeprom_write(int, String);

/**
 * @brief Read data from eeprom.
 * @param addr memory address
 * @return read string
 */
String eeprom_read(int);

#endif