#include "hall_int.h"

/***********************************
 * 
 * Hall_INTInit()
 * 
**********************************/
#if 0
void HALL_Init()
{

    TRISAbits.TRISA0 = 1 ;  //RA0 = 1 input
    ANSA0 = 0;  //0 = digital I/O; 1 = analog input
   // PORTAbits.RA0 =1;
    INLVLA0 = 0;  // 1 =ST input 0 =TTL input
    IOCAP = 0x01;  // IOCAP : <ic0an0>
    IOCAF0 = 0x00;  //Flag IOCAF0
    //HALL_SENSOR = 0;
    //INTE =1 ;  //external interrupt enable bit
    IOCIE =1;  //interrupt on change enable bit
   // IOCAN = 0b00001011;
   // IOCAP = 0b00001011;
   // IOCAF = 0x00;
    PEIE =1;   //peripheral interrupt enable
  //  GIE = 1;  // open all interrupt
    INTEDG = 1;  // rising edge interrupt
  //  IOCIE =1 ;  //interrupt-on-change enable
   // IOCIF =0;
    GIE = 1;  // open all interrupt

   
}
#endif
void HALL_Init()
{

    TRISAbits.TRISA2 = 1 ;  //RA2 = 1 input interrupter
    ANSA2 = 0;  //0 = digital I/O; 1 = analog input
    HALL_SENSOR = 1;
    IOCIE =1;
    INLVLA0 = 1;  // 1 =ST input 0 =TTL input
    INTF = 0; //
    INTE = 1;  //external interrupt enable bit
    PEIE =1;   //peripheral interrupt enable
    INTEDG = 0;  // 1=rising edge interrupt
    GIE = 1;  // open all interrupt


}