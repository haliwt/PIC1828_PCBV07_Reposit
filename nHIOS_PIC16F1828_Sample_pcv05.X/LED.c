#include "LED.h"

/*********************************
 *
 * Function Name:
 * Function Active:LED initial fuction
 * Input Reference: no
 * Output Reference:no
 *
********************************/
void Led_Init(void)
{
  //  TRISCbits.TRISC1 = 0;
   // TRISCbits.TRISC2= 0;
    TRISCbits.TRISC3 = 0;
   // LED1=0;
    //LED2=0;
    LED3=0;
}
