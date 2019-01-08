/* 
 * File:   Drv8306.h
 * Author: Administrator
 *
 * Created on December 25, 2018, 11:22 AM
 */

#ifndef DRV8306_H
#define	DRV8306_H
#include "delay.h"
#define  DRV_ENABLE      RC7
#define  DRV_BRAKE       RC6
#define  DRV_PWM         RC5
#define  DRV_DIR           RB6
#define  DRV_FAULT        RB7 //input
#define  DRV_FGOUT       RA4 //input

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct
{
    uchar drv_enable ;
    uchar drv_brake ;
    uchar drv_dir ;
    uchar  drv_fault ;  //input
    uchar  drv_fgout;    //input Capture
    uint   drv_pwm;   //uint model
}my_drv8306;
    void Drv8306_Init();
    void Drv8306_PWM();
    void Drv8306_FGOUT();    //DRV8306_FGOUT
    void Drv8306_FAULT();





#ifdef	__cplusplus
}
#endif

#endif	/* DRV8306_H */

