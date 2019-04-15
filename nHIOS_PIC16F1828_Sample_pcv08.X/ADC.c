/*
 * File:   ADC.c
 * Author: Administrator
 *
 * Created on April 11, 2019, 9:00 PM
 */

#include "ADC.h"

/********************************************
 * 
 * ADC Function: ADC GPIO Initional
 * 
 * 
 * 
*********************************************/

void ADC_Init(void)
{
    TRISCbits.TRISC0 = 1; //input ADC PORT
    ANSC0 = 1;  //analog port
    //PORTCbits.RC0 = 0; 
    
    ADCON1 =0xb0; //0xb0;  //right justified ,AD clock 8MHZ
    ADCON0 = 0x10 ; //ADC channel 4 
    ADCON0bits.ADON = 1; //start ADC model
}

/********************************************
 * 
 * ADC Conversion one times  
 * 
 * 
 * 
*********************************************/
uint ADC_Conversion_One(void)
{
    uint value=0;
    value = 0;
    ADCON0bits.CHS = 0b00100;  //select ADC of channel 4
    ADCON0bits.GO_nDONE =1; //Start ADC conversion 
    while(ADCON0bits.GO_nDONE); //wait conversion end
    
    value =(uint)ADRESH; //contain 10bit 
    
    value = value << 8;  //shift left 8 bit 
    value = value | ADRESL ;  //low 8 bit of ADRESL 
    return value ;


}
/********************************************
 * 
 * ADC Conversion more times  
 * 
 * 
 * 
*********************************************/
uint ADC_Conversion_More(void)
{
    uint ADV_MCU[ADC_NUM],ADV_CNT,ADV_ALL=0;
    ADV_ALL = 0;
    
    for(ADV_CNT =0;ADV_CNT< ADC_NUM;ADV_CNT++) //run more times ADC 
    {
        ADV_MCU[ADV_CNT]= ADC_Conversion_One();
    }
    for(ADV_CNT =0 ; ADV_CNT < ADC_NUM;ADV_CNT++)  //calculate more times ADC of mean vaule
    {
        ADV_ALL= ADV_ALL + ADV_MCU[ADV_CNT];
    
    }
    ADV_ALL = ADV_ALL / ADC_NUM;
    
    return ADV_ALL ;


}
