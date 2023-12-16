#include "tim.h"

/**
 * @brief Get the Th Tl value to initialize a timer
 *
 * @param timx The timer to initialize
 * @return u8* The Th Tl array {TH, TL}
 */
u8 *getThTl(TimerInitStruct *timx)
{
    // TODO: Implement this function
    return timx->load;
}

void tim_init(TimerInitStruct *timx)
{
    switch (timx->timx)
    {
    case 0:
        TMOD |= timx->mode;
        ET0 = timx->exti;
        // TODO: Finish timer0
        break;
    // TODO: Implement timer1
    default:
        break;
    }
}

void __tim_start(TimerInitStruct *timx)
{
    switch (timx->timx)
    {
    case 0:
        TR0 = 1;
        break;
    case 1:
        TR1 = 1;
        break;
    default:
        break;
    }
}

void __tim_stop(TimerInitStruct *timx)
{
    switch (timx->timx)
    {
    case 0:
        TR0 = 0;
        break;
    case 1:
        TR1 = 0;
        break;
    default:
        break;
    }
}

void __tim_exti_ena(TimerInitStruct *timx)
{
    switch (timx->timx)
    {
    case 0:
        ET0 = 1;
        break;
    case 1:
        ET1 = 1;
        break;
    default:
        break;
    }
}

void __tim_exti_dis(TimerInitStruct *timx)
{
    switch (timx->timx)
    {
    case 0:
        ET0 = 0;
        break;
    case 1:
        ET1 = 0;
        break;
    default:
        break;
    }
}

// TODO: Optimize these functions for timers
