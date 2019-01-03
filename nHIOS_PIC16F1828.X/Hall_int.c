#include "hall_int.h"

/***********************************
 * 
 * Hall_INTInit()
 * 
**********************************/
void HALL_INTInit()
{
    TRISA = 0X02 ;  //RA2 = 1 input
    PORTA = 0x00; //GPIO set up
    PEIE =1;   //peripheral interrupt enable
    GIE = 1;  // open all interrupt
    INTEDG = 1;  // rising edge interrupt

}
