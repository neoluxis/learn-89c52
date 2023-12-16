#ifndef __TIM_H
#define __TIM_H

#include "main.h"

/**
 * @brief A structure to initialize a timer
 *
 * @param timx The timer to initialize, x: 0 for timer0, 1 for timer1
 * @param period The period of the timer
 * @param mode The mode of the timer, 1 for 16-bit non-autoreload, 2 for 8 bit autoreload
 * @param exti Whether to enable the timer interrupt
 * @param load The Th Tl value to initialize the timer. Needn't to be set bacause a function was written
 * @param callback The callback function to call when the timer interrupt is triggered. Valid only if exti is 1
 *
 */
typedef struct TimerInitStruct
{
  u8 timx;
  u16 period;
  u8 mode;
  u8 exti;
  u8 load[2];
  void (*callback)(void);
} TimerInitStruct;

/**
 * @brief Initializes a timer
 *
 * @param timx The timer to initialize
 */
extern void tim_init(TimerInitStruct *timx);

/**
 * @brief Starts a timer
 *
 * @param timx The timer to start
 */
extern void __tim_start(TimerInitStruct *timx);

/**
 * @brief Stops a timer
 *
 * @param timx The timer to stop
 */
extern void __tim_stop(TimerInitStruct *timx);

/**
 * @brief Enables the timer interrupt
 *
 * @param timx The timer to enable the interrupt
 */
extern void __tim_exti_ena(TimerInitStruct *timx);

/**
 * @brief Disables the timer interrupt
 *
 * @param timx The timer to disable the interrupt
 */
extern void __tim_exti_dis(TimerInitStruct *timx);

#endif