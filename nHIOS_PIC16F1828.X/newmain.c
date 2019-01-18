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

         

        mykey =GetKeyPad();
      while(HALL_SENSOR == 0)
      {
           PORTC = 0x0;
           delay_10ms(50);
            LED1 =1;
            LED2=1;
            LED3=1;
       }
         
      if( GetKeyPad()==1) //scredirver works,
       {
         //PORTCbits.RC7= 1; //DRV_ENABLE =1 ;
          //PORTCbits.RC6 =1 ;//DRV_BRAKE =1 ;
          PORTC = 0xc0;  //start on
           delay_10ms(10);
          //PORTC = 0xce;
       }
         if( GetKeyPad()==0)
         {
             PORTC = 0x0; //breake 
             delay_10ms(50);
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
           PORTC = 0x0;
           delay_10ms(50);
          // LATC6 =0;//PORTCbits.RC6=1;//DRV_BRAKE = 0 ;
           
         
       }
     }
 

}
