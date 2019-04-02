#ifndef  __OUTPUT_SIG_H__
#define	__OUTPUT_SIG_H__

#include "Delay.h"

#define Auto_OutPut_Brake               PORTBbits.RB6//Version 05 of PC PORTBbits.RB5  //auto equipment output brake signal
#define Machine_Works_Fail              PORTBbits.RB4  //auto equipment output fsult signal


#ifdef	__cplusplus
extern "C" {
#endif

   void Brake_OutPut_SIG_Init(void);   //output signal
   void Output_SIG_Init(void);  //output signal
   void Machine_Learning_Arithmetic(ulong numbers);   //output signal


#ifdef	__cplusplus
}
#endif

#endif	/* OUTPUT_SIG_H */

