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
    uint i;
    uchar mykey=0;
    init_fosc();
    Led_Init();
    Key_Init();
    Drv8306_Init();
    HALL_Init();
    Drv8306_PWM();
    while(1)
    {
        if(GetKeyPad() == 1)
        {
           if ( flag_brake == 1)
            {
                LED1=1;
                delay_10ms(10);
                TRISC =0xc0;// TRISCbits.TRISC7 = 0;
                //TRISCbits.TRISC6 = 0;
                PORTC = 0x00;
            }
            if( flag_power_on ==0)
            {
                flag_power_on++;
                LED2=1;
                TRISC =0x0;// TRISCbits.TRISC7 = 0;
                //TRISCbits.TRISC6 = 0;
                PORTC = 0xc0;
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

void interrupt Hallsensor(void)
{
   //if(INTF == 1)//if( IOCAF0 == 1)//if(IOCIF == 1)
  //if(INTF == 1)
  if( IOCAF2 == 1)
    {
      IOCAF2=0;//INTF =0;
         my_drv.drv_brake =1;
           flag_brake=1;
           flag_power_on =1;
           TRISC= 0xc0;
             delay_10ms(100);
           PORTC = 0x00;
           delay_10ms(100);
            LED3=1;
            delay_10ms(10);
           while(1);
       
       }
   }
 



