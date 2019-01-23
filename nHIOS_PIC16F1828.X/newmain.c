//#include <xc.h>
#include "hall_adc.h"
#include "delay.h"
#include "hall_int.h"
#include "led.h"
#include "drv8306.h"
#include "key.h"
volatile uchar flag_brake=0 ;
extern uchar flag_power_on;

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
        mykey =GetKeyPad();
        switch(mykey)
        {
            case 0 :
            {
               PORTC = 0x01;
               TRISCbits.TRISC5 =1;
                LED1=1;
                
              }
            break;

            case 1:
             {
                   // pwm_duty=0x02;
                     LED2=1;
                   // CCPR1L = pwm_duty;
                    TRISCbits.TRISC5 =0;
                    PORTC = 0xc1;
                    while(GetKeyPad());
               }
            break;
            default :
            {
              PORTC = 0x01;
              TRISCbits.TRISC5 =1;
             }
            break;
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
// if(INTF == 1)
#if 0
  if( IOCAF2  == 1)
    {
        IOCIF =0;
      IOCAF2=0;//INTF =0;
         // IOCBF4=0;
        //  INTF=0;
          PORTC = 0x01;
          flag_power_on =1;
          pwm_duty =0x00;
          CCPR1L = pwm_duty;    //LSB:Low 2 bit 0x00 //pulse duty of
          LED3=1;
          delay_10ms(100);
      }
#endif 
  if(PORTBbits.RB4 ==0)
  {
       PORTC = 0x01;
          flag_power_on =1;
          pwm_duty =0x00;
          CCPR1L = pwm_duty;    //LSB:Low 2 bit 0x00 //pulse duty of
          LED3=1;
          while(1);

  }
  
  }
  

   
 



