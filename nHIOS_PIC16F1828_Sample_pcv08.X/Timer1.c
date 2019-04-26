#include "Timer1.h"



void Timer1_Init(void)
{
	  PIE1bits.TMR1IE =0;//DISABLE;   // Disable Timer1 interuupt
      T1CON= 0x30 ;   //Timer1 counter time = 4us ,prescal =8, T= 4/8mhz(OSC), time= 4*0.125*8=4us,
      PIR1bits.TMR1IF=0;  //clear Timer1 overflow interuupt flag bit
      TMR1_Counter_Enable = 0;  //stop counter number
      TMR1L=0;
      TMR1H=0;

}
