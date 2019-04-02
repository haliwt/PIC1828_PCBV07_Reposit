/* 
 * File:   RS232.h
 * Author: Administrator
 *
 * Created on February 23, 2019, 4:31 PM
 */

#ifndef __RS232_H__
#define	__RS232_H__
#include "Delay.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define RXD   PORTBbits.RB5
#define TXD   PORTBbits.RB7

void USART_Init(void);
  
#ifdef	__cplusplus
}
#endif

#endif	/* RS232_H */

