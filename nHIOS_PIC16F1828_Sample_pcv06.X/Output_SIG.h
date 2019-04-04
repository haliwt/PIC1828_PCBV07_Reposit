#ifndef  __OUTPUT_SIG_H__
#define	__OUTPUT_SIG_H__

#include "Delay.h"

#define Auto_OutPut_Brake           PORTBbits.RB6//Version 05 of PC PORTBbits.RB5  //auto equipment output brake signal
#define Auto_OutPut_Fail            PORTBbits.RB4  //auto equipment output fsult signal


#ifdef	__cplusplus
extern "C" {
#endif

  
void Output_SIG_Init(void);  //output signal
  


#ifdef	__cplusplus
}
#endif

#endif	/* OUTPUT_SIG_H */

