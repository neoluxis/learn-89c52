#include "seg.h"
#include "delay.h"

u8 code seg_pos[] = {
    0x7f, // 0
    0xbf, // 1
    0xdf, // 2
    0xef, // 3
    0xf7, // 4
    0xfb, // 5
    0xfd, // 6
    0xfe  // 7
};

u8 code seg_num[] = {
    0x3f, // 0
    0x06, // 1
    0x5b, // 2
    0x4f, // 3
    0x66, // 4
    0x6d, // 5
    0x7d, // 6
    0x07, // 7
    0x7f, // 8
    0x6f, // 9
    0x77, // A
    0x7c, // b
    0x39, // C
    0x5e, // d
    0x79, // E
    0x71  // F
};

u8 code seg_neg_sign = 0x40;
u8 code seg_dot_sign = 0x80;

u8 seg_flag = 0;

// TODO: Rewrite with timer
void seg_init(void)
{
    wela = 0;
    dula = 0;
    SEG = 0xff;
}

// TODO: Need implementation
void seg_clear(void) {}

void seg_start(void)
{
    seg_flag = 1;
}

void seg_stop(void)
{
    seg_flag = 0;
}

void seg_display(u8 pos, u8 num)
{
    SEG = seg_pos[pos];
    wela = 1;
    wela = 0;

    SEG = seg_num[num];
    dula = 1;
    dula = 0;
    delay_centus(1);
}

void seg_customize(u8 pos, u8 cust)
{
    SEG = seg_pos[pos];
    wela = 1;
    wela = 0;

    SEG = cust;
    dula = 1;
    dula = 0;
    delay_centus(1);
}

void seg_show(u16 num, u8 full)
{
    u8 i;
    u8 buf[8];
    for (i = 0; full ? i < 8 : num > 0; i++)
    {
        buf[i] = num % 10;
        num /= 10;
    }
    for (i--; i < 8; i--)
    {
        seg_display(i, buf[i]);
    }
}

void seg_signed_show(i16 num)
{
    if (num >= 0)
    {
        seg_show(num, 0);
    }
    else
    {
        u8 i;
        u8 buf[8];
        num = -num;
        for (i = 0; num > 0; i++)
        {
            buf[i] = num % 10;
            num /= 10;
        }
        seg_customize(i, seg_neg_sign);
        for (i--; i < 8; i--)
        {
            seg_display(i, buf[i]);
        }
    }
}

void seg_hex_show(u16 num, u8 full)
{
    u8 i;
    u8 buf[8];
    for (i = 0; full ? i < 8 : num > 0; i++)
    {
        buf[i] = num % 0x10;
        num /= 0x10;
    }
    for (i--; i < 8; i--)
    {
        seg_display(i, buf[i]);
    }
}

void seg_digit_show(double num)
{
    // TODO: Implement this function
}
