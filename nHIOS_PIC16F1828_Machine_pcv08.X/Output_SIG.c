#include "Output_SIG.h"
/***********************************************************
   *
   *Function :Output_SIG_Init()
   *Effect : output break signal to auto equipment
   *Input reference :no
   *Output reference :no
   *
 **********************************************************/
void Output_SIG_Init(void)
{
      TRISBbits.TRISB6 =0;  //IO  -output fault signal
      
       Auto_OutPut_Brake = 0; //PORTBbits.RB6 =0;   //output error signal
      
      TRISBbits.TRISB4 = 0;
	  ANSB4 =0;
     
      
     
      Auto_Works_Signal = 0;
}

 
