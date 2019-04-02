#ifndef DELAY_H
#define	DELAY_H
#include <xc.h>
//#include <pic16f1828.h>
#include <stdio.h>
#include <stdlib.h>
#define uchar       unsigned char   /*8bit 0~ 255*/
#define uint        unsigned int       /*16bit 0 ~ 65535*/
#define ushort      unsigned short   /*16bit*/
#define ulong       unsigned long    /* 32bit */
#define ulonglong   unsigned long long   /* 32bit */
#ifdef	__cplusplus
extern "C" {
#endif
 void delay_100us(uint t);
 void delay_1ms(uint t);
 void delay_10ms(uint t);
 void init_fosc(void);


#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */

