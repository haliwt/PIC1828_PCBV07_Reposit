/* 
 * File:   Drv8306.h
 * Author: Administrator
 *
 * Created on December 25, 2018, 11:22 AM
 */

#ifndef DRV8306_H
#define	DRV8306_H
#include "delay.h"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct
{
    uchar drv_enable : 1;
    uchar drv_brake : 1;
    uchar drv_dir : 1;
    uchar  drv_fault : 1;  //input
    uchar  drv_fgout;    //input Capture
    uint   drv_pwm;   //uint model
}my_drv8306;
    void Drv8306_Init();
    void Drv8306_PWM();
    void Drv8306_FGOUT(); //DRV8306_FGOUT
    void Drv8306_FAULT();





#ifdef	__cplusplus
}
#endif

#endif	/* DRV8306_H */

