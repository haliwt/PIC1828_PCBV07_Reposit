/* 
 * File:   newmain.c
 * Author: Administrator
 *
 * Created on December 25, 2018, 8:45 AM
 */
//#include <xc.h>
#include "hall_adc.h"
#include "delay.h"
#include "hall_int.h"
#include "led.h"
#include "drv8306.h"
uchar HALL_INT_Flag = 0;
/**************************************************************
 * 
 *************************************************************/
void  main(void )
{
    init_fosc();
    Led_Init();
  //  Drv8306_Init();
 //   HALL_INTInit();
    while(1)
    {
        PORTC = 0x0;//
        delay_10ms(20);
        PORTC = 0x0f;
         delay_10ms(20);

    }

 }

/**************************************************************
 *
 * Function function: interrupt program hall
 *
 *
 *************************************************************/
void interrupt hall_int()
{
    if(RA2 == 1)
        HALL_INT_Flag =1;

}

