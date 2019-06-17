#include "Drv8306.h"


//my_drv8306 drv ={0,0,0,0,0,0};
/******************************************
 *
 * Function Name: Drv8306_Init()
 * Function : Inition
 *
 *****************************************/
void Drv8306_Init(void)
{
   
    TRISCbits.TRISC4 = 0;  //PCBV_08 DRV8306 Brake
   
    TRISAbits.TRISA4 = 0; //PCBV06 -DRV8306_ENABLE 2019-03-14
    ANSA4 =0;
    DRV_ENABLE = 0;
    DRV_BRAKE = 1; //WT.EDIT 2019-0506 This is key
  
  
    
}
/******************************************
 *
 * Function Name: Drv8306_PWM()
 * Function Active: output OSC 8Mhz
 *Input Reference: NO   PR2 = 0X0d ,Pre = 16 f=8.92 KHZ
 *                high speed PR2 =0xc, Pre= 4,f= 38.46Khz
 *Output Reference:NO
 *
 *****************************************/
void Drv8306_PWM(void)
{

    TRISCbits.TRISC5=1;  //PWM CCP1,OSC =8MHZ

   //T2CON = 0x04;    //TXCON <>TIMER2 enable ,prescaler is=1 .
#ifdef HIGHSPEED
    PR2 =0x0c;
    T2CON = 0x05;     //Prescaler = 4 ; WT.EDIT 2019-06-17
    //T2CON = 0x04;        //TXCON <>TIMER2 enable ,prescaler is=1 .
#else
   T2CON = 0x06;  //Prescaler = 16, high speed is 1568 rpm 
   PR2= 0x0d;
#endif
   CCPR1L = 0x00;    //MSB 8bit<>pulse duty of value
   CCP1CON = 0x0d ;//LSB has 2 bits in <5:4>
   CCPTMRS0 = 0;//0xFC ;  //PWM timer selectiong control RE :Enable PWM
    
}


