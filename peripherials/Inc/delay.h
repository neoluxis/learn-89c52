#ifndef __DELAY_H
#define __DELAY_H

#include "main.h"

/**
 * @brief cus: 100us counter
 *
 */
extern u32 cus;

/**
 * @brief sleep function pointer, by default delay_ms()
 *
 */
extern void (*sleep)(u16);

/**
 * @brief 100us delay
 *
 */
extern void delay_init(void);

/**
 * @brief delay n 100us
 *
 * @param centus number of 100us(es)
 */
extern void delay_centus(u16 centus);

/**
 * @brief ms delay
 *
 * @param ms number of ms(es)
 */
extern void delay_ms(u16 ms);

#endif // !__DELAY_H