#ifndef __BEEPER_H__
#define __BEEPER_H__

#include "main.h"

sbit beeper = P2 ^ 3;

extern void beeper_on();
extern void beeper_off();

#endif // !__
