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
#define  DRV_BRAKE        PORTCbits.RC4 //PCB_V08
#define  DRV_PWM          PORTCbits.RC5
#define  DETECT_BRAKE     PORTCbits.RC0 //input 1
//#define  CPU_CAPTURE      PORTCbits.RC4   // caputre PWM signal

//volatile ulong pwm_duty=0 ;

enum drv{DISABLE , ENABLE};
#ifdef	__cplusplus
extern "C" {
#endif

typedef struct DRV8306
{
    uchar drv_enable  ;
    uchar drv_brake ;
    uchar drv_dir ;
    
   
}my_drv8306;

struct DRV8306   my_drv={0,0,0};

    void Drv8306_Init(void);
    void Drv8306_PWM(void);
    void Drv8306_FGOUT_Capture(void);    //DRV8306_FGOUT
    void Drv8306_FAULT_Init(void);  //Drv8603 is fault signal






#ifdef	__cplusplus
}
#endif

#endif	/* DRV8306_H */

