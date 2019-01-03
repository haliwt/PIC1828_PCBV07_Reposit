#include "led.h"


void Led_Init()
{
    TRISC = 0Xf0;
    PORTC = 0X00;
    LED1 = 1;
    LED2 = 1;
    LED3 = 1;
}
