#include "RS232.h"
#if 0
void USART_Init(void)
{
  ANSELBbits.ANSB5 = 0;        //cloase analog data
  TRISBbits.TRISB5= 1;                 //RXD
  APFCON0bits.RXDTSEL = 0;   //select RB5 is RXD of pin function
  APFCON0bits.TXCKSEL = 0;   // select RB7 is TXD of pin function
  TRISBbits.TRISB7 = 0;           //IO input TXD
  SPBRG =0x0c;                  //baud rate 9600 bit/s,Fosc = 8MHz

  TXSTA=0X24 ;           //TXD Register
  RCSTA=0X90;           //RXD Register

 //RSCTA regedister
 //BAUDCON = 0X01;
 // RCIE=0X1;              // Enable USART interrupt
//  PEIE=0X1;
//  TXIE = 1;
//  RCIE =1; //
//  GIE=0X1;
}
#endif
