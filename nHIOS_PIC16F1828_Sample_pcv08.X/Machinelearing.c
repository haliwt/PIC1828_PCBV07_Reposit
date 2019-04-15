#include "MachineLearing.h"
#include "Eeprom.h"

/***********************************************************
   *
   *Function :Machine_Learning_Output_SIG_Init()
   *Effect : output fsult signal to Auto equipment
   *Input reference:no
   *Output referncece: no
   *
 **********************************************************/
 uchar Machine_M_Learning(void )
 {
     uint sum_m=0;
     
	
	 	
	  sum_m  =(EEPROM_Read_OneByte(0xb5)+ EEPROM_Read_OneByte(0xb6)
		         	+EEPROM_Read_OneByte(0xb7)) / 3 ;
	 	

	
	 return sum_m ;
	
	 
 }
 /***********************************************************
	*
	*Function :Machine Learning of data
	*Effect : output fsult signal to Auto equipment
	*Input reference:no
	*Output referncece: no
	*
************************************************************/
 uchar Machine_N_Learning(void )
 {
     
   uint  sum_n=0;
	
      sum_n = (EEPROM_Read_OneByte(0x53)+ EEPROM_Read_OneByte(0x54)
	  	      + EEPROM_Read_OneByte(0x55))/ 3;

	
    return sum_n;
	
	 
 }
/***********************************************************
	*
	*Function :Machine_Learning_Output_SIG_Init()
	*Effect : output fsult signal to Auto equipment
	*Input reference: arrary of EE
	*Output referncece: no
	*
	*
**********************************************************/
void Average_First(uchar size_m,uchar addr)
	  {
		  uchar sample_sm[79];
		  sample_sm[0]=0;
		  uchar i;
		  ulong sum=0,aver = 0;
		//	uchar m = sizeof(sample_sm) / sizeof(sample_sm[0]);
		  
		
			 
		  if(size_m ==80)
		  {
				  for(i=0;i<80;i++)
				  {
				   sample_sm[i] = EEPROM_Read_OneByte(i+100);
				   sum = sum+ sample_sm[i];
				  }
			  
				   convertDecimalToHexa(sum);
				   aver = sum / 80;
				   delay_100us(5);
				   TXREG = aver;
				   delay_100us(5);
	 
				   EEPROM_Write_OneByte(addr, aver); //save sample of arrive 80
				   
		  
		  }
		
		 
	 }
		 

 
 
 
 
 /***********************************************************
	 *
	 *Function : the second caulation average 
	 *Effect : 
	 *Input reference:
	 *Output referncece: average_second data
	 *
	 *
**********************************************************/
	 void Average_Second(uchar size_n,uchar addr)
	 {
		  uchar sample_sn[79];
		  sample_sn[0]= 0;
		  uchar i;
		  ulong sum=0,aver=0;
	   //	uchar n = sizeof(sample_sn) / sizeof(sample_sn[0]);
		 
		   if(size_n == 80)
		   {
			   for(i=0;i<80;i++)
				 {
				   sample_sn[i] = EEPROM_Read_OneByte(i);
				   sum = sum+ sample_sn[i];
				 }
			  
				 convertDecimalToHexa(sum);
				 aver = sum /80;
				 delay_100us(5);
				 TXREG = aver;
				 delay_100us(5);
				 
			   EEPROM_Write_OneByte(addr, aver);
			  
		   }
		 
	 }


 
 /********************************************************
   *
   *Function Name: void convertDecimalToHexa(ulong decimalNumber)
   *Fuction Active : 10 to 16 
   *Input Reference : decimalNumber
   *
 *********************************************************/
 
 void  convertDecimalToHexa(uint number)
  {
	 uchar i,index =0 ;
	 ulong x = number;
	 uchar data[4]={0,0,0,0};
	 while(x>0)
	 {
		 data[index] = x%16; // get hexadecimal is remainder
		 delay_100us(5);
		 x = x/16;			 //get consult
		 delay_100us(5);
		 index = index +1;
	 }
	 
	 //queue hexadecimal output sequence
	   
		 delay_100us(5);
		TXREG = data[3];
		 delay_100us(5);
		TXREG = data[2];
		delay_100us(5);
		TXREG = data[1];
		delay_100us(5);
		TXREG = data[0];
		delay_100us(5);
	   
 }
  

