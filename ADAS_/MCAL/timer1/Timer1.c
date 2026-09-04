#include "Timer1.h"
#include "../../LIB/BitMath.h"
#include <avr/io.h>


void Timer1_Init(void)
{
    /* Normal Mode */
    TCCR1A = 0x00;
    TCCR1B = 0x00;

    /* Start counter from zero */
    TCNT1 = 0;

    /* Clear old flags */
    TIFR = (1 << ICF1) | (1 << TOV1);

    /* Capture Rising Edge first */
    SET_BIT(TCCR1B, ICES1);

    /* Prescaler = 8 */
    SET_BIT(TCCR1B, CS11);
}


void Timer1_Reset(void)
{
    TCNT1 = 0;
}


void Timer1_SetCaptureEdge(u8 Edge)
{
    if (Edge == TIMER1_RISING_EDGE)
    {
        SET_BIT(TCCR1B, ICES1);
    }
    else
    {
        CLR_BIT(TCCR1B, ICES1);
    }
}


u8 Timer1_CaptureOccurred(void)
{
    return GET_BIT(TIFR, ICF1);
}


void Timer1_ClearCaptureFlag(void)
{
    TIFR = (1 << ICF1);
}


u16 Timer1_GetCaptureValue(void)
{
    return ICR1;
}


u8 Timer1_OverflowOccurred(void)
{
    return GET_BIT(TIFR, TOV1);
}


void Timer1_ClearOverflowFlag(void)
{
    TIFR = (1 << TOV1);
}
