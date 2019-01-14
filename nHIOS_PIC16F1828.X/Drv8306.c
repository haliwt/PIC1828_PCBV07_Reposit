#include "drv8306.h"


//my_drv8306 drv ={0,0,0,0,0,0};
/******************************************
 *
 * Function Name: Drv8306_Init()
 *
 *
 *****************************************/
void Drv8306_Init()
{
    TRISC = 0X00; //Drv
    TRISB = 0x80;
    TRISA = 0x10;
   // PORTB= 0X40;
   
    
    
}
/******************************************
 *
 * Function Name: Drv8306_PWM()
 *Input Reference: PWM = RC5,??100KHZ??
 *
 *****************************************/
void Drv8306_PWM()
{

    TRISCbits.TRISC5=1;  //PWM CCP1,OSC =16MHZ
    PR2 =0x15;     //Timer2 period Register
   //CCP1CON = 0x3C ; //CCPxCON, PWM module
     CCPR1L = 0x0f;    //pulse duty of value
    CCP1CON = 0X0C; //LSB has 2 bits,<5:4>selcet PMW module,Load duty cycle
    CCPTMRS0 = 0xFC ;  //PWM timer selectiong control RE :Enable PWM
    //T2CON  = 0X07;     //TIMER2 of TIMER2,prescaler is 64
    T2CON = 0x04;    //TIMER2 enable ,prescaler is=1 .
    TRISCbits.TRISC5 =0;
    

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
 void Drv8306_FAULT()
 {
    TRISBbits.TRISB7 =1;
     RB7=0;
 }
 