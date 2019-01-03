#include "drv8306.h"

#define  DRV_ENABLE      RC7
#define  DRV_BRAKE       RC6
#define  DRV_PWM         RC5
#define  DRV_DIR           RB6
#define  DRV_FAULT        RB7 //input
#define  DRV_FGOUT       RA4 //input

my_drv8306 *pdrv ;
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
    pdrv->drv_enable = DRV_ENABLE ;
    DRV_BRAKE = 0;
    pdrv->drv_brake= DRV_BRAKE ;
    DRV_DIR = 0;
    pdrv->drv_dir= DRV_DIR ;
     DRV_FAULT = 0;
    pdrv->drv_fault = DRV_FAULT ;
    DRV_FGOUT = 0;
    pdrv->drv_fgout = DRV_FGOUT ;
    DRV_PWM=0;
    pdrv->drv_pwm = DRV_PWM ;
}
/******************************************
 *
 * Function Name: Drv8306_PWM()
 *
 *
 *****************************************/
void Drv8306_PWM()
{
    CCPR1L = 0x32;    //
    CCP1CON = 0x0c ; //CCPxCON, PWM module
    TRISC5 = 0 ; //CCP1 

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