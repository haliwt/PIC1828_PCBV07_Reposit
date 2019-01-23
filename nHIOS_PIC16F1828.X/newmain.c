//#include <xc.h>
#include "hall_adc.h"
#include "delay.h"
#include "hall_int.h"
#include "led.h"
#include "drv8306.h"
#include "key.h"



volatile uchar flag_brake=0 ;
extern uchar flag_power_on=0;

/**************************************************************
 *
 *Function :main()
 * input regerence :noting
 *
 *************************************************************/
void  main(void )
{
    uint i=0,j;
    uchar mykey=0;
    init_fosc();
    Led_Init();
    Key_Init();
    Drv8306_Init();
    HALL_Init();
    Drv8306_PWM();
    while(1)
    {
        //mykey =GetKeyPad();
        if(flag_power_on == 1)
        {
            //mykey =GetKeyPad();
            mykey =0;
            PORTC = 0x01;
            TRISCbits.TRISC5 =1;
             Key_Access = 0;
             j=2;
             while(1);
        }
        if(flag_power_on == 0)
        {
          
            pwm_duty=0x02;
            Key_Access = 1;
             mykey =GetKeyPad();
             if(j==2)
             {
                 LED1=1;
                 LED2=1;
                 LED3=1;
                 while(1);
             }
          
        }
        switch(mykey)
        {
            case 0 :
            {
               PORTC = 0x01;
               TRISCbits.TRISC5 =1;
                LED1=1;
                 pwm_duty=0;
                if(flag_brake ==1)
                {
                    j=2;
                    mykey=0;
                    Key_Access = 0;
                      while(1);
                   LED2=1;
                   LED1=1;
                    pwm_duty=0;
                   delay_10ms(10);
                   while(1);
                }
                else
                {
                    Key_Access = 1;
                     delay_10ms(10);
                }
              }
            break;

            case 1:
             {
                   // pwm_duty=0x02;
                     LED2=1;
                     TRISCbits.TRISC5 =0;
                    PORTC = 0xc1;
                  //  while(mykey==1);
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
 *****




 ******************************************************/

void interrupt Hallsensor(void)
{
   //if(INTF == 1)//if( IOCAF0 == 1)//if(IOCIF == 1)
// if(INTF == 1)
    uint i;
  if(IOCAF2 == 1)
    {
     
      IOCIF =0;
     IOCAF2=0;//INTF =0;
         // IOCBF4=0;
        //  INTF=0;
           flag_brake =1;
          flag_power_on =1;
          PORTC = 0x01;
          TRISCbits.TRISC5 =1;
          PORTBbits.RB4 =0;
           pwm_duty=0;
           LED3=1;
           delay_10ms(10);
         }
 }

  

   
 



