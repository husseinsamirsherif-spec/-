#include "Button.h"


void Button_Init(void)
{
    DIO_SetPinDirection(BUTTON_PORT, FORWARD_BUTTON, DIO_INPUT);
    DIO_SetPinDirection(BUTTON_PORT, BACKWARD_BUTTON, DIO_INPUT);
    DIO_SetPinDirection(BUTTON_PORT, LEFT_BUTTON, DIO_INPUT);
    DIO_SetPinDirection(BUTTON_PORT, RIGHT_BUTTON, DIO_INPUT);

    DIO_SetPinValue(BUTTON_PORT, FORWARD_BUTTON, DIO_HIGH);
    DIO_SetPinValue(BUTTON_PORT, BACKWARD_BUTTON, DIO_HIGH);
    DIO_SetPinValue(BUTTON_PORT, LEFT_BUTTON, DIO_HIGH);
    DIO_SetPinValue(BUTTON_PORT, RIGHT_BUTTON, DIO_HIGH);
}


u8 Button_IsPressed(u8 ButtonPin)
{
    if (DIO_GetPinValue(BUTTON_PORT, ButtonPin) == BUTTON_PRESSED)
    {
        return 1;
    }

    return 0;
}
