#include "key.h"
#include "LED.h"
#include "Drv8306.h"
#include "MachineLearing.h"
#include "Output_SIG.h"



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
  
      TRISCbits.TRISC5 =1;
	   __delay_ms(2);
       DRV_BRAKE =0 ;
       Auto_OutPut_Brake=0;
       return 1;
      
  }
  
  if (Key_Start == 0) //WT.EDIT 2019-07-22
  {
	  __delay_ms(2);//__delay_ms(2);//delay_1ms(5); //WT.EID 2019-07-22
     
      
      return 0;
     
     
   }
  
 
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
 
  if(Key_MachineL == 1 )
  {
      if( AUTO_OUTPUT_DIR==1)
      {
        __delay_ms(1);//delay_1ms(5); //WT.EDIT 2019-06-10
      
        my_drv.drv_dir=1;
        //Auto_Works_Signal = 1;
    
      
        return 1;
      
      }
     if( AUTO_OUTPUT_DIR==0)
     {
     
          __delay_ms(1);//delay_1ms(5); //WT.EDIT 2019-06-10
           
            my_drv.drv_dir=2;
          

            return 0;
       }
   }
  else
  {
   if(Key_Dir ==1)// CW   motor run to works 2019-07-25
   {

       if(my_drv.drv_dir ==4)
       {
      
            __delay_ms(1);//delay_10ms(1); //WT.EDIT 2019-06-10
            //if(my_drv.drv_dir ==4)
            {
              DRV_DIR =0;
             
              //TXREG=0x12;

              return 0;
            }
       }
       else

       {
        __delay_ms(1);//delay_1ms(5); //WT.EDIT 2019-06-10
      
        my_drv.drv_dir=1;
      
    
      
        return 1;
       }
		 
   }
   else if(Key_Dir ==0)  //clockwise Motor do works run
   {
       
       if(my_drv.drv_dir ==4)
        {
          __delay_ms(1);//delay_10ms(1);//WT.EDIT 2019-06-10
         
           return 1;
          
        }
        else 

        {
           __delay_ms(1);//delay_1ms(5); //WT.EDIT 2019-06-10
          
            my_drv.drv_dir=2;
           

            return 0;
         }
           
    }
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
		//  TXREG=0xcc;
		  return 1;
        
	   }
 
  }
  	

	
}
	   
           
