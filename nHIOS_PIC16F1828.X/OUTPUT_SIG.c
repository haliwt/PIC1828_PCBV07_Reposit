#include "output_sig.h"
/***********************************************************
   *
   *Function :Brake_Output_SIG_Init()
   *Effect : output break signal to auto equipment
   *Input reference :no
   *Output reference :no
   *
 **********************************************************/
void Brake_OutPut_SIG_Init()
{
      TRISBbits.TRISB5 =0; //RB5 -output brake
      PORTBbits.RB5 =0;  //output low level
}
 /***********************************************************
   *
   *Function :Fsult_OutPut_SIG_Init()
   *Effect : output fsult signal to Auto equipment
   *Input reference:no
   *Output referncece: no
   *
 **********************************************************/
 void Fsult_OutPut_SIG_Init()
 {
     TRISBbits.TRISB4 =0;
     PORTBbits.RB4 =0;
 }
  /***********************************************************
   *
   *Function :
   *Effect : output fail signal to Auto equipment
   *         that screw don't tightening
   *
 **********************************************************/
