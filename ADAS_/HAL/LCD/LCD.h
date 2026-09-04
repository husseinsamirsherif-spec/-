#ifndef LCD_H_
#define LCD_H_

#include "../../MCAL/DIO/DIO.h"

#define LCD_PORT       DIO_PORTA

#define LCD_RS_PIN     DIO_PIN0
#define LCD_E_PIN      DIO_PIN1

#define LCD_D4_PIN     DIO_PIN2
#define LCD_D5_PIN     DIO_PIN3
#define LCD_D6_PIN     DIO_PIN4
#define LCD_D7_PIN     DIO_PIN5


void LCD_Init(void);

void LCD_SendCommand(u8 Command);

void LCD_WriteChar(u8 Character);

void LCD_WriteString(const char *String);

void LCD_Clear(void);

void LCD_SetCursor(u8 Row, u8 Column);


#endif
