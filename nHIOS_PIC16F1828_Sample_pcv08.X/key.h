#ifndef KEY_H
#define	KEY_H
#include "Delay.h"
#ifdef	__cplusplus
extern "C" {
#endif

#define Key_Start               PORTAbits.RA0  //PORTAbits.RA0
#define Key_Dir                 PORTCbits.RC1//PORTAbits.RA1 //KEY_Press physical
#define Key_MachineL            PORTCbits.RC2  //machine learnign switch 
#define  DRV_DIR                PORTCbits.RC3// PCB_V06
    
    
    
enum key {start=1, dir };
struct flag_key 
{
  uchar flag_dir;
  uchar flag_run;
  uchar flag_stop;
  uchar flag_brake;

};

struct flag_key myflag_key={2,2,2,2};

void Key_Init(void);
uchar GetKeyPad(void);
uchar Manual_Operation_Dir(void);

uchar MachineLearning_Key(void);



#ifdef	__cplusplus
}
#endif

#endif	/* KEY_H */

