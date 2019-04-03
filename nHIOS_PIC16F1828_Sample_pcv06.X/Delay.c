#include "Delay.h"
/**************************************
  *
  *
  *
 **************************************/
void delay_100us(uint t)
{
     uint i= 6*t ;
      while(i --)
        {
          ;
        }

}
/***************************************************************************
 *
 * Function Name:delay_1ms()
 * Function function:
 * input regerence :
 *
 *************************************************************************/
void delay_1ms(uint tim)  //8MHZ OSC
{
     ulong i= 25*tim ;
      while(i --)
        {
          ;
        }
    
}

  /***************************************************************************
 *
 * Function Name:delay_10ms()
 * Function function:
 * input regerence :
 *
 *************************************************************************/
    void delay_10ms(uint t)
    {
        uint i= 626 *t ; // 8MHZ osc
        while(i --)
        {
          ;
        }

    }
/***************************************************************************
 *
 * Function Name:
 * Function function:Oscilation selection
 * input regerence :
 *
 *************************************************************************/
void init_fosc(void)
{
   // PLLR = 0;  // OSCSTAT : 0  = 4 x PLL is not ready
    HFIOFR = 1 ;  //OSCSTAT:  1 = HFINTOSC is ready

    OSCCON= 0xe2; //8Mhz OSCS

   // OSCCON = 0xFA;  //internal OSCS is 16MHZ
}