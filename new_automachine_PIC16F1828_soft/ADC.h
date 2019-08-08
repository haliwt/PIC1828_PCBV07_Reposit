/* 
 * File:   HALL_ADC.h
 * Author: Administrator
 *
 * Created on December 25, 2018, 8:53 AM
 */

#ifndef __ADC_H_
#define	__ADC_H_
#include "Delay.h"

#ifdef	__cplusplus
extern "C" {
#endif
#include <xc.h>

      void  ADC_Init(void);
      ulong ADC_GetValue(void);




#ifdef	__cplusplus
}
#endif

#endif	/* HALL_ADC_H */

