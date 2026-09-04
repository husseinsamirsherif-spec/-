#include "Ultrasonic.h"
#include <util/delay.h>


void Ultrasonic_Init(void)
{
    DIO_SetPinDirection(
        ULTRASONIC_TRIG_PORT,
        ULTRASONIC_TRIG_PIN,
        DIO_OUTPUT
    );

    DIO_SetPinDirection(
        ULTRASONIC_ECHO_PORT,
        ULTRASONIC_ECHO_PIN,
        DIO_INPUT
    );

    DIO_SetPinValue(
        ULTRASONIC_TRIG_PORT,
        ULTRASONIC_TRIG_PIN,
        DIO_LOW
    );

    Timer1_Init();
}


u16 Ultrasonic_GetDistance(void)
{
    u16 StartTime;
    u16 EndTime;
    u16 PulseTime;
    u16 Distance;


    Timer1_SetCaptureEdge(TIMER1_RISING_EDGE);

    Timer1_ClearCaptureFlag();
    Timer1_ClearOverflowFlag();

    Timer1_Reset();



    DIO_SetPinValue(
        ULTRASONIC_TRIG_PORT,
        ULTRASONIC_TRIG_PIN,
        DIO_LOW
    );

    _delay_us(2);

    DIO_SetPinValue(
        ULTRASONIC_TRIG_PORT,
        ULTRASONIC_TRIG_PIN,
        DIO_HIGH
    );

    _delay_us(10);

    DIO_SetPinValue(
        ULTRASONIC_TRIG_PORT,
        ULTRASONIC_TRIG_PIN,
        DIO_LOW
    );


    while (Timer1_CaptureOccurred() == 0)
    {
        if (Timer1_OverflowOccurred())
        {
            Timer1_ClearOverflowFlag();

            return 0;
        }
    }


    StartTime = Timer1_GetCaptureValue();


    Timer1_SetCaptureEdge(TIMER1_FALLING_EDGE);

    Timer1_ClearCaptureFlag();


    while (Timer1_CaptureOccurred() == 0)
    {
        if (Timer1_OverflowOccurred())
        {
            Timer1_ClearOverflowFlag();

            return 0;
        }
    }


    EndTime = Timer1_GetCaptureValue();


    if (EndTime >= StartTime)
    {
        PulseTime = EndTime - StartTime;
    }
    else
    {
        PulseTime = (65535 - StartTime) + EndTime + 1;
    }


    Distance = PulseTime / 58;


    return Distance;
}
