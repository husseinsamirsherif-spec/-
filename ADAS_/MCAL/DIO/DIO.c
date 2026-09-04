#include "DIO.h"
#include "../../LIB/BitMath.h"
#include <avr/io.h>


void DIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction)
{
    switch (Port)
    {
        case DIO_PORTA:
            if (Direction == DIO_OUTPUT)
                SET_BIT(DDRA, Pin);
            else
                CLR_BIT(DDRA, Pin);
            break;

        case DIO_PORTB:
            if (Direction == DIO_OUTPUT)
                SET_BIT(DDRB, Pin);
            else
                CLR_BIT(DDRB, Pin);
            break;

        case DIO_PORTC:
            if (Direction == DIO_OUTPUT)
                SET_BIT(DDRC, Pin);
            else
                CLR_BIT(DDRC, Pin);
            break;

        case DIO_PORTD:
            if (Direction == DIO_OUTPUT)
                SET_BIT(DDRD, Pin);
            else
                CLR_BIT(DDRD, Pin);
            break;
    }
}


void DIO_SetPinValue(u8 Port, u8 Pin, u8 Value)
{
    switch (Port)
    {
        case DIO_PORTA:
            if (Value == DIO_HIGH)
                SET_BIT(PORTA, Pin);
            else
                CLR_BIT(PORTA, Pin);
            break;

        case DIO_PORTB:
            if (Value == DIO_HIGH)
                SET_BIT(PORTB, Pin);
            else
                CLR_BIT(PORTB, Pin);
            break;

        case DIO_PORTC:
            if (Value == DIO_HIGH)
                SET_BIT(PORTC, Pin);
            else
                CLR_BIT(PORTC, Pin);
            break;

        case DIO_PORTD:
            if (Value == DIO_HIGH)
                SET_BIT(PORTD, Pin);
            else
                CLR_BIT(PORTD, Pin);
            break;
    }
}


u8 DIO_GetPinValue(u8 Port, u8 Pin)
{
    u8 Value = 0;

    switch (Port)
    {
        case DIO_PORTA:
            Value = GET_BIT(PINA, Pin);
            break;

        case DIO_PORTB:
            Value = GET_BIT(PINB, Pin);
            break;

        case DIO_PORTC:
            Value = GET_BIT(PINC, Pin);
            break;

        case DIO_PORTD:
            Value = GET_BIT(PIND, Pin);
            break;
    }

    return Value;
}


void DIO_SetPortDirection(u8 Port, u8 Direction)
{
    switch (Port)
    {
        case DIO_PORTA:
            DDRA = Direction;
            break;

        case DIO_PORTB:
            DDRB = Direction;
            break;

        case DIO_PORTC:
            DDRC = Direction;
            break;

        case DIO_PORTD:
            DDRD = Direction;
            break;
    }
}


void DIO_SetPortValue(u8 Port, u8 Value)
{
    switch (Port)
    {
        case DIO_PORTA:
            PORTA = Value;
            break;

        case DIO_PORTB:
            PORTB = Value;
            break;

        case DIO_PORTC:
            PORTC = Value;
            break;

        case DIO_PORTD:
            PORTD = Value;
            break;
    }
}


u8 DIO_GetPortValue(u8 Port)
{
    u8 Value = 0;

    switch (Port)
    {
        case DIO_PORTA:
            Value = PINA;
            break;

        case DIO_PORTB:
            Value = PINB;
            break;

        case DIO_PORTC:
            Value = PINC;
            break;

        case DIO_PORTD:
            Value = PIND;
            break;
    }

    return Value;
}




