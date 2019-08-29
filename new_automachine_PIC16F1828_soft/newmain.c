#include <xc.h>
#include "Delay.h"
#include "Hall_int.h"
#include "Drv8306.h"
#include "key.h"
#include "Output_SIG.h"
#include "RS232.h"
#include "MachineLearing.h"
#include "ShellSort.h"
#include "Eeprom.h"
#include "Timer1.h"
#include "ADC.h"

/*2019-04-03 */
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
/*ChenYu_Co. Soft 2019-05-09*/
// CONFIG1
#pragma config FOSC = EXTRC       // Oscillator Selection (ECH, External Clock, High Power Mode (4-32 MHz): device clock supplied to CLKIN pin)
#pragma config WDTE = ON        // Watchdog Timer Enable (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = OFF       // PLL Enable (4x PLL enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)



#define DELAY_STOP   

//#define LENGTH(a) ((sizeof(a))/(sizeof(a[0])))
uchar flag_power_on=0;
uchar data[4];

 
/**************************************************************
 *
 *Function :main()
 * input regerence :noting
 *
 *************************************************************/
void  main(void )
{
    uchar rem=1, flag_auto_test=0;
    uchar  mykey=1,mydir = 0;  //wt.edit 2019-02-21
    uchar flag_brake,b_s; 
    volatile uchar  flag_run;
    uint adc_value =0 ,read_adc = 0;
 
    init_fosc();
    USART_Init();
   // Led_Init();
    ADC_Init();
    Key_Init();
    Timer1_Init();
    Output_SIG_Init();
    Drv8306_Init();
    HALL_Init();
    Drv8306_PWM();
    TRISCbits.TRISC5 =1;
               
  while(1)
  {
    
   
    mykey =GetKeyPad(); //jude the key if key down scan 
	mydir = Manual_Operation_Dir();  //direction key scan
    
    if(Key_MachineL == 1 ) //jude automation of machine by test be used to .
    {
       flag_auto_test=1;  //by test automation for factory ,don't used to customer
      
    }
    else  flag_auto_test=0;  // by customer of model.
        
	
     
	  if((flag_power_on==2)||(my_drv.drv_brake ==1)) //the motor be brake statement
      {

         Auto_OutPut_Brake=1;
        DRV_BRAKE = 0; //run
        CCPR1L =0;   //WT.EDIT 2019-06-10
         TRISCbits.TRISC5 =1;
         DRV_ENABLE=0;
         flag_brake=2;
       TMR1_Counter_Enable = 0;
        TXREG=0x00;
       }//end if(flag_power_on))
     
	  switch(mykey)
        {
            case 0 : //run works
            {
BRAKE_S:      if((mydir == 1)&&(flag_brake ==2)&&(flag_brake!=3)&&(flag_brake!=0))
                {
                    
                   // Auto_Works_Signal = 1;
                    CCPR1L =0;   //WT.EDIT 2019-06-10
                    TRISCbits.TRISC5 =1;
                     DRV_BRAKE = 0; //run
                     DRV_ENABLE=0;
                     if(b_s ==1)
                     {
                         Auto_OutPut_Brake=0;
                     }
                     else 
				     Auto_OutPut_Brake=1;
                     delay_10ms(2); //WT.EDIT 20190505
                  
                    // Auto_Works_Signal = 1;
                     TXREG=0x55;
                   
                     //delay_1ms(10);
                     
                }
				/***********************CW Rotate*********************************************************/
                /**********************************************************************************/
				else if(((((mydir == 1)||(my_drv.drv_dir==1))&&flag_brake != 2) ||((mydir==0)&&(flag_brake == 4)))
                               &&(my_drv.drv_enable!=1 && flag_brake !=5 && flag_brake !=2))
               {
                    DRV_DIR =0;//WT.EDIT 2019-06-13
                    Auto_OutPut_Brake=0;
                    DRV_BRAKE = 1; //run
                    DRV_ENABLE=1;
                    TRISCbits.TRISC5 =0;
                    TMR1_Counter_Enable = 1;
                    rem++;
                    if(Key_Start == 1)
                    {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                    }
                    if(flag_run == 0x0a)
                    {
                     Auto_OutPut_Brake=1;// Auto_Works_Signal = 1;
                     CCPR1L =0;   //WT.EDIT 2019-06-10
                     TRISCbits.TRISC5 =1;
                     DRV_BRAKE = 0; //run
                     DRV_ENABLE=0;
				     flag_brake =2;
                     TXREG = 0xa5;
                     while(1);
                
                    }
                    else if(rem==2)
                    {
                     
                         rem++;
					    DRV_DIR =0; //WT.EDIT 2019-06-13
                        CCPR1L =0x0;    //MSB 8bit<>pulse duty of value
                        
                        if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                         DRV_DIR =0;
                         CCPR1L =0x01;    //MSB 8bit<>pulse duty of value
                        if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                         DRV_DIR =0;
                         CCPR1L =0x02;    //MSB 8bit<>pulse duty of value
                          if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                         DRV_DIR =0;
                         CCPR1L =0x03;    //MSB 8bit<>pulse duty of value
                          if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                         DRV_DIR =0;
                         CCPR1L =0x04;    //MSB 8bit<>pulse duty of value
                          if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                         DRV_DIR =0;
                         CCPR1L =0x05; 
                          if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                         DRV_DIR =0;
                         CCPR1L =0x06;   
                          if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                         DRV_DIR =0;
                         CCPR1L =0x07;    
                          if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                         DRV_DIR =0;
                         CCPR1L =0x08;   
                          if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                         DRV_DIR =0;
                         CCPR1L =0x09;    
                          if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                         DRV_DIR =0;
                         CCPR1L =0x0a;    
                          if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                         DRV_DIR =0;
                         CCPR1L =0x0b;    
                          if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                         DRV_DIR =0;
                         CCPR1L = 0x0c;   
                          if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                         DRV_DIR =0;
                         CCPR1L = 0x0d;    
                          if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                        
                         TXREG=0xa1;
                       
                    }
                    
                     if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                    }
                    
                    
                    if(flag_auto_test==0)
                    {
                        
                    if(PIR1bits.TMR1IF == 1) 
                    {

                        TXREG= 0xa2 ;
                       //delay_1ms(5);
                       TMR1_Counter_Enable = 0;
                       PIR1bits.TMR1IF =0;
                       TMR1L =0;
                       TMR1H =0;

                      adc_value = ADC_GetValue();
                     // convertDecimalToHexa(adc_value);
                      TXREG = 0xff;
                       if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                    
                       if(adc_value > 0x100 || adc_value ==0x100)//judge overcurrent protect
                       {
                          // TXREG = 0xee;
                            my_drv.error_f = my_drv.error_f + 1;
                           //  TXREG = my_drv.error_f ;
                          
                             flag_run = flag_run + 1;
                            // TXREG = flag_run;
                          
                            // TXREG = 0xa3;
                              if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
                            if( my_drv.error_f ==2 ||flag_run == 2)
                            {
                                flag_brake=2;
                              
                                flag_run=0x0a;
                              //  TXREG = 0xa4;
                               
                                while(1);
                                
                                
                            }
                       }
                      } 
                      
                    } 
                    rem=5;
                    
                    
                   // Auto_Works_Signal = 1;
                    Auto_OutPut_Brake=0;
                  
                      IOCIE =1;
                      IOCIF=0;
                      PEIE =1;   
                      GIE = 1; 
                      IOCAP2 = 1;  //Flag IOCAF0  //WT.EDIT 2019-02-20
                      IOCAN2 =1; 
                   
                       if(Key_Start == 1)
                        {
                            TRISCbits.TRISC5 =1;
                            __delay_ms(5);
                            DRV_BRAKE =0 ;   
                            b_s = 1;
                            flag_brake =2;
                            mydir = 1;
                            goto BRAKE_S;
                        }
                     
                     
                     flag_brake =4;
                     my_drv.drv_dir=4; //WT.EDIT 20190508
                  
                     flag_power_on=1;
                     my_drv.drv_enable=2;
                    
                      
                }  
				
				/**********************ccw*******************************************************/
				  else if(((mydir == 0 || my_drv.drv_dir ==2)
                         ||((mydir==1)&&(flag_brake == 5)))&&(my_drv.drv_enable!=2 && flag_brake !=4 && flag_brake !=2))
					{
					    
		                    DRV_DIR =1;
		                    /**/
		                    //Auto_Works_Signal = 0;
		                    Auto_OutPut_Brake=0;
		                    
		                    DRV_BRAKE = 1; //run
		                    DRV_ENABLE=1;
		                    TRISCbits.TRISC5 =0;
							TMR1_Counter_Enable = 1;
		                    rem++;
                            if(flag_run ==0x0b)
                            {
                                Auto_OutPut_Brake=1;// Auto_Works_Signal = 1;
                                CCPR1L =0;   //WT.EDIT 2019-06-10
                                TRISCbits.TRISC5 =1;
                                DRV_BRAKE = 0; //run
                                DRV_ENABLE=0;
                                flag_brake =2;
                                TXREG = 0xb5;
                                while(1);
                            }
		                    else if(rem==2)
		                    {
		                        rem++;
		                        DRV_DIR =1; 
		                        CCPR1L =0x0;    
                                if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
		                       
		                         DRV_DIR =1; 
		                         CCPR1L =0x1;    //MSB 8bit<>pulse duty of value
		                          if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
		                         DRV_DIR =1; 
		                         CCPR1L =0x2;    //MSB 8bit<>pulse duty of value
		                         if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
		                         DRV_DIR =1; 
		                         CCPR1L =0x3;    //MSB 8bit<>pulse duty of value
		                           if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
		                         DRV_DIR =1; 
		                         CCPR1L =0x4;    //MSB 8bit<>pulse duty of value
		                          if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
		                         DRV_DIR =1; 
		                         CCPR1L =0x5;    //MSB 8bit<>pulse duty of value
		                          if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
		                         DRV_DIR =1;    
		                        CCPR1L =0x06;    //MSB 8bit<>pulse duty of value
		                         if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
		                         DRV_DIR =1;    
		                         CCPR1L =0x07;    //MSB 8bit<>pulse duty of value
		                           if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                } 
		                         DRV_DIR =1;   
		                         CCPR1L = 0x08;    //MSB 8bit<>pulse duty of value
		                         if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
		                         DRV_DIR =1;    
		                         CCPR1L = 0x09;    //MSB 8bit<>pulse duty of value
		                          if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
		                         DRV_DIR =1;    
		                         CCPR1L = 0x0a;    //MSB 8bit<>pulse duty of value
		                        if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
		                          DRV_DIR =1;    
		                          CCPR1L = 0x0b;    //MSB 8bit<>pulse duty of value
		                           if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
		                          DRV_DIR =1;    
		                          CCPR1L = 0x0c;    //MSB 8bit<>pulse duty of value
		                           if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
		                           DRV_DIR =1;    
		                          CCPR1L = 0x0d;    //MSB 8bit<>pulse duty of value
		                       
		                          
		                          //TXREG=0xb1;
		                         
		                    }
		                    DRV_DIR =1;
		                   if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
		                    
		                    GIE =0;
                          if(flag_auto_test==0)	
                          {
		                     if(PIR1bits.TMR1IF == 1) 
                             {
		                      
		                       TXREG= 0xb2 ;
		                       //delay_1ms(5);
		                       TMR1_Counter_Enable = 0;
		                       PIR1bits.TMR1IF =0;
		                       TMR1L =0;
		                       TMR1H =0;

		                       adc_value = ADC_GetValue();
			                   //convertDecimalToHexa(adc_value);
			                    if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }    
			                  
			                   
			                    if(adc_value > 0x100 || adc_value ==0x100)
		                       {
		                          //   TXREG = 0xdd;
		                             my_drv.error_f = my_drv.error_f + 1;
		                           //  TXREG = my_drv.error_f ;
		                            // __delay_ms(1);
		                             flag_run = flag_run + 1;
		                           //  TXREG = flag_run;
		                           //  __delay_ms(1);
		                           //  TXREG = 0xb3;
                                      if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
		                            
		                            if( my_drv.error_f ==2 || flag_run == 2)
		                            {
		                                flag_brake=2;
		                                flag_run = 0x0b;
		                            }
		                       }
		                    }
                          }
		                     rem=5;
		                     if(Key_Start == 1)
                                {
                                    TRISCbits.TRISC5 =1;
                                    __delay_ms(5);
                                    DRV_BRAKE =0 ;   
                                    b_s = 1;
                                    flag_brake =2;
                                    mydir = 1;
                                    goto BRAKE_S;
                                }
		                  
                                flag_brake=5;
                                flag_power_on=0; //WT.EIDT 20190508
                                my_drv.drv_dir=3;
                                my_drv.drv_brake =3; //WT.EDIT 20190508
                                my_drv.drv_enable=1;
		                  }
		         
		            break;
            	}
			case 1: //STOP_key
            {
                 Auto_OutPut_Brake=0;
               
                 TRISCbits.TRISC5 =1;
                 __delay_ms(5);
                 DRV_BRAKE =0 ;
               
                 DRV_ENABLE=0;
               
                Auto_OutPut_Brake=0;
             
                  IOCIE =0;
                  IOCIF=1;
                  PEIE =0;   
                  GIE = 0;
                  IOCAP2 = 0;  //Flag IOCAF0  //WT.EDIT 2019-02-20
                  IOCAN2 =0; 
                
                  rem=1;
				  
                flag_brake=3;
                
		   
				
			    flag_run=0;
		        my_drv.error_f=0;
			    my_drv.default_f =0;
                my_drv.drv_enable = 0;
			     my_drv.drv_brake=0;
                my_drv.drv_dir=0;
                 flag_power_on=0;
                Auto_OutPut_Brake=0;
              }
            break;
         default :
	     	{
			  TRISCbits.TRISC5 =1;
			  DRV_ENABLE=0;
			  flag_power_on=0;
			  Auto_OutPut_Brake=0;
			}
            break;
         }//end switch(mykey)
    
     

     }//end while(1)
	 
  }
   

/**************************************************************
 *
 * Function function: interrupt program hall sensor
 * Input Reference :Noting
 * Return Reference :Noting
 *  Note:MPLAB X is 3.0 :void interrupt Hallsensor(void)
 *
******************************************************/

void __interrupt() Hallsensor(void)
{
   
if((INTF == 1) ||(IOCAF2 == 1) || (IOCAP2 ==1)||(PORTAbits.RA2 == 0)||(IOCIF ==1))
{
     
      INTF =0;
	  IOCIF =0;
      IOCAF2=0;
      IOCAP2=0;
      flag_power_on=flag_power_on+ 1;
      my_drv.drv_brake =1;
      TXREG=0x66;
      delay_100us(5);
     
      CCPR1L =0;   //WT.EDIT 2019-06-10
      TRISCbits.TRISC5 =1;
      DRV_BRAKE =0 ;
      Auto_OutPut_Brake=1;
      __delay_ms(5);
      TXREG=0x66;
     
 
 }

  
}  


   
 




