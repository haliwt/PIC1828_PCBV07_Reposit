//#include <xc.h>
#include "hall_adc.h"
#include "delay.h"
#include "hall_int.h"
#include "led.h"
#include "drv8306.h"
#include "key.h"
 uchar flagbrake ;


/**************************************************************
 *
 *Function :main()
 * input regerence :noting
 *
 *************************************************************/
void  main(void )
{
   // uint i;
    uchar mykey=0;
    init_fosc();
    Led_Init();
    Key_Init();
    Drv8306_Init();
    HALL_Init();
    Drv8306_PWM();
    while(1)
    {
        while(HALL_SENSOR == 0)
        {
            LED1 =1;
            LED2=1;
            LED3=1;
        
        }
        mykey =GetKeyPad();
         if(my_drv.drv_dir ==1)
           {

            LED1=1;
            delay_10ms(100);
           }
       if( flagbrake == 1)// if( my_drv.drv_brake == 1)
        {
           //my_drv.drv_brake=0;
           LED3=1;
           DRV_BRAKE = 0 ;
           delay_10ms(100);
           LED3= 0;
           delay_10ms(100);
           LED3 = !LED3;
        }

      if( GetKeyPad()==1) //scredirver works,
       {
          LED2 =1;
        if((DRV_BRAKE==0) ||(flagbrake != 0))
         {
          DRV_ENABLE =1 ;
          DRV_BRAKE = 1;
          delay_10ms(10);
          my_drv.drv_brake=0;
           LED1=1;
           delay_10ms(100);
           LED3=1;
           delay_10ms(100);
           LED1=0;
          // DRV_BRAKE = 0 ;
           delay_10ms(100);
           LED3=0;
           delay_10ms(100);
          
          }
      }
#if 0
        {
         else if(my_drv.drv_dir ==1)
           {
            DRV_DIR=1;
            DRV_ENABLE =1;
            DRV_BRAKE = 1 ;
            LED3=1;
            delay_10ms(100);
           }
         else if(my_drv.drv_dir ==0)
           {
               DRV_DIR=0;
               DRV_ENABLE =1;
               DRV_BRAKE = 1 ;
               LED2=1;
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
void interrupt Hallsensor(void)
{
   //if(INTF == 1)//if( IOCAF0 == 1)//if(IOCIF == 1)
  if(INTF == 1)
   {
      //INTF =0;
     // PORTCbits.RC6=1;//DRV_BRAKE = 0 ;
       if(HALL_SENSOR == 0)
       {
           INTF=0;
           my_drv.drv_brake =1;
           flagbrake=1;
           LED3=1;
           LATC6 =0;//PORTCbits.RC6=1;//DRV_BRAKE = 0 ;
           
         
       }
     }
 

}