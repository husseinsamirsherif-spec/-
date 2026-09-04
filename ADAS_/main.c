#include "HAL/Motor/Motor.h"
#include "HAL/Button/Button.h"
#include "HAL/Buzzer/Buzzer.h"
#include "HAL/LCD/LCD.h"
#include "HAL/Ultrasonic/Ultrasonic.h"

#include <util/delay.h>


int main(void)
{
    u16 Distance;



    Motor_Init();
    Button_Init();
    Buzzer_Init();
    LCD_Init();
    Ultrasonic_Init();


    Motor_Stop();
    Buzzer_Off();


    while (1)
    {
        Distance = Ultrasonic_GetDistance();



        if (Distance < 20)
        {


            Motor_Stop();

            Buzzer_On();


            LCD_SetCursor(0, 0);
            LCD_WriteString("UNSAFE WAY      ");


            LCD_SetCursor(1, 0);
            LCD_WriteString("STOP            ");
        }



        else
        {
            Buzzer_Off();


            LCD_SetCursor(0, 0);
            LCD_WriteString("SAFE WAY        ");


            if (Button_IsPressed(FORWARD_BUTTON))
            {
                Motor_Forward();

                LCD_SetCursor(1, 0);
                LCD_WriteString("FORWARD         ");
            }


            else if (Button_IsPressed(BACKWARD_BUTTON))
            {
                Motor_Backward();

                LCD_SetCursor(1, 0);
                LCD_WriteString("BACK            ");
            }


            else if (Button_IsPressed(LEFT_BUTTON))
            {
                Motor_Left();

                LCD_SetCursor(1, 0);
                LCD_WriteString("LEFT            ");
            }


            else if (Button_IsPressed(RIGHT_BUTTON))
            {
                Motor_Right();

                LCD_SetCursor(1, 0);
                LCD_WriteString("RIGHT           ");
            }


            else
            {
                Motor_Stop();



                LCD_SetCursor(1, 0);
                LCD_WriteString("                ");
            }
        }


        _delay_ms(60);
    }


    return 0;
}
