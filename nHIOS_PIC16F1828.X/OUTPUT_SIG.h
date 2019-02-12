#include "delay.h"
#ifndef  OUTPUT_SIG_H
#define	OUTPUT_SIG_H

#define AutoOutPutBrake    PORTBbits.RB5  //auto equipment output brake signal
#define Auto_OutPut_Fsult     PORTBbits.RB4  //auto equipment output fsult signal

#ifdef	__cplusplus
extern "C" {
#endif

   void Brake_OutPut_SIG_Init();   //output signal
   void Works_SIG_Init();  //output signal
   void Fsult_OutPut_SIG_Init();   //output signal


#ifdef	__cplusplus
}
#endif

#endif	/* OUTPUT_SIG_H */

