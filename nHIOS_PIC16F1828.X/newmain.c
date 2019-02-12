//#include <xc.h>
#include "hall_adc.h"
#include "delay.h"
#include "hall_int.h"
#include "led.h"
#include "drv8306.h"
#include "key.h"
#include "output_sig.h"
#asm RESET
#endasm
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
    uint i=0,j,z;
    uchar mykey=0;
    init_fosc();
    Led_Init();
    Key_Init();
    Brake_OutPut_SIG_Init();
    Drv8306_Init();
    HALL_Init();
    Drv8306_PWM();
    while(1)
    {
       mykey =GetKeyPad();
       if(flag_power_on == 1)
       {
            //mykey =GetKeyPad();
           LED1=0;
           LED2=0;
           LED3=0;
            mykey =0;
            PORTC = 0x01;
            TRISCbits.TRISC5 =1;
             j=2;
             while(1);
        }
       if(flag_power_on == 0)
        {
            PORTC = 0x01;
            TRISCbits.TRISC5 =1;
            mykey =GetKeyPad();
            if(j==2)
             {
                 LED1=~LED1;
                 if(z==1)
                     PORTBbits.RB5=0;
                 else
                     PORTBbits.RB5=1;
                 delay_1ms(20);
                 mykey=2;// new add item
             }
           
           }

       switch(mykey)
        {
            case 0 : //stop
            {
               PORTC = 0x01;
               TRISCbits.TRISC5 =1;
               LED3=1;
                delay_1ms(50);
                
            }
            break;

            case 1:
            {
                LED2=1;
                TRISCbits.TRISC5 =0;
                 PORTC = 0xc1;
                 while(flag_power_on==0 && mykey==1);
            }
            break;

            case 2:
            {
                GetKeyPad();
                PORTC = 0x01;
                TRISCbits.TRISC5 =1;
                LED2=~LED2;
                delay_1ms(50);
                if(GetKeyPad() == 1)
                {
                    if(z==1)
                    {
                        z=0;
                        j=3;
                       PORTBbits.RB5=0;
                    }
                 }
                if(GetKeyPad()==0)
                {
                    z = 1;
                  LED3=~LED3;
                  PORTBbits.RB5=0;
                  delay_1ms(100);
                }
               
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
 * Input Reference :Noting
 * Return Reference :Noting
 *
******************************************************/

void interrupt Hallsensor(void)
{
   //if(INTF == 1)//if( IOCAF0 == 1)//if(IOCIF == 1)
// if(INTF == 1)
  if(IOCAF2 == 1)
    {
      IOCIF =0;
      IOCAF2=0;//INTF =0;
      flag_brake =1;
      flag_power_on =1;
      PORTC = 0x01;
      LED3=1;
    //  PORTBbits.RB5=1;
      delay_10ms(10);

     }
    if(IOCAF0 ==1)
    {
        IOCIF =0;
        IOCAF0 =0;
        PORTC = 0x01;
        delay_1ms(20);
    }
 }

  

   
 



