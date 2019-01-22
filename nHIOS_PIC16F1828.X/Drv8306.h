/* 
 * File:   Drv8306.h
 * Author: Administrator
 *
 * Created on December 25, 2018, 11:22 AM
 */

#ifndef DRV8306_H
#define	DRV8306_H
#include "delay.h"
#define  DRV_ENABLE      PORTCbits.RC7
#define  DRV_BRAKE       PORTCbits.RC6
#define  DRV_PWM         PORTCbits.RC5
#define  DRV_DIR           PORTBbits.RB6
#define  DRV_FAULT        PORTBbits.RB7 //input
#define  DRV_FGOUT       PORTAbits.RA4 //input

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct
{
    volatile uchar drv_enable  ;
    volatile uchar  drv_brake ;
    volatile uchar drv_dir;
    volatile uchar key_press_start ;
    uchar  drv_fault :1 ;  //input
    uchar  drv_fgout;    //input Capture
    uint   drv_pwm;   //uint model
}my_drv8306;
my_drv8306 my_drv;
    void Drv8306_Init();
    void Drv8306_PWM();
    void Drv8306_FGOUT();    //DRV8306_FGOUT
  //  void Drv8306_FAULT();





#ifdef	__cplusplus
}
#endif

#endif	/* DRV8306_H */

