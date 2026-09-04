#include "Motor.h"


void Motor_Init(void)
{
    DIO_SetPinDirection(MOTOR_PORT, RIGHT_MOTORS_IN1, DIO_OUTPUT);

    DIO_SetPinDirection(MOTOR_PORT, RIGHT_MOTORS_IN2, DIO_OUTPUT);

    DIO_SetPinDirection(MOTOR_PORT, LEFT_MOTORS_IN1, DIO_OUTPUT);

    DIO_SetPinDirection(MOTOR_PORT, LEFT_MOTORS_IN2, DIO_OUTPUT);

    Motor_Stop();
}


void Motor_Forward(void)
{
	DIO_SetPinValue(MOTOR_PORT, RIGHT_MOTORS_IN1, DIO_HIGH);

    DIO_SetPinValue(MOTOR_PORT, RIGHT_MOTORS_IN2, DIO_LOW);

    DIO_SetPinValue(MOTOR_PORT, LEFT_MOTORS_IN1, DIO_HIGH);

    DIO_SetPinValue(MOTOR_PORT, LEFT_MOTORS_IN2, DIO_LOW);
}



void Motor_Backward(void)
{

    DIO_SetPinValue(MOTOR_PORT, RIGHT_MOTORS_IN1, DIO_LOW);

    DIO_SetPinValue(MOTOR_PORT, RIGHT_MOTORS_IN2, DIO_HIGH);

    DIO_SetPinValue(MOTOR_PORT, LEFT_MOTORS_IN1, DIO_LOW);

    DIO_SetPinValue(MOTOR_PORT, LEFT_MOTORS_IN2, DIO_HIGH);


}

void Motor_Left(void)
{
	DIO_SetPinValue(MOTOR_PORT, RIGHT_MOTORS_IN1, DIO_HIGH);

    DIO_SetPinValue(MOTOR_PORT, RIGHT_MOTORS_IN2, DIO_LOW);

    DIO_SetPinValue(MOTOR_PORT, LEFT_MOTORS_IN1, DIO_LOW);

    DIO_SetPinValue(MOTOR_PORT, LEFT_MOTORS_IN2, DIO_LOW);


}


void Motor_Right(void)
{
    DIO_SetPinValue(MOTOR_PORT, LEFT_MOTORS_IN1, DIO_HIGH);

    DIO_SetPinValue(MOTOR_PORT, LEFT_MOTORS_IN2, DIO_LOW);

    DIO_SetPinValue(MOTOR_PORT, RIGHT_MOTORS_IN1, DIO_LOW);

    DIO_SetPinValue(MOTOR_PORT, RIGHT_MOTORS_IN2, DIO_LOW);
}


void Motor_Stop(void)
{
    DIO_SetPinValue(MOTOR_PORT, RIGHT_MOTORS_IN1, DIO_LOW);

    DIO_SetPinValue(MOTOR_PORT, RIGHT_MOTORS_IN2, DIO_LOW);

    DIO_SetPinValue(MOTOR_PORT, LEFT_MOTORS_IN1, DIO_LOW);

    DIO_SetPinValue(MOTOR_PORT, LEFT_MOTORS_IN2, DIO_LOW);

}
