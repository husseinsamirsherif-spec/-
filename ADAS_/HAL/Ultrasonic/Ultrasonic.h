#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/timer1/Timer1.h"


#define ULTRASONIC_TRIG_PORT      DIO_PORTC
#define ULTRASONIC_TRIG_PIN       DIO_PIN0

#define ULTRASONIC_ECHO_PORT      DIO_PORTD
#define ULTRASONIC_ECHO_PIN       DIO_PIN6


void Ultrasonic_Init(void);

u16 Ultrasonic_GetDistance(void);


#endif
