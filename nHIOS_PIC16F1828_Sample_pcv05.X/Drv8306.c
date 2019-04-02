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
   //TRISCbits.TRISC7 =0 ; //DRV_ENABLE output
    ANSC7=0; //Digital I/O ,1= analog
    TRISCbits.TRISC6 = 0;  //DRV_BRAKE output
    TRISCbits.TRISC4 = 0 ;

    ANSC6 =0;

	
    //DRV_BRAKE = 0;

	
    TRISBbits.TRISB7 = 0 ; //DRV_NEW_DIR  output

    PORTBbits.RB7=0;      //


    TRISBbits.TRISB4 = 0;  //DRV_ENABLE IO OUTPUT
    ANSB4 =0 ;
 

    TRISAbits.TRISA4 = 0; //New DRV8306_ENABLE 2019-03-14
    ANSA4 =0;
	PORTBbits.RB4=0;
	DRV_DIR = 0;
   
  
  
    
}
/******************************************
 *
 * Function Name: Drv8306_PWM()
 * Function Active: output OSC 8Mhz
 *Input Reference: NO
 *Output Reference:NO
 *
 *****************************************/
void Drv8306_PWM(void)
{

    TRISCbits.TRISC5=1;  //PWM CCP1,OSC =8MHZ
    PR2 =0x05;     //Timer2 period Register
   //CCP1CON = 0x3C ; //CCPxCON, PWM module
    CCPR1L = 0x05;    //MSB 8bit<>pulse duty of value
    CCP1CON = 0x2c;//0X0c; //LSB has 2 bits in <5:4>
    CCPTMRS0 =0x3c;//0xFC ;  //PWM timer selectiong control RE :Enable PWM
    //T2CON  = 0X07;     //TIMER2 of TIMER2,prescaler is 64
    T2CON = 0x04;    //TXCON <>TIMER2 enable ,prescaler is=1 .
   // T2CON = 0x05;    //prescale is = 4
    //TRISCbits.TRISC5 =0;
    
}
/******************************************
 *
 * Function Name: Drv8306_Capture
 * Input Reference :NO
 * Output Reference: NO
 *
 *****************************************/
#if 0
void Drv8306_FGOUT_Init()
{
    TRISAbits.TRISA4=1; //define to I/O input

}
#endif
