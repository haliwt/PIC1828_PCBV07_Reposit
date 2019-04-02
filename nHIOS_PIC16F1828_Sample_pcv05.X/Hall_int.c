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
    IOCAP2 = 1;  //Flag IOCAF0  //WT.EDIT 2019-02-20
    IOCAN2 =1; //negative edge enable
    IOCIE =1;  //interrupt on change enable bit
    PEIE =1;   //peripheral interrupt enable
    GIE = 1;  // open all interrupt
}

