/* 
 * File:   MachineLearing.h
 * Author: Administrator
 *
 * Created on February 26, 2019, 8:24 PM
 */

#ifndef MACHINELEARING_H
#define	MACHINELEARING_H
#include "Delay.h"

extern uchar data[4]={0,0,0,0};
typedef struct machine 
{
   uchar machine_swtich : 1 ;
   

}MACHINE ;
MACHINE my_machine ;

uchar Machine_M_Learning(void);   //output signal
uchar Machine_N_Learning(void);   //output signal

void Average_First(uchar size,uchar address);

void  convertDecimalToHexa(ulong number);
void Average_Second(uchar size_n,uchar address);




#ifdef	__cplusplus
}
#endif

#endif	/* MACHINELEARING_H */

