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
 *Input Reference: NO   PR2 = 0X06  CCPR1L = 0x07 is best
 *Output Reference:NO
 *
 *****************************************/
void Drv8306_PWM(void)
{

    TRISCbits.TRISC5=1;  //PWM CCP1,OSC =8MHZ
    PR2 = 0x0d;//PR2 =0x0d ;//0x06//mass PR2 = 0X06;//0x05//0x04     //Timer2 period Register,f =100Khz
    CCPR1L = 0x00;    //MSB 8bit<>pulse duty of value
    CCP1CON = 0x0d ;//LSB has 2 bits in <5:4>
    CCPTMRS0 = 0;//0xFC ;  //PWM timer selectiong control RE :Enable PWM
   // T2CON = 0x04;    //TXCON <>TIMER2 enable ,prescaler is=1 .
   // T2CONbits.T2CKPS = 0b00 ;  //prescaler = 1 
    T2CONbits.T2CKPS = 0b01 ;    //presaler = 4
    T2CONbits.TMR2ON = 0b1;
    
}


