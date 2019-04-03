/* 
 * File:   Drv8306.h
 * Author: Administrator
 *
 * Created on December 25, 2018, 11:22 AM
 */

#ifndef DRV8306_H
#define	DRV8306_H
#include "Delay.h"

#define  DRV_ENABLE       PORTAbits.RA4// PCB_V06
//#define  DRV_BRAKE       
#define  DRV_PWM          PORTCbits.RC5

#define  DETECT_BRAKE     PORTCbits.RC0 //input 1

//volatile ulong pwm_duty=0 ;

enum drv{DISABLE , ENABLE};
#ifdef	__cplusplus
extern "C" {
#endif

typedef struct
{
    uchar drv_enable :1  ;
    uchar drv_brake: 1 ;
    uchar drv_dir:1 ;
    uchar key_press_start :1 ;
    uchar  drv_fault :1 ;  //input
    uchar  drv_fgout;    //input Capture
    uint    drv_pwm;   //uint model
}my_drv8306;
my_drv8306 my_drv;

    void Drv8306_Init(void);
    void Drv8306_PWM(void);
    void Drv8306_FGOUT_Init(void);    //DRV8306_FGOUT
    void Drv8306_FAULT_Init(void);  //Drv8603 is fault signal






#ifdef	__cplusplus
}
#endif

#endif	/* DRV8306_H */

