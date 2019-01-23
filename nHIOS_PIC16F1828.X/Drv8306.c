#include "drv8306.h"


//my_drv8306 drv ={0,0,0,0,0,0};
/******************************************
 *
 * Function Name: Drv8306_Init()
 * Function : Inition
 *
 *****************************************/
void Drv8306_Init()
{
    TRISCbits.TRISC7 =0 ; //DRV_ENABLE output
    TRISCbits.TRISC6 = 0;  //DRV_BRAKE output
    TRISCbits.TRISC0 = 1;  //DETECT_BRAKE input
    TRISBbits.TRISB6 = 0 ;  //DRV_DIR  output
    TRISBbits.TRISB7 = 1 ; //DRV_FAULT input
    TRISAbits.TRISA4 = 1; //DRV_FGOUT input
    PORTC = 0xC1;
  
  
    
}
/******************************************
 *
 * Function Name: Drv8306_PWM()
 *Input Reference: PWM = RC5,??100KHZ??
 *
 *****************************************/
void Drv8306_PWM()
{

    TRISCbits.TRISC5=1;  //PWM CCP1,OSC =8MHZ
    PR2 =0x4;     //Timer2 period Register
   //CCP1CON = 0x3C ; //CCPxCON, PWM module
    CCPR1L = 0x02;    //MSB 8bit<>pulse duty of value
    CCP1CON = 0X0c; //LSB has 2 bits in <5:4>
    CCPTMRS0 =0xFC ;  //PWM timer selectiong control RE :Enable PWM
//    //T2CON  = 0X07;     //TIMER2 of TIMER2,prescaler is 64
    T2CON = 0x04;    //TxCON <>TIMER2 enable ,prescaler is=1 .
    //TRISCbits.TRISC5 =0;
    

}
/******************************************
 *
 * Function Name: Drv8306_Capture
 *
 *
 *****************************************/
void Drv8306_FGOUT()
{
   


}
/******************************************
 *
 * Function Name: Drv8306_FAULT
 *
 *
 *****************************************/
