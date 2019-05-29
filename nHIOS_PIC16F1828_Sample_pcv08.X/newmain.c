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


//#define LENGTH(a) ((sizeof(a))/(sizeof(a[0])))
uchar flag_power_on=0;


 
/**************************************************************
 *
 *Function :main()
 * input regerence :noting
 *
 *************************************************************/
void  main(void )
{
    uchar rem=0, machine_key=0,k=0,m=0,n=0,power_on=1,counter=0;
    uint size_n;
    uchar  mykey=1,times_m=0,times_n=0,mydir = 0;  //wt.edit 2019-02-21
    uchar flag_brake,flag_run=0;   
 
    init_fosc();
    USART_Init();
   // Led_Init();
    Key_Init();
    Timer1_Init();
    Output_SIG_Init();
    Drv8306_Init();
    HALL_Init();
    Drv8306_PWM();
    TRISCbits.TRISC5 =1;
               
    while(1)
    {
      
      
      machine_key =MachineLearning_Key();
	  mydir = Manual_Operation_Dir();
      mykey =GetKeyPad();
     if((flag_power_on==2)||(my_drv.drv_brake ==1))
      {
       
        TRISCbits.TRISC5 =1;
        DRV_BRAKE =0 ;
        Auto_OutPut_Brake=1;
        delay_10ms(5);
         
        //Auto_OutPut_Brake=1;
        TMR1_Counter_Enable = 0;
        Auto_Works_Signal = 1;
        TXREG=0xff;
        delay_1ms(10);
        switch(machine_key)
        {     
         case 0 :
         {
            flag_brake=2;
            size_n =0;
            EEPROM_Write_OneByte(0x56,0);

         }
         break;
         case 1 : //machine deep learning 
             {
                
                 
                 TXREG  = size_n ;
                 delay_1ms(10);
                 if( size_n ==0  )
                   {
                       size_n = EEPROM_Read_OneByte(0x56);

                       if(size_n == 245)
                        {
                           size_n= 245 ; // rember
                        }
                       else 
                        size_n  = 0;
                      
                       TXREG = size_n ;
                       delay_1ms(10);

                  }
                  if(size_n < 242 )
                   {

                       m = k;    // 262ms * k = m
                       TXREG=m;
                       delay_1ms(10);
                      
                       n = TMR1H;  // 4* 256 * TMR1H / 1000 (ms) = n+++++++++++++++
                       TXREG = n ;
                       delay_1ms(10);
                       if((n >03) ||(k >1)||(k ==1))
                       {
                            size_n = size_n + 1;
                            TXREG = size_n ;
                            delay_1ms(10);
                           if(size_n < 81)
                           {
                              EEPROM_Write_OneByte(size_n+99,m); // m > n to save sample of data
                              EEPROM_Write_OneByte(size_n-1,n); // m > n
                              Average_First(size_n,0xb5);

                              TXREG = 0xaa;     //flag bit 0xba
                              delay_1ms(10);
                              Average_Second(size_n,0x53);
                           }
                           else if(size_n > 80 && size_n < 161)
                           {
                              counter = size_n -80 ;
                              EEPROM_Write_OneByte(counter+99,m); // m > n to save sample of data
                              EEPROM_Write_OneByte(counter-1,n); // m > n
                              Average_First(counter,0xb6);

                              TXREG = 0xbb;     //flag bit 0xba
                               delay_1ms(10);
                              Average_Second(counter,0x54);
                           }
                           else if(size_n > 160 && size_n < 241)
                           {
                              counter = size_n - 160;
                              EEPROM_Write_OneByte(counter+99,m); // m > n to save sample of data
                              EEPROM_Write_OneByte(counter-1,n); // m > n
                              Average_First(counter,0xb7);

                              TXREG = 0xcc;     //flag bit 0xba
                               delay_1ms(10);
                              Average_Second(counter,0x55);

                           }
                        }
                      }
                      else if(size_n > 241  && size_n < 244)
                      {
                        size_n = 245;
                        EEPROM_Write_OneByte(0x56,size_n);
                        times_m = Machine_M_Learning();
                        TXREG = times_m;     //flag bit 0xef
                        delay_1ms(10);

                        times_n = Machine_N_Learning();
                        TXREG = times_n;     //flag bit 0xef
                        delay_1ms(10);

                        TXREG = size_n;     //flag bit 0xef
                        delay_1ms(10);
                       }
                      else if(size_n > 243)
                      {
                        TXREG=size_n;
                        delay_1ms(10);
                        
                        if(size_n == 65535)
                          size_n = 245;
                        times_m = Machine_M_Learning();
                        times_n = Machine_N_Learning();
                       }
                  
                       m = k;
                       n = TMR1H;
                       TXREG = times_m;     //flag bit 0xef
                         delay_1ms(10);
                       TXREG = times_n;     //flag bit 0xef
                         delay_1ms(10);

                       if((m > times_m) && ( m != 0))
                       {

                           flag_brake=2;

                        }
                       else if(m < times_m && m != 0)
                       {
                          flag_brake=2; 
                       
                       }
                       else if ((m == times_m)&&( m == 0))
                        {

                           if (n > times_n || n == times_n)
                           {
                             flag_brake=2;
                           }
                           else if((n + 0x0a) > times_n  && (times_n >= 0x0a))
                           {
                               flag_brake=2;
                           
                           }
                           else if ( n > 0x05 || n == 0x05)
                           {
                             flag_brake=2;
                           }
                         
                        }
                       

                }
                break;
             
		   }//switch(machine_key))

    }//end if(flag_power_on))
     
	switch(mykey)
        {
            case 0 : //run works
            {
                if((mydir == 0)&&(flag_brake ==2)&&(flag_brake!=3)&&(flag_brake!=0))
                {
                    
                    Auto_Works_Signal = 1;
                    TRISCbits.TRISC5 =1;
                     DRV_BRAKE = 0; //run
                     DRV_ENABLE=0;
				     Auto_OutPut_Brake=1;
                     delay_10ms(2); //WT.EDIT 20190505
				     TMR1H=0;
		             TMR1L=0;
                     k=0;
                     Auto_Works_Signal = 1;
                     TXREG=0x55;
                   
                     //delay_1ms(10);
                     
                }
                else if((((mydir == 0)||(my_drv.drv_dir==2)) 
					     ||((mydir==1)&&(flag_brake == 4)))&&(flag_brake!=5)&&(flag_brake !=0))
                {
                   
                    //DRV_DIR =0;
                    Auto_OutPut_Brake=0;
                    DRV_BRAKE = 1; //run
                   
                    DRV_ENABLE=1;
                    Auto_Works_Signal = 1;
                 
                    if(rem==0)
                    {
                       //DRV_DIR =0;
                     //  Auto_Works_Signal = 1;
                     //  Auto_OutPut_Brake=0;
                        rem++;
                         PR2 =0x4;//
                         CCPR1L =0x4;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                        
                         PR2 =0x5;//
                         CCPR1L =0x5;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         
                         PR2 =0x6;//
                         CCPR1L =0x6;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         
                         PR2 =0x7;//
                         CCPR1L =0x7;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         
                         PR2 =0x8;//
                         CCPR1L =0x8;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                        delay_1ms(1);
                        
                        PR2 =0x9;//
                         CCPR1L =0x9;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         
                         PR2 =0x0a;//
                         CCPR1L =0x0a;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         
                         PR2 =0xb;//
                         CCPR1L =0x0b;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         
                         PR2 =0x0c ;//
                         CCPR1L = 0x0c;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         
                          PR2 =0x0d ;//
                         CCPR1L = 0x0d;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         TXREG=0x12;
                    
                        // delay_100us(2);
                    }
                    //DRV_DIR =0; 
                    TRISCbits.TRISC5 =0;
                    
                    
                      PEIE =1;   
                      GIE = 1; 
                   
                      TXREG=0x77;
                      rem=5;
                    Auto_OutPut_Brake=0;
                   TMR1_Counter_Enable = 1;
                   if(PIR1bits.TMR1IF ==1)//if(TMR1H ==0xFF) //
		            {
		                PIR1bits.TMR1IF=0;
		                 k=k+1;
		                 TMR1H=0;
		                 TMR1L=0;
                     }
                     Auto_OutPut_Brake=0;
                     Auto_Works_Signal = 1;
                     flag_brake =4;
                     my_drv.drv_dir=4; //WT.EDIT 20190508
                     TXREG=0x88;
                    // delay_100us(2);
                     flag_power_on=1;
                     my_drv.drv_enable=2;
                }
                else if(((mydir == 1 || my_drv.drv_dir ==1)
					      ||((mydir==0)&&(flag_brake == 5)))&&(flag_brake!=4)&&(flag_brake !=0))
			    {
                    Auto_Works_Signal = 0;
                    Auto_OutPut_Brake=0;
                    DRV_DIR =1;
                    DRV_BRAKE = 1; //run
                    DRV_ENABLE=1;
                   if(rem==0)
                    {
                        DRV_DIR =1; 
                        Auto_OutPut_Brake=0;
                       rem++;
                        
                         PR2 =0x4;//
                    
                         CCPR1L =0x4;    //MSB 8bit<>pulse duty of value
                   
                         TRISCbits.TRISC5 =0;
                   
                         delay_1ms(1);
                         PR2 =0x5;//
                 
                         CCPR1L =0x5;    //MSB 8bit<>pulse duty of value
                    
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         PR2 =0x6;//
                      
                         CCPR1L =0x6;    //MSB 8bit<>pulse duty of value
                      
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                      
                         PR2 =0x7;//
                  
                         CCPR1L =0x7;    //MSB 8bit<>pulse duty of value
                      
                         TRISCbits.TRISC5 =0;
                        delay_1ms(1);
                        PR2 =0x8;//
                         CCPR1L =0x8;    //MSB 8bit<>pulse duty of value
                    
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                  
                         PR2 =0x9;//
              
                         CCPR1L =0x9;    //MSB 8bit<>pulse duty of value
                 
                         TRISCbits.TRISC5 =0;
                        delay_1ms(1);
                         PR2 =0x0a;//
                         CCPR1L =0x0a;    //MSB 8bit<>pulse duty of value
                
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         PR2 =0xb;//
                         CCPR1L =0x0b;    //MSB 8bit<>pulse duty of value
                  
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         PR2 =0x0c ;//
                         CCPR1L = 0x0c;    //MSB 8bit<>pulse duty of value
                    
                         TRISCbits.TRISC5 =0;
                        delay_1ms(1);
                         TXREG=0x23;
                         Auto_OutPut_Brake=0;
                       //  delay_100us(2);
                    }
                    DRV_DIR =1;
                    TRISCbits.TRISC5 =0;
                    IOCIE =0;
                    PEIE =0;   
                    GIE = 0;
                    IOCAP2 = 0;  //Flag IOCAF0  //WT.EDIT 2019-02-20
                    IOCAN2 =0; 
                    rem=5;
                     TXREG=0x22;
                    //delay_100us(10);
                   
                     flag_brake=5;
                    // DRV_BRAKE = 1;
					 TMR1_Counter_Enable = 0;
		             k=0;
					 TMR1H =0;
					 TMR1L = 0;
                    flag_power_on=0; //WT.EIDT 20190508
                    my_drv.drv_dir=3;
					my_drv.drv_brake =3; //WT.EDIT 20190508
				     Auto_OutPut_Brake=0;
                     Auto_Works_Signal = 0;
                    // DRV_BRAKE = 1;
                    TXREG=0x33;
                   // delay_100us(10);
                    my_drv.drv_enable=1;
                     mydir = Manual_Operation_Dir();
                    mykey =GetKeyPad();
                    
                 }
			
               
         }
            break;
           
			case 1: //STOP_key
            {
#if 0
                if(flag_brake == 2)
                {
                      GIE = 0;
                      PEIE =0 ;
                      flag_brake=0;
					  flag_power_on=0;
					  Auto_OutPut_Brake=0;
                      Auto_Works_Signal = 0;
				
	                 DRV_BRAKE = 1; //run
                     DRV_ENABLE=1;
                     DRV_DIR =0;
                    
                         PR2 =0x4;//
                         CCPR1L =0x4;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                        
                         PR2 =0x5;//
                         CCPR1L =0x5;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         
                         PR2 =0x6;//
                         CCPR1L =0x6;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         
                         PR2 =0x7;//
                         CCPR1L =0x7;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         
                         PR2 =0x8;//
                         CCPR1L =0x8;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                        delay_1ms(1);
                        
                        PR2 =0x9;//
                         CCPR1L =0x9;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         
                         PR2 =0x0a;//
                         CCPR1L =0x0a;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         
                         PR2 =0xb;//
                         CCPR1L =0x0b;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         
                         PR2 =0x0c ;//
                         CCPR1L = 0x0c;    //MSB 8bit<>pulse duty of value
                         TRISCbits.TRISC5 =0;
                         delay_1ms(1);
                         TXREG=0x45;
                        
                        
                 
                    delay_10ms(20);

				  DRV_BRAKE =0;
                //  DRV_ENABLE=0;
                  TRISCbits.TRISC5 =1;
                  delay_10ms(4);  //WT.EDIT 20190505
                  DRV_BRAKE =0;
                   Auto_OutPut_Brake=0;
                   Auto_Works_Signal = 0;
                 
                  
				}
                else 
#endif 
                {
                  Auto_OutPut_Brake=0;
                  Auto_Works_Signal = 0;
                  DRV_BRAKE =0;
                  TRISCbits.TRISC5 =1;
                  delay_10ms(6);  //WT.EDIT 20190505
                  DRV_BRAKE =0;
                  DRV_ENABLE=0;
                  IOCIE =0;
                  PEIE =0;   
                  GIE = 0;
                  IOCAP2 = 0;  //Flag IOCAF0  //WT.EDIT 2019-02-20
                  IOCAN2 =0; 
                  rem=0;
				  
                flag_brake=3;
                
		        k=0;
				TMR1H =0;
				TMR1L = 0;
			    flag_run=0;
		
				
                my_drv.drv_enable = 0;
			     my_drv.drv_brake=0;
                my_drv.drv_dir=0;
                 flag_power_on=0;
                  TXREG=0xf1;
                Auto_OutPut_Brake=0;
             
				mydir = Manual_Operation_Dir();
                mykey =GetKeyPad();
			   }
                 
		    }
            break;
            
            
           
           

	     default :
	     	{
			  TRISCbits.TRISC5 =1;
			  DRV_ENABLE=0;
			  flag_power_on=0;
			  Auto_OutPut_Brake=0;
			  TMR1_Counter_Enable = 0;
			  Auto_Works_Signal = 0;
			  k=0;
			 TMR1H =0;
			 TMR1L = 0;
      
			 
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
   
if((IOCAF2 == 1)||(PORTAbits.RA2 == 0))
{
     
      INTF =0;
	  IOCIF =0;
      IOCAF2=0;
      IOCAP2=0;
      flag_power_on=flag_power_on+ 1;
      my_drv.drv_brake =1;
      TXREG=0x66;
      delay_100us(5);
#if 0     
      TRISCbits.TRISC5 =1;
      DRV_BRAKE =0 ;
      Auto_OutPut_Brake=1;
      delay_10ms(5);
       TXREG=0x66;
       delay_1ms(2);
#endif 
 }
#if 0
 else if(IOCAP0 == 1) //||IOCAN0==1||(PORTAbits.RA0 == 0))
{
    INTF =0;
	IOCIF =0;
    IOCAF0=0;
    IOCAP0=0;
    TRISCbits.TRISC5 =1;
    DRV_BRAKE =0 ;
    Auto_OutPut_Brake=1;
    delay_10ms(10);
    TXREG=0x44;
    delay_1ms(2);
    my_drv.drv_brake =3;
}
#endif 
  
}  


   
 




