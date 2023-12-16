#include "delay.h"

u32 cus = 0; // 100 us

void (*sleep)(u16) = delay_ms;

void delay_centus(u16 centus)
{
  cus = 0;
  TR0 = 1;
  while (cus < centus)
    ;
  TR0 = 0;
}

void delay_ms(u16 ms)
{
  cus = 0;
  TR0 = 1;
  while (cus < ms * 10)
    ;
  TR0 = 0;
}

void delay_init(void)
{
  TMOD |= 0x02;
  TH0 = 255 - 89;
  TL0 = 255 - 89;
  ET0 = 1;
  EA = 1;
}

void timer0_int(void) interrupt 1
{
  TH0 = 255 - 89;
  TL0 = 255 - 89;
  cus++;
}
