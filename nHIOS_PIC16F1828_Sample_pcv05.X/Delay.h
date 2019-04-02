#ifndef __DELAY_H_
#define	__DELAY_H_
#include <xc.h>
//#include <pic16f1828.h>
#include <stdio.h>
#include <stdlib.h>
#define uchar unsigned char   /*0~ 255*/
#define uint unsigned int       /*0 ~ 65535*/
#define ulong unsigned long    /* 32bit */
#define ulonglong unsigned long long   /* 32bit */
#ifdef	__cplusplus
extern "C" {
#endif
 void delay_100us(uint t);
 void delay_1ms(uint t);
 void delay_10ms(ulong t);
 void init_fosc(void);


#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */

