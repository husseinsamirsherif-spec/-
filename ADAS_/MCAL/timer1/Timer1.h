#ifndef TIMER1_H_
#define TIMER1_H_

#include "../../LIB/StdTypes.h"


#define TIMER1_FALLING_EDGE    0
#define TIMER1_RISING_EDGE     1


void Timer1_Init(void);

void Timer1_Reset(void);

void Timer1_SetCaptureEdge(u8 Edge);

u8 Timer1_CaptureOccurred(void);

void Timer1_ClearCaptureFlag(void);

u16 Timer1_GetCaptureValue(void);

u8 Timer1_OverflowOccurred(void);

void Timer1_ClearOverflowFlag(void);


#endif
