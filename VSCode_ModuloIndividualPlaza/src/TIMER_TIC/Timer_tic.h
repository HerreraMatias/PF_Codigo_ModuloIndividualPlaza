/*****************************************************************************
*  \file      Timer_tic.h
*  \brief     This file allows the use timers from the Ticker.h library.
*  \details   To be able to use it, include it, 
*             and put Ticker_begin() in the setup() (main.cpp).       
*  \author    Matias Herrera                                                
*  \version   1.0                                                           
*  \date      2024
*  \copyright (c) 2024 Adox. All rights reserved.
******************************************************************************/


#ifndef TICKER_FUNCTIONS_H
#define TICKER_FUNCTIONS_H

extern int encoder_button_tic;
extern int sensor_tic;
extern int test_tic;
extern int oled_display_tic;
extern int wifi_tcp_tic;
extern int mqtt_tic;

void Timer_1ms();
void Ticker_begin();

#endif