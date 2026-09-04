#include "Buzzer.h"


void Buzzer_Init(void)
{
    DIO_SetPinDirection(BUZZER_PORT, BUZZER_PIN, DIO_OUTPUT);

    Buzzer_Off();
}


void Buzzer_On(void)
{
    DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_HIGH);
}


void Buzzer_Off(void)
{
    DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_LOW);
}
