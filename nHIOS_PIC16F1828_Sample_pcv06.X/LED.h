/* 
 * File:   LED.h
 * Author: Administrator
 *
 * Created on December 25, 2018, 1:37 PM
 */

#ifndef LED_H
#define	LED_H
#include "Delay.h"
#ifdef	__cplusplus
extern "C" {
#endif
//#define LED1  PORTCbits.RC1
#define LED2  //PORTCbits.RC2 // in stead of Machine switch
#define LED3 // PORTCbits.RC3
 void  Led_Init();



#ifdef	__cplusplus
}
#endif

#endif	/* LED_H */

