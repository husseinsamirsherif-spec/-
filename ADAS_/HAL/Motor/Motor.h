#ifndef MOTOR_H_
#define MOTOR_H_

#include "../../MCAL/DIO/DIO.h"

#define MOTOR_PORT              DIO_PORTB

#define LEFT_MOTORS_IN1         DIO_PIN0
#define LEFT_MOTORS_IN2         DIO_PIN1

#define RIGHT_MOTORS_IN1        DIO_PIN2
#define RIGHT_MOTORS_IN2        DIO_PIN3


void Motor_Init(void);

void Motor_Forward(void);

void Motor_Backward(void);

void Motor_Left(void);

void Motor_Right(void);

void Motor_Stop(void);


#endif
