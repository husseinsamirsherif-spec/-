#include "LCD.h"
#include <util/delay.h>


static void LCD_SendNibble(u8 Nibble)
{
    DIO_SetPinValue(LCD_PORT, LCD_D4_PIN, (Nibble >> 0) & 1);
    DIO_SetPinValue(LCD_PORT, LCD_D5_PIN, (Nibble >> 1) & 1);
    DIO_SetPinValue(LCD_PORT, LCD_D6_PIN, (Nibble >> 2) & 1);
    DIO_SetPinValue(LCD_PORT, LCD_D7_PIN, (Nibble >> 3) & 1);

    DIO_SetPinValue(LCD_PORT, LCD_E_PIN, DIO_HIGH);
    _delay_us(1);

    DIO_SetPinValue(LCD_PORT, LCD_E_PIN, DIO_LOW);
    _delay_us(100);
}


void LCD_Init(void)
{
    DIO_SetPinDirection(LCD_PORT, LCD_RS_PIN, DIO_OUTPUT);
    DIO_SetPinDirection(LCD_PORT, LCD_E_PIN, DIO_OUTPUT);

    DIO_SetPinDirection(LCD_PORT, LCD_D4_PIN, DIO_OUTPUT);
    DIO_SetPinDirection(LCD_PORT, LCD_D5_PIN, DIO_OUTPUT);
    DIO_SetPinDirection(LCD_PORT, LCD_D6_PIN, DIO_OUTPUT);
    DIO_SetPinDirection(LCD_PORT, LCD_D7_PIN, DIO_OUTPUT);

    _delay_ms(40);

    DIO_SetPinValue(LCD_PORT, LCD_RS_PIN, DIO_LOW);

    LCD_SendNibble(0x03);
    _delay_ms(5);

    LCD_SendNibble(0x03);
    _delay_us(150);

    LCD_SendNibble(0x03);

    LCD_SendNibble(0x02);

    LCD_SendCommand(0x28);
    LCD_SendCommand(0x0C);
    LCD_SendCommand(0x06);
    LCD_SendCommand(0x01);

    _delay_ms(2);
}


void LCD_SendCommand(u8 Command)
{
    DIO_SetPinValue(LCD_PORT, LCD_RS_PIN, DIO_LOW);

    LCD_SendNibble(Command >> 4);
    LCD_SendNibble(Command & 0x0F);
}


void LCD_WriteChar(u8 Character)
{
    DIO_SetPinValue(LCD_PORT, LCD_RS_PIN, DIO_HIGH);

    LCD_SendNibble(Character >> 4);
    LCD_SendNibble(Character & 0x0F);
}


void LCD_WriteString(const char *String)
{
    while (*String != '\0')
    {
        LCD_WriteChar(*String);
        String++;
    }
}


void LCD_Clear(void)
{
    LCD_SendCommand(0x01);
    _delay_ms(2);
}


void LCD_SetCursor(u8 Row, u8 Column)
{
    if (Row == 0)
    {
        LCD_SendCommand(0x80 + Column);
    }
    else
    {
        LCD_SendCommand(0xC0 + Column);
    }
}
