#ifndef BUZZER_H_
#define BUZZER_H_

#include "../../MCAL/DIO/DIO.h"

#define BUZZER_PORT    DIO_PORTC
#define BUZZER_PIN     DIO_PIN6

void Buzzer_Init(void);
void Buzzer_On(void);
void Buzzer_Off(void);

#endif
