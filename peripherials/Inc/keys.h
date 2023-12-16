#ifndef __KEYS_H__
#define __KEYS_H__

#include "main.h"

sbit K1 = P3 ^ 0;
sbit K2 = P3 ^ 1;
sbit K3 = P3 ^ 2;
sbit K4 = P3 ^ 3;
sbit MATRIX_KEY = P3;

/**
 * @brief scan independent key
 *
 * @param mode 0: no continue, 1: continue
 * @return u8 key value, 0: no key, 1: K1, 2: K2, 3: K3, 4: K4
 */
extern u8 key_scan(u8 mode);

/**
 * @brief scan matrix key
 *
 * @param mode 0: no continue, 1: continue
 * @return u8 key value, 0: no key, 0x10-0x1f: K1-K16
 */
extern u8 matrix_key_scan(u8 mode);

/**
 * @brief scan all keys (independent key and matrix key)
 *
 * @param mode 0: no continue, 1: continue
 * @param pri 0: independent key first, 1: matrix key first
 * @return u8 key value, 0: no key, 1-4: K1-K4 independent keys; 0x10-0x1f: K1-K16 in matrix key
 */
extern u8 all_key_scan(u8 mode, u8 pri);

#endif // !__
