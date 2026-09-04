#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/DIO.h"

#define BUTTON_PORT          DIO_PORTD

#define FORWARD_BUTTON       DIO_PIN0
#define BACKWARD_BUTTON      DIO_PIN1
#define LEFT_BUTTON          DIO_PIN2
#define RIGHT_BUTTON         DIO_PIN3

#define BUTTON_PRESSED       DIO_LOW
#define BUTTON_NOT_PRESSED   DIO_HIGH


void Button_Init(void);

u8 Button_IsPressed(u8 ButtonPin);


#endif
