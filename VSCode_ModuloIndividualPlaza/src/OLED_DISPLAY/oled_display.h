/*****************************************************************************
*  \file      oled_display.h 
*  \brief     This file contains the functions for oled display SSD1306.
*  \author    Matias Herrera                                                
*  \version   1.0                                                           
*  \date      2024
*  \copyright (c) 2024 Adox. All rights reserved.
******************************************************************************/

#ifndef OLED_LIBRARY_H
#define OLED_LIBRARY_H

#include <Arduino.h>


/**
 * @brief Funcion para inicializar la pantalla oled
 */
void oled_init();

/**
 * @brief Funcion para mostrar el estado de la red wifi.
 */
void oled_wifi();

/**
 * @brief Funcion para mostrar el estado de memoria,rtc,etc.
 */
void oled_status();

/**
 * @brief Funcion para mostrar nombre del dispositivo.
 */
void oled_init_display();

/**
 * @brief Funcion para mostrar la presion.
 */
void oled_pressure();

/**
 * @brief Funcion para mostrar la temperatura y humedad.
 */
void oled_AM2301();

/**
 * @brief Funcion para mostrar los indices del tcp.
 */
void oled_tcp_indexes();

/**
 * @brief Funcion para mostrar el estado de envios de datos por tcp.
 */
void oled_tcp_states();

void oled_wifi_mode_AP(String, String);

void oled_receptor(String data_received);
void oled_transmisor(String data_sent);

#endif
