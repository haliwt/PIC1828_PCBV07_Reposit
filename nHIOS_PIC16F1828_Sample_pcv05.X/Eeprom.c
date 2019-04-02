#include "Eeprom.h"
#include "Delay.h"

/*************************************************
 * 
 * Function Active: to read one byte form eeprom
 *                   of address
 * 
 ***************************************************/
uchar  EEPROM_Read_OneByte(uchar addr)
{
    uchar num;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS =0 ;
    while(EECON1bits.WR ==1);
    EEADRL = addr;
    EECON1bits.RD = 1;
    while(EECON1bits.RD ==1);
    num = EEDATA;
    return num ;
}

/*************************************************
 *
 * Function Active: to write one byte form eeprom
 *                   of address
 *
 ***************************************************/
void EEPROM_Write_OneByte(unsigned char addr, unsigned char data)
{
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS =0 ;

    while(EECON1bits.WR ==1);  //wait complete
    EEADRL = addr;    //write address of value
    EEDATA = data ;   //write data

     EECON1bits.EEPGD = 0;
    EECON1bits.CFGS =0 ;
    EECON1bits.WREN =1;
    EECON2 = 0x55;
    EECON2 = 0xaa;
    EECON1bits.WR = 1;

    while(EECON1bits.WR==1) ;//to wait for complete
    EECON1bits.WREN = 0;  //disable write data

 }

/**************************************************************
 *
 * Function Active: To read continuance   form eeprom
 *                   of address
 * 入口参数：所读数据的首地址 读得的数据的存放首地址 读数据 长度
 *出口参数：所读地址的数据
 *
 **************************************************************/
void EEPROM_Read_StringByte(uchar inAddr, uchar *outAddr, uchar datalog)
{
    uchar i;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS =0 ;
    for(i=datalog; i>0 ;i --)
    {
        while(EECON1bits.RD ==1); //wait read over
        EEADRL  = inAddr ;  //write to input of address ;
        EECON1bits.RD =1  ;  //
        while(EECON1bits.RD ==1); //wait read complete
        *outAddr = EEDATA;   //EEPROM of data register

        inAddr ++ ;  //save of address add 1
        outAddr ++  ;  //data of address add 1

    }
}
/**************************************************************
 *
 * Function Active: To write continuance   form eeprom
 *                   of address
 *
 *Input Refenerce: inAddr -intput of address ,InData -input data
 *                 DataLong --input data length
 *
 **************************************************************/
 void EEPROM_Write_StringByte(uchar inAddr, uchar *InData, uchar DataLong)
{
    uchar i,j ;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS =0 ;

    for(i=DataLong ;i > 0; i--)
    {
        while(EECON1bits.WR ==1); //wait for write complete
        EEADRL = inAddr;  // write to input of address
        EEDATA = *InData;  //write input of data
        EECON1bits.WREN =1;  // Enable write to eeprom of data
        EECON2 = 0x55;  //write definite of data
        EECON2 = 0xaa ;
        EECON1bits.WR =1;
        while(EECON1bits.WR ==1); //wait for complete to write
        EECON1bits.WREN =0;
   }

}