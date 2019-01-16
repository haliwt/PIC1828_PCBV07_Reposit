//#include <xc.h>
#include "hall_adc.h"
#include "delay.h"
#include "hall_int.h"
#include "led.h"
#include "drv8306.h"
#include "key.h"
uchar flag_brake = 0;

/**************************************************************
 *
 *Function :main()
 * input regerence :noting
 *
 *************************************************************/
void  main(void )
{
   // uint i;
    init_fosc();
    Led_Init();
    Key_Init();
    Drv8306_Init();
    HALL_Init();
    Drv8306_PWM();
    while(1)
    {
       if( my_drv.drv_brake == 1)
        {
           //my_drv.drv_brake=0;
           LED3=1;
           DRV_BRAKE = 0 ;
           delay_10ms(100);
           LED3= 0;
           delay_10ms(100);
           LED3 = !LED3;
        }
#if 1
      if(GetKeyPad() ==1) //scredirver works,
       {
         if( my_drv.drv_brake ==1)
         {
           my_drv.drv_brake=0;
           LED3=2;
           DRV_BRAKE = 0 ;
           delay_10ms(100);
          }
          if(my_drv.drv_dir ==1)
           {
            DRV_DIR=1;
            DRV_ENABLE =1;
            DRV_BRAKE = 1 ;
            LED3=1;
            delay_10ms(100);
           }
           if(my_drv.drv_dir ==0)
           {
               DRV_DIR=0;
               DRV_ENABLE =1;
               DRV_BRAKE = 1 ;
               LED1=1;
               delay_10ms(100);
               LED2=1;
                delay_10ms(100);
               LED3=1;
                delay_10ms(100);
           }
          Manual_Operation_Dir();
        }
#endif
     
    }
 }
   

/**************************************************************
 *
 * Function function: interrupt program hall
 *
 *
 *************************************************************/
void interrupt ISR(void)
{
   //if(INTF == 1)//if( IOCAF0 == 1)//if(IOCIF == 1)
   if(INTF == 1)
   {
       INTF =0;
       if(HALL_SENSOR == 0)
       {
        my_drv.drv_brake =1;
        flag_brake=1;
         LED1=1;
         //PORTCbits.RC6=0;//DRV_BRAKE = 0 ;
         delay_10ms(10);
       }
     }
 

}