/*****************************************************************************
*  \file      EEPROM_functions.cpp 
*  \brief     This file contains all the functions for EEPROM 
*  \details   Put eeprom_begin() in setup() for the correct operation.
*  \author    Matias Herrera                                                
*  \version   1.0                                                           
*  \date      2024
*  \copyright (c) 2024 Adox. All rights reserved.
******************************************************************************/


#include <Arduino.h>
#include <EEPROM.h>

#include "EEPROM_functions.h"
#include "../src/Debug_setup.h"

/**
 * Variables
 */
int dir_ssid = 0;
int dir_pass = 50;
int dir_datos_set = 100;
int dir_mqtt_topic_name = 200;
int dir_ip_puerto_local = 250;

/**
 * @brief Begin eeprom.
 */
void eeprom_begin()
{
  EEPROM.begin(512);
  DEBUG("[EEPROM]: begin")

  //-------> Lectura de variables:
  //tcp_first_index = (eeprom_read(dir_tcp_first_index)).toInt();
  DEBUG("[EEPROM]: tcp_first_index: " + String())

  //tcp_last_index = (eeprom_read(dir_tcp_last_index)).toInt();
  DEBUG("[EEPROM]: tcp_last_index: " + String())

  //tcp_reset_counter = (eeprom_read(dir_tcp_reset_counter)).toInt();
  DEBUG("[EEPROM]: tcp_reset_counter: " + String())

  //datos_set = (eeprom_read(dir_datos_set));
  DEBUG("[EEPROM]: datos_set: " + String())
}

/**
 * @brief Write data to eeprom.
 * @param addr memory address
 * @param data data to write
 * @return none
 */
void eeprom_write(int addr, String data)
{
  if (addr != -1)
  {
    int tamano = data.length();
    char inchar[50];
    data.toCharArray(inchar, tamano + 1);
    for (int i = 0; i < tamano; i++)
    {
      EEPROM.write(addr + i, inchar[i]);
    }
    for (int i = tamano; i < 50; i++)
    {
      EEPROM.write(addr + i, 255);
    }
    EEPROM.commit();
  }
  else
  {
    Serial.print("\n[EEPROM]: wrong address");
  }
}

/**
 * @brief Read data from eeprom.
 * @param addr memory address
 * @return read string
 */
String eeprom_read(int addr)
{
  byte lectura;
  String strlectura;
  for (int i = addr; i < addr + 50; i++)
  {
    lectura = EEPROM.read(i);
    if (lectura != 255)
    {
      strlectura += (char)lectura;
    }
  }
  return strlectura;
}
