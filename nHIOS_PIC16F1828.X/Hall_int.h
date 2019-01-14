/* 
 * File:   Hall_int.h
 * Author: Administrator
 *
 * Created on December 25, 2018, 11:25 AM
 */

#ifndef HALL_INT_H
#define	HALL_INT_H
#include "delay.h"

#ifdef	__cplusplus
extern "C" {
#endif
#define HALL_SENSOR  PORTAbits.RA0

    void HALL_INTInit();




#ifdef	__cplusplus
}
#endif

#endif	/* HALL_INT_H */

