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
    ANSA2 = 0;
    TRISAbits.TRISA1 =1 ; //key_dir input
    ANSA1 = 0;
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
  if(Key_Start == 1) 
   {
      delay_1ms(1);

      while(Key_Start ==1)
          return 1;

#if 0
      if(Key_Start ==1)
       {
           return 1;
         }
#endif
    }
  else
   {
     
       return 0;
     }
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