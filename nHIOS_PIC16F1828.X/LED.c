#include "led.h"


void Led_Init()
{
    TRISCbits.TRISC1 = 0;
    TRISCbits.TRISC2= 0;
    TRISCbits.TRISC3 = 0;
    LED1=0;
    LED2=0;
    LED3=0;
}
