#include "delay.h"

/***************************************************************************
 *
 * Function Name:delay_1ms()
 * Function function:
 * input regerence :
 *
 *************************************************************************/
    void delay_1ms(uint t)
    {
         uint i= 63 *t ;
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
    void delay_10ms(ulong t)
    {
        uint i= 630 *t ; // 8MHZ//uint i= 1260 *t ;//16mhz
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

    OSCCON= 0xe2; //8M

   // OSCCON = 0xFA;  //internal OSCS is 16MHZ
}