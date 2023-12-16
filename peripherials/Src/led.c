#include "led.h"

void led_init(void)
{
    LED = 0xff;
}

void led_on(u8 ledx)
{
	switch(ledx){
    case 0:
      LED0 = LED_ON;
      break;
    case 1:
      LED1 = LED_ON;
      break;
    case 2:
      LED2 = LED_ON;
      break;
    case 3:
      LED3 = LED_ON;
      break;
    case 4:
      LED4 = LED_ON;
      break;
    case 5:
      LED5 = LED_ON;
      break;
    case 6:
      LED6 = LED_ON;
      break;
    case 7:
      LED7 = LED_ON;
      break;
  }
}

void led_off(u8 ledx)
{
	switch(ledx){
    case 0:
      LED0 = LED_OFF;
      break;
    case 1:
      LED1 = LED_OFF;
      break;
    case 2:
      LED2 = LED_OFF;
      break;
    case 3:
      LED3 = LED_OFF;
      break;
    case 4:
      LED4 = LED_OFF;
      break;
    case 5:
      LED5 = LED_OFF;
      break;
    case 6:
      LED6 = LED_OFF;
      break;
    case 7:
      LED7 = LED_OFF;
      break;
  }
}

void led_toggle(u8 ledx)
{
	switch(ledx){
    case 0:
      LED0 = !LED0;
      break;
    case 1:
      LED1 = !LED1;
      break;
    case 2:
      LED2 = !LED2;
      break;
    case 3:
      LED3 = !LED3;
      break;
    case 4:
      LED4 = !LED4;
      break;
    case 5:
      LED5 = !LED5;
      break;
    case 6:
      LED6 = !LED6;
      break;
    case 7:
      LED7 = !LED7;
      break;
  }
}
