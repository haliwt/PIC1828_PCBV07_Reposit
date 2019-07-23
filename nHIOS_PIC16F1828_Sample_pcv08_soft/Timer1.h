#ifndef __TIMER1_H__
#define	__TIMER1_H__
#include "Delay.h"

#define TMR1_Counter_Enable             T1CONbits.TMR1ON
#define TMR1_Counter_Overflow_Flag      PIR1bits.TMR1IF


void Timer1_Init(void);

#endif	/* TIMER1_H */

