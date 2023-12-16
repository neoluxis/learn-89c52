#ifndef __LED_H
#define __LED_H

#include "main.h"

sbit LED0 = P1 ^ 0;
sbit LED1 = P1 ^ 1;
sbit LED2 = P1 ^ 2;
sbit LED3 = P1 ^ 3;
sbit LED4 = P1 ^ 4;
sbit LED5 = P1 ^ 5;
sbit LED6 = P1 ^ 6;
sbit LED7 = P1 ^ 7;

#define LED P1

#define LED_ON 0
#define LED_OFF 1

/**
 * @brief set all led off
 *
 */
extern void led_init(void);
extern void led_on(u8 ledx);
extern void led_off(u8 ledx);
extern void led_toggle(u8 ledx);

#endif // !__LED_H
