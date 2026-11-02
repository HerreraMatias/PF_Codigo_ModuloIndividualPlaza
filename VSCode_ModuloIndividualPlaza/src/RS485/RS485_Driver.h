
#ifndef RS485_DRIVER_H
#define RS485_DRIVER_H

void rs485_init();
void rs485_loop();
void rs485_send(String);

extern bool rs485_available;
extern String rs485_buffer;

#endif