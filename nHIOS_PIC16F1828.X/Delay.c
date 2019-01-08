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
         uint i= 4000 *t ;
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
        uint i= 630 *t ; // 8MHZ
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
    //OSCCON=0x72; //?????8MHZ
   // OSCCON = 0x60; //externl 8mhz
    //OSCCONbits.IRCF=0b1110;//8M?? // 400KHZ
    OSCCON = 0xe0;
}