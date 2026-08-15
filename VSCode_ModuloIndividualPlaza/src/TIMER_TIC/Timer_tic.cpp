/*****************************************************************************
*  \file      Timer_tic.cpp
*  \brief     This file allows the use timers from the Ticker.h library.
*  \details   To be able to use it, include it, 
*             and put Ticker_begin() in the setup() (main.cpp).       
*  \author    Matias Herrera                                                
*  \version   1.0                                                           
*  \date      2024
*  \copyright (c) 2024 Adox. All rights reserved.
******************************************************************************/

#include <Ticker.h>
#include "Timer_tic.h"

Ticker timer_1ms;

int encoder_button_tic = 0;
int sensor_tic = 0;
int test_tic = 0;
int oled_display_tic = 0;
int wifi_tcp_tic = 0;
int mqtt_tic = 0;
int ultrasonico_tic = 0;
int example_tic = 0;

void Timer_1ms()
{
    if (example_tic > 0)
        example_tic--;
    if (ultrasonico_tic > 0)
        ultrasonico_tic--;
    if (encoder_button_tic > 0)
        encoder_button_tic--;
    if (sensor_tic > 0)
        sensor_tic--;
    if (test_tic > 0)
        test_tic--;
    if (oled_display_tic > 0)
        oled_display_tic--;
    if (wifi_tcp_tic > 0)
        wifi_tcp_tic--;
    if (mqtt_tic > 0)
        mqtt_tic--;
}

void Ticker_begin()
{
    timer_1ms.attach_ms(1, Timer_1ms);
}