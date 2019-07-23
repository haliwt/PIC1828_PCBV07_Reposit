#include "ADC.h"
#include "Delay.h"

 void  ADC_Init(void)
 {
          TRISCbits.TRISC0 = 1; //RC0
          ANSC0 = 1;
         //ADCON0=0x41;
         ADCON0bits.CHS =0b00100; //AN4 channel 
         ADCON0bits.ADON = 0b1; //ADC enable
	     //ADCON1=0x8e;
         ADCON1bits.ADFM = 0b1;
         ADCON1bits.ADCS = 0b111;
         ADCON1bits.ADNREF = 0b0;
         ADCON1bits.ADPREF = 0b10;
      
	
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
    ulong  adval,adval_l;
	float advalf;
	ADCON0bits.GO = 1;//ADGO=1;
	while(ADCON0bits.GO);
	adval= ADRESH;//00000000 00000011
    //adval_l = ADRESL;
	adval = (adval << 8) | ADRESL;//00000011 11111111
	advalf = (adval * 10000) >> 10 ; //  adval / 1024;
	adval= advalf ;
	return (adval);

 }
