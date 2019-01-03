/* 
 * File:   Delay.h
 * Author: Administrator
 *
 * Created on December 25, 2018, 8:56 AM
 */

#ifndef DELAY_H
#define	DELAY_H
//#include <xc.h>
#include <pic16f1828.h>
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#ifdef	__cplusplus
extern "C" {
#endif

 void delay_1ms(uint t);
 void delay_10ms(uint t);
 void init_fosc(void);


#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */

