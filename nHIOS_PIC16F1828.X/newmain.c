//#include <xc.h>
#include "hall_adc.h"
#include "delay.h"
#include "hall_int.h"
#include "led.h"
#include "drv8306.h"


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
    HALL_Init();
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

       if( my_drv.drv_brake ==1)
       {
         my_drv.drv_brake=0;
        // if(HALL_SENSOR == 0)
         { 
             for(i=0;i<1;i++)
             {
                   LED2 =1 ;
                   LED3=1;
                   delay_10ms(100);
                   LED3=0;
                   LED2 = 0;
                    delay_10ms(100);
                  
             }
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
   if(INTF == 1)//if( IOCAF0 == 1)//if(IOCIF == 1)
    {
        my_drv.drv_brake =1;
        INTF =0;
       }

}

