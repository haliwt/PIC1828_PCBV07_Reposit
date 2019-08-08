#include "Timer1.h"



void Timer1_Init(void)
{
	  PIE1bits.TMR1IE =0;//DISABLE;   // Disable Timer1 interuupt
      PIE1bits.TMR1GIE =0;
      PIE1bits.ADIE =0;
      
      PIR1bits.TMR1IF = 0b0; //
      
      T1CONbits.TMR1CS = 0b00 ;  //select Timer1 clock = Fosc/4 
      T1CONbits.T1CKPS = 0b11 ;  //Timer1 prescal =1:8, T= 4/8mhz(OSC), time= 4*0.125*8=4us,
      T1CONbits.T1OSCEN = 0b0;  //disable osc
      //T1CONbits.nT1SYNC = 0b1;  //disable synchronize extern clock input 
      T1CONbits.TMR1ON = 0b0;    //stop timer1 
      //TMR1_Counter_Enable = 0;  //stop timer1
      TMR1L=0;
      TMR1H=0;

}
