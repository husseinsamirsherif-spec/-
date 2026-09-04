# Advanced Driver Assistance System (ADAS)

A simple ADAS-based robot car project using the ATmega32 microcontroller.

## Project Overview

The car is controlled using four push buttons:

- Forward
- Backward
- Left
- Right

An HC-SR04 ultrasonic sensor continuously measures the distance in front of the car.

If an obstacle is detected at a distance less than 20 cm:

- The motors stop automatically.
- The buzzer turns ON.
- The LCD displays `UNSAFE WAY` and `STOP`.
- Movement buttons are ignored.

If the distance is 20 cm or more:

- The buzzer turns OFF.
- The LCD displays `SAFE WAY`.
- The user can control the car movement.

## Hardware

- ATmega32 Microcontroller
- L298 Motor Driver
- 4 DC Motors
- HC-SR04 Ultrasonic Sensor
- 16x2 LCD
- Buzzer
- 4 Push Buttons

## Software Architecture

The project is divided into layers:

### MCAL
- DIO Driver
- Timer1 Driver

### HAL
- Motor Driver
- Button Driver
- Buzzer Driver
- LCD Driver
- Ultrasonic Driver

### Application
- main.c

## Ultrasonic Measurement

The HC-SR04 ECHO pin is connected to the Timer1 Input Capture pin (ICP1 / PD6).

Timer1 runs at 1 MHz, so:

1 Timer Tick = 1 microsecond

Distance is calculated using:

Distance (cm) = Echo Pulse Time / 58

## Safety Condition

Distance < 20 cm → UNSAFE
Distance >= 20 cm → SAFE

## Project Demo
[▶ Watch the Proteus Simulation](media/adas-demo.mp4?raw=1)
















