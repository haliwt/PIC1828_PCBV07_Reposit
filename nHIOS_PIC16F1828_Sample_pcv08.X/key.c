#include "key.h"
#include "LED.h"
#include "Drv8306.h"
#include "MachineLearing.h"
#include "Output_SIG.h"
#include "Timer1.h"


/************************************************************
 *
 * Function Name:Key_Init(void)
 *
 *
 ************************************************************/
void Key_Init(void)
{
    TRISAbits.TRISA0 =1;  //Key_start input
    ANSA0 = 0;
   
   
   TRISCbits.TRISC2 =1 ; //machine learning switch IO 

    TRISCbits.TRISC1 = 1;  //manual directin key
    
    TRISCbits.TRISC3 = 0;  //PCBV06- DRV8306_DIR 
    ANSC3 =0;
	DRV_DIR = 0;
    
    ANSC1 = 0;  //wt.edit New_direction key 
   
	ANSC2 = 0;
}
/************************************************************
 *
 * Function Name:uchar GetKeyPad(void)
 *
 *
 ************************************************************/
uchar GetKeyPad(void)
{

  if(Key_Start == 1) //stop
  {
       DRV_BRAKE =0 ;
       TRISCbits.TRISC5 =1;
	   Auto_OutPut_Brake=0;
       delay_10ms(1);
       DRV_BRAKE =0 ;
       TXREG=0xbb;
       delay_100us(10);
       return 1;
      
  }

  else //if (Key_Start == 0)  //run //WT.EDIT 2019-02-20
  {
	  TXREG=0xaa;
     // delay_100us(5);
      return 0;
   }
 // else 
      //return 1;
}
 
/************************************************************
 *
 * Function Name:void Manual_Operation_Dir(void);
 * Function Active: run clockwise and  anticlockwise
 *
 *
 ************************************************************/
uchar  Manual_Operation_Dir(void)
{
   
   if(Key_Dir ==1)//anticlockwise Motor don't works run
   {
       
      // delay_1ms(20); //WT.EDIT DISABLE 201905.14
	   //if(Key_Dir ==1) //CCW
	   //	{
          
           if(my_drv.drv_dir ==4)
           {
              DRV_DIR =0;
			   TXREG=0x21;
              return 0;
           }
           else
           {
            Auto_OutPut_Brake=0;
			DRV_DIR =1;
            my_drv.drv_dir=1;
            TXREG=0x11;
           delay_100us(5);
            return 1;
           }
		  
	   //	}
   }
   else if(Key_Dir ==0)  //clockwise Motor do works run
   {
       
       //delay_1ms(20); //WT.EDIT 201905.14
      // if(Key_Dir==0)
      // {
           if(my_drv.drv_dir ==3)
           {
              Auto_OutPut_Brake=0;
			  DRV_DIR =1;
			  TXREG=0x01;
              return 1;
           }
           else
           {
           
           DRV_DIR =0;
           my_drv.drv_dir=2;
           TXREG=0x00;
           delay_100us(5);
            return 0;
           }
      //  }
   }
   
  
}
/************************************************************
 *
 * Function Name:MachineLearning_Key(void)
 * Function Active:switch machine learning  
 * Input Reference:no
 * Output Reference: key if press of value
 *
 ************************************************************/
uchar MachineLearning_Key(void)
{
 if(Key_MachineL == 0) //disable machine learning model
 {
      delay_100us(1);
	   if(Key_MachineL == 0)
	   {
          my_machine.machine_swtich =0 ;
		  return 0;
        
	   }

 }
 else if(Key_MachineL == 1) //Enable machine learning model
  {
    delay_100us(1);
	if(Key_MachineL == 1)
	   {
		  my_machine.machine_swtich =1 ;
		  TXREG=0xcc;
		  return 1;
        
	   }
 
  }
  	

	
}
	   
           
