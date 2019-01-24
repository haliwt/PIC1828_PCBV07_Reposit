#ifndef KEY_H
#define	KEY_H
#include "Delay.h"
#ifdef	__cplusplus
extern "C" {
#endif

#define Key_Start   PORTAbits.RA0  //PORTAbits.RA0
#define Key_Dir    PORTAbits.RA1  //interrupter
#define Key_Access PORTBbits.RB4  //output

enum key {start=1, dir };

void Key_Init(void);
uchar GetKeyPad(void);
void Manual_Operation_Dir(void);



#ifdef	__cplusplus
}
#endif

#endif	/* KEY_H */

