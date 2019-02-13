#include "key.h"
#include "led.h"
#include "drv8306.h"
uchar flag_power_on;
/************************************************************
 *
 * Function Name:Key_Init(void)
 *
 *
 ************************************************************/
void Key_Init(void)
{
    TRISAbits.TRISA0 =1; //Key_start input
 //   TRISBbits.TRISB4 = 0 ; //Key_access
    ANSA0 = 0;
    IOCAP0 = 1;  //Flag IOCAF0
    IOCIE =1;  //interrupt on change enable bit

    PEIE =1;   //peripheral interrupt enable
    GIE = 1;  // open all interrupt
  
    Key_Dir = 0;
  //  Key_Access = 0;
    

 }
/************************************************************
 *
 * Function Name:uchar GetKeyPad(void)
 *
 *
 ************************************************************/
uchar GetKeyPad(void)
{
#if 1
  if(Key_Start == 1) 
   {
     // delay_1ms(10);
      delay_100us(1);
      if(Key_Start ==1)
       {
           return 1;
        }

    }
 if(Key_Start == 0)
  {
    //delay_1ms(10);
     delay_100us(1);
    if(Key_Start == 0)
    {
        return 0;
    }
   }
#endif
 }
 
/************************************************************
 *
 * Function Name:void Manual_Operation_Dir(void);
 *
 *
 ************************************************************/
void Manual_Operation_Dir(void)
{
   if(Key_Dir == 1)
    {
        delay_1ms(10);
        if(Key_Dir ==1)
        {
            LED2=1;
            my_drv.drv_dir=1;
           
        }
     }
}