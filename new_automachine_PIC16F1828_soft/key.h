#ifndef KEY_H
#define	KEY_H
#include "Delay.h"
#ifdef	__cplusplus
extern "C" {
#endif

#define Key_Start               PORTAbits.RA0  //PORTAbits.RA0
#define Key_Dir                 PORTCbits.RC1//PORTAbits.RA1 //KEY_Press physical
//#define Key_New_Dir             PORTCbits.RC1 //KEY_Press physical
//#define Key_Access            PORTBbits.RB4  //output
#define Key_MachineL            PORTCbits.RC2  //machine learnign switch 
#define  DRV_DIR                PORTCbits.RC3// PCB_V06
    
    
    
enum key {start=1, dir };

void Key_Init(void);
uchar GetKeyPad(void);
uchar Manual_Operation_Dir(void);

uchar MachineLearning_Key(void);



#ifdef	__cplusplus
}
#endif

#endif	/* KEY_H */

