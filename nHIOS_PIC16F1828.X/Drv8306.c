#include "drv8306.h"

#define  DRV_ENABLE      RC7
#define  DRV_BRAKE       RC6
#define  DRV_PWM         RC5
#define  DRV_DIR           RB6
#define  DRV_FAULT        RB7 //input
#define  DRV_FGOUT       RA4 //input

my_drv8306 drv ={0,0,0,0,0,0};
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
    DRV_ENABLE=0 ;
    DRV_BRAKE = 0;
    DRV_DIR = 0;
     DRV_FAULT = 0;
     DRV_FGOUT = 0;
    DRV_PWM=0;
    
}
/******************************************
 *
 * Function Name: Drv8306_PWM()
 *Input Reference: PWM = RC5
 *
 *****************************************/
void Drv8306_PWM()
{
    TRISCbits.TRISC5=1;  //????
    PR2 = 0X9C;   //TIMER1 ???
   CCP1CON = 0x0f ; //CCPxCON, PWM module
    CCPR1L = 0x3e;    //????8?
    CCPTMRS0 = 0xFC ;  //CCP1??TIMER2 ??
    T2CON  = 0X07;     //TIMER2 ?
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


 }
 /******************************************
 *
 * Function Name: Drv8306_FAULT
 *
 *
 *****************************************/