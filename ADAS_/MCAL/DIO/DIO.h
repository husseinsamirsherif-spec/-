#ifndef DIO_H_
#define DIO_H_

#include "../../LIB/StdTypes.h"


/* Ports */
#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3


/* Pins */
#define DIO_PIN0     0
#define DIO_PIN1     1
#define DIO_PIN2     2
#define DIO_PIN3     3
#define DIO_PIN4     4
#define DIO_PIN5     5
#define DIO_PIN6     6
#define DIO_PIN7     7


/* Pin Direction */
#define DIO_INPUT    0
#define DIO_OUTPUT   1


/* Pin Value */
#define DIO_LOW      0
#define DIO_HIGH     1


/* Functions */

void DIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);

void DIO_SetPinValue(u8 Port, u8 Pin, u8 Value);

u8 DIO_GetPinValue(u8 Port, u8 Pin);

void DIO_SetPortDirection(u8 Port, u8 Direction);

void DIO_SetPortValue(u8 Port, u8 Value);

u8 DIO_GetPortValue(u8 Port);


#endif
