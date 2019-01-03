/* 
 * File:   HALL_ADC.h
 * Author: Administrator
 *
 * Created on December 25, 2018, 8:53 AM
 */

#ifndef HALL_ADC_H
#define	HALL_ADC_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <xc.h>
#define uchar unsigned char
#define uint  unsigned int
      void  Hall_AdcInit();
      uint  ADC_GetValue();




#ifdef	__cplusplus
}
#endif

#endif	/* HALL_ADC_H */

