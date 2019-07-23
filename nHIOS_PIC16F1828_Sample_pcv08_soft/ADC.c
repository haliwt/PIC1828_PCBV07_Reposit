#include "ADC.h"
#include "Delay.h"

 void  ADC_Init(void)
 {
         TRISA=0x01;
         PORTA=0;
         ADCON0=0x41;
	 ADCON1=0x8e;
      
	delay_10ms(1);
  }

  /***************************************************************************
 *
 * Function Name:hall_adc_get_value()
 * Function function:
 * input regerence :
 *
 ****************************************************************************/
 ulong  ADC_GetValue(void)
 {
    ulong  adval;
	float advalf;
	ADGO=1;
	while(ADGO);
	adval=ADRESH;//00000000 00000011
	adval=adval<<8|ADRESL;//00000011 11111111
	advalf= ((adval * 1000)/1023.0 );//==2.3843
	adval=advalf;
	return (adval);

 }
