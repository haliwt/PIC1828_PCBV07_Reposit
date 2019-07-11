#ifndef __EEPROM_H
#define	__EEPROM_H



void EEPROM_Write_OneByte(unsigned char addr, unsigned char value);
unsigned char   EEPROM_Read_OneByte(unsigned char  addr);
void EEPROM_Read_StringByte(unsigned char inAddr, unsigned char *ptaddrout, unsigned char datalog);
void EEPROM_Write_StringByte(unsigned char inAddr, unsigned char *ptaddrout, unsigned char datalog);




#endif	/* EEPROM_H */

