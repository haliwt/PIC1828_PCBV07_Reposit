#include "Hall_int.h"

/*******************************************
 * 
 * Hall_INTInit()
 * 
*******************************************/
void HALL_Init(void)
{
    TRISAbits.TRISA2 = 1 ;  //RA0 = 1 input
    ANSA2 = 0;  //0 = digital I/O; 1 = analog input
    IOCAP2 = 0;  //Flag IOCAF0  //WT.EDIT 2019-02-20
    IOCAN2 =0; //negative edge enable
    IOCIE =0;  //interrupt on change enable bit
    IOCIF = 0;
    PEIE =0;   //peripheral interrupt enable
    GIE = 0;  // open all interrupt
}

