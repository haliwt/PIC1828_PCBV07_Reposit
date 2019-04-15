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
   
    //TRISCbits.TRISC4 = 1;  //PCBV_06 capture
    //ANSC4 =0;
  
	 
    TRISAbits.TRISA4 = 0; //PCBV06 -DRV8306_ENABLE 2019-03-14
    ANSA4 =0;
    DRV_ENABLE = 0;
  
  
    
}
/******************************************
 *
 * Function Name: Drv8306_PWM()
 * Function Active: output OSC 8Mhz
 *Input Reference: NO   PR2 = 0X07  F= 62.5KHZ
 *Output Reference:NO
 *
 *****************************************/
void Drv8306_PWM(void)
{

    TRISCbits.TRISC5=1;  //PWM CCP1,OSC =8MHZ
    PR2 =0x04 ;//0x06;//0x05//0x04     //Timer2 period Register,f =100Khz
    CCPR1L = 0x04;    //MSB 8bit<>pulse duty of value
    CCP1CON = 0x0d ;//LSB has 2 bits in <5:4>
    CCPTMRS0 = 0;//0xFC ;  //PWM timer selectiong control RE :Enable PWM
   //T2CON  = 0X07;     //TIMER2 of TIMER2,prescaler is 64
    T2CON = 0x04;    //TXCON <>TIMER2 enable ,prescaler is=1 .
   // T2CON = 0x05;    //prescale is = 4
   // TRISCbits.TRISC5 =0;
    
}
