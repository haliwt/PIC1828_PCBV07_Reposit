#include "hall_int.h"

/***********************************
 * 
 * Hall_INTInit()
 * 
**********************************/
void HALL_INTInit()
{

    TRISAbits.TRISA0 = 1 ;  //RA0 = 1 input
    ANSA0 = 0;  //
   // PORTAbits.RA0 =1;
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
