#ifndef __SEG_H
#define __SEG_H

#include "main.h"

#define SEG P0
sbit wela = P2 ^ 7; // 74HC138
sbit dula = P2 ^ 6; // 74HC138

/**
 * @brief Value of each position
 *
 */
extern u8 code seg_pos[8];

/**
 * @brief Value of each number (0~F)
 *
 */
extern u8 code seg_num[16];

/**
 * @brief Value of negative sign
 *
 */
extern u8 code seg_neg_sign;

/**
 * @brief Value of dot sign (to be or-ed with the number)
 *
 */
extern u8 code seg_dot_sign;

extern u8 seg_flag;

/**
 * @brief Initialize 8-segment display
 *
 */
extern void seg_init(void);

/**
 * @brief clear 8-segment display
 *
 */
extern void seg_clear(void);

/**
 * @brief Show a number on a position
 *
 * @param pos The position of the number
 * @param num The number to be shown
 */
extern void seg_display(u8 pos, u8 num);

/**
 * @brief To show a customized value on a position
 *
 * @param pos The position of the shown
 * @param cust The customized value to be shown
 */
extern void seg_customize(u8 pos, u8 cust);

/**
 * @brief Show a number (A positive integer within 8 digits)
 *
 * @param num The number to be shown
 * @param full 0: show only the digits of the number, 1: show all 8 digits (fill with 0)
 */
extern void seg_show(u16 num, u8 full);

/**
 * @brief Show a signed number (positive integer within 8 digits or negative integer within 7 digits)
 *
 * @param num The number to be shown
 */
extern void seg_signed_show(i16 num);

/**
 * @brief Show a hex number (within 8 digits)
 *
 * @param num The hex number to be shown
 */
extern void seg_hex_show(u16 num, u8 full);

/**
 * @brief Show a double number (within 8 digits). The integeral part is shown on the left 4 digits, and the decimal part within 8 digits 
 * and digital part will be shown on the 4 digits left. Final digit rounded. 
 *
 * @param num The double number to be shown
 */
extern void seg_digit_show(double num);

#endif // !__SEG_H