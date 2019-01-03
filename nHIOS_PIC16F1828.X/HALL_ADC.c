#include "HALL_ADC.h"
#include "Delay.h"

 void  Hall_AdcInit()
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
 uint  ADC_GetValue()
 {
        ulong  adval;
	float advalf;
	ADGO=1;
	while(ADGO);
	adval=ADRESH;//00000000 00000011
	adval=adval<<8|ADRESL;//00000011 11111111
	advalf=adval/1023.0*5.0;//==2.3843
	adval=advalf*1000;
	return (adval);

 }
