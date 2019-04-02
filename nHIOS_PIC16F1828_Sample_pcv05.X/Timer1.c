#include "Timer1.h"


void Timer1_Init(void)
{
      PIE1bits.TMR1IE =0;//DISABLE;   // Disable Timer1 interuupt
      T1CON= 0x30 ;   //disable  Timer1 ,prescal =8  time= 4*0.125*8=4us
      PIR1bits.TMR1IF=0;  //clear Timer1 overflow interuupt flag bit
      TMR1L=0;
      TMR1H=0;

}
