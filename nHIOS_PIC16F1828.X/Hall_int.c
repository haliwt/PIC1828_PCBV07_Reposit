#include "hall_int.h"

/***********************************
 * 
 * Hall_INTInit()
 * 
**********************************/

void HALL_Init()
{
    TRISAbits.TRISA2 = 1 ;  //RA0 = 1 input
    ANSA2 = 0;  //0 = digital I/O; 1 = analog input
    INLVLA2 = 1;  // 1 =ST input 0 =TTL inpu
    IOCAP2 = 1;  //Flag IOCAF0
    IOCAN2 = 1;
    IOCIE =1;  //interrupt on change enable bit
   // IOCAN = 0b00000100;
   // IOCAP = 0b00000100;
    PEIE =1;   //peripheral interrupt enable
    GIE = 1;  // open all interrupt

   
}
#if 0
void HALL_Init()
{

    TRISAbits.TRISA2 = 1 ;  //RA2 = 1 input interrupter
    ANSA2 = 0;  //0 = digital I/O; 1 = analog input
    INLVLA0 = 1;  // 1 =ST input 0 =TTL input
    INTF = 0; //
    INTE = 1;  //external interrupt enable bit
    PEIE =0;   //peripheral interrupt enable
    INTEDG = 0;  // 1=rising edge interrupt
    GIE = 1;  // open all interrupt
}
#endif