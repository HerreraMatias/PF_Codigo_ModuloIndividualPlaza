/*****************************************************************************
*  \file      Debug_setup.h 
*  \brief     Serial debug definitions. 
*  \details   This file enables debugging of the program on the serial port and on the web server.
*             If DEBUG_ENABLE is commented out, debugging is disabled.
*             If DEBUG_STM32_ENABLE is disabled, the hardware serial port is
*             allowed to be used to program STM32 microcontrollers.
*  \author    Matias Herrera                                                
*  \version   1.0                                                           
*  \date      2024
*  \copyright (c) 2024 Adox. All rights reserved.
******************************************************************************/


#include <Arduino.h>

#define DEBUG_ENABLE // Comment this line to disable serial debug.
#ifdef DEBUG_ENABLE
/** Begin serial debug. */
#define DEBUG_BEGIN Serial.begin(9600);
/** Print on serial port. */
#define DEBUG(x) {Serial.println(x);} 
#define DEBUG_(x) {Serial.print(x);}
#else
#define DEBUG(x)
#define DEBUG_(x)
#define DEBUG_BEGIN
#endif
