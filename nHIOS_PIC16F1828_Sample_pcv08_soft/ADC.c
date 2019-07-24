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
         ADCON1bits.ADPREF = 0b00;//0b01;
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
     uchar i;
    ulong  adval[3]={0};
    float  adc_sum=0;
	ulong  advalf[3]={0};
	ADCON0bits.GO = 1;//ADGO=1;
    while(ADCON0bits.GO);
    {
         adval[0]= ADRESH;//00000000 00000011

         adval[0] = (adval[0] << 8) | ADRESL;//00000011 11111111
         delay_100us(1);
         advalf[0] = (adval[0] * 10000) >> 10 ; //  adval / 1024;
         delay_10us(1); 
    }
   // return (advalf[0]);

    ADCON0bits.GO = 1;//ADGO=1;
    while(ADCON0bits.GO);
    {
        adval[1]= ADRESH;//00000000 00000011

        adval[1] = (adval[1] << 8) | ADRESL;//00000011 11111111
        delay_100us(1);
        advalf[1] = (adval[1] * 10000) >> 10 ; //  adval / 1024;
        delay_10us(1);
    }
   
  // adc_sum = (advalf[0] + advalf[1]) / 2;
   //delay_10us(5);
   //return (adc_sum);

    ADCON0bits.GO = 1;//ADGO=1;
    while(ADCON0bits.GO);
    {
        adval[2]= ADRESH;//00000000 00000011

        adval[2] = (adval[2] << 8) | ADRESL;//00000011 11111111
        delay_100us(1);
        advalf[2] = (adval[2] * 10000) >> 10 ; //  adval / 1024;
        delay_10us(1);
    }
    adc_sum = (advalf[0] + advalf[1]+ advalf[2]) / 3;
    delay_10us(1);
    
    return (adc_sum);
    
#if 0   
     ADCON0bits.GO = 1;//ADGO=1;
    while(ADCON0bits.GO);
    {
        adval[3]= ADRESH;//00000000 00000011

        adval[3] = (adval[3] << 8) | ADRESL;//00000011 11111111
        delay_100us(1);
        advalf[3] = (adval[3] * 10000) >> 10 ; //  adval / 1024;
        delay_100us(1);
    }

    adc_sum = (advalf[0] + advalf[1]+ advalf[2]+advalf[3]) / 4;
    delay_100us(5);
    for(i=0;i<4;i++)
    {
        advalf[i]=0;
        adval[i]=0;
        
    
    }
    return (adc_sum);
#endif 
 #if 0
    ADCON0bits.GO = 1;//ADGO=1;
    while(ADCON0bits.GO);
    {
        adval[3]= ADRESH;//00000000 00000011

        adval[3] = (adval[3] << 8) | ADRESL;//00000011 11111111
        advalf[3] = (adval[3] * 1000) >> 10 ; //  adval / 1024;
        delay_10us(5);
    }  
    ADCON0bits.GO = 1;//ADGO=1;
    while(ADCON0bits.GO);
    {
        adval[4]= ADRESH;//00000000 00000011

        adval[4] = (adval[4] << 8) | ADRESL;//00000011 11111111
        advalf[4] = (adval[4] * 1000) >> 10 ; //  adval / 1024;
        delay_10us(5);
    }  
    
    
    adc_sum = (advalf[0] + advalf[1]+ advalf[2]+advalf[3]+advalf[4]) / 5 ;
    delay_10us(5);
    
    return (adc_sum);
   
#endif            
     
    
	

 }
