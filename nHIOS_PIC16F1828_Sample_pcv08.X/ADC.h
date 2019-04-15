
// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __ADC_H
#define	__ADC_H
#include "Delay.h"


#define ADC_ON  ADCON0bits.ADON  //



#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */


#define ADC_NUM  8 //adc conversion number 

void ADC_Init(void);

uint ADC_Conversion_One(void);

uint ADC_Conversion_More(void);



#endif	/* XC_HEADER_TEMPLATE_H */

