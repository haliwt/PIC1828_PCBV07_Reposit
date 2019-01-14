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
    uint i;
    init_fosc();
    Led_Init();
    Drv8306_FAULT();
    Drv8306_Init();
    HALL_INTInit();
    Drv8306_PWM();

  
    while(1)
    {
        //PORTC = 0xce;//start screwdriver
        delay_10ms(1000);
        LED1 =0;
       // LED2=0;
      //  LED3=0;
        delay_10ms(1000);
        LED1 =1;
       // LED2=1;
       // LED3=1;
#if 0
        if(HALL_SENSOR == 0)
        {
            my_drv.drv_brake=0;
           LED3 =1 ;
            for(i=0;i<2;i++)
            delay_10ms(100);
        }
#endif
        if( my_drv.drv_brake ==1)
        {
           my_drv.drv_brake=0;
           for(i=0;i<10;i++)
           {
               LED2 =1 ;
               LED3 = 0;
               delay_10ms(1000);
                LED2 =0 ;
                LED3 = 1;
                delay_10ms(1000);
           }
        }
   

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
    uint i;
    if( IOCAF0 == 1)
    {
        my_drv.drv_brake =1;
        IOCAF0 =0 ;
        IOCIE =0;
        LED1 =0;
        LED2 =0 ;
        LED3 =0;
       // for(i=0;i<10;i++)
      //  delay_10ms(1000);

       
    }

}

