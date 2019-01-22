//#include <xc.h>
#include "hall_adc.h"
#include "delay.h"
#include "hall_int.h"
#include "led.h"
#include "drv8306.h"
#include "key.h"
volatile uchar flag_brake ;
volatile uchar flag_power_on;



/**************************************************************
 *
 *Function :main()
 * input regerence :noting
 *
 *************************************************************/
void  main(void )
{
    uint i=0;
    uchar mykey=0;
    init_fosc();
    Led_Init();
    Key_Init();
    Drv8306_Init();
    HALL_Init();
    Drv8306_PWM();
    while(1)
    {
        if(i==0)
        {
          GetKeyPad();
          i=2;
          
        }
        if(i ==1)
        {
          my_drv.key_press_start  == 0;
        }
        if(HALL_SENSOR==0)
        {
            i=1;
            TRISC =0xc0;
             PORTC = 0x00;
         }
       if((flag_brake ==1) || (my_drv.drv_brake == 1))
            my_drv.key_press_start = 0;
        if(my_drv.key_press_start  == 0)
        {

                   LED1=1;
                   i=1;
                   flag_brake =1;
                   my_drv.drv_brake=1;
                    TRISC =0xc0;
                    PORTC = 0x00;
                   
          }
         if(my_drv.key_press_start  == 1)
        {
       
             TRISCbits.TRISC5 =0;
             PORTC = 0xc0;
                
           }
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
  //if(INTF == 1)
  if( IOCIF == 1)
    {
          IOCAF=0;//INTF =0;
        //  if(HALL_SENSOR==0)
          {
             LED3=1;
          my_drv.drv_brake =1;
          my_drv.key_press_start=0;
           flag_brake=1;
           flag_power_on =1;
           TRISC=0xc0;
           PORTC= 0x00;
          
          }
      }
   }
 



