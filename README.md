# JCU RoboClub Zumo Workshop

This repository contains starter code and activities for the 3-hour Zumo Arduino Workshop.
Each folder contains a sample Arduino sketch for the corresponding activity.

## Activities
- 01_BasicMovement: Move forward, reverse, turn
- 02_ObstacleAvoidance: Detect collisions using buttons or simulated sensors
- 03_LineFollower: Follow a line using the reflectance sensor
- 04_BuzzerAndLED: Control the onboard buzzer and LED
- 05_FinalChallenge: Combine everything for a final task


## Agenda
| **Time**          | **Activity**                                                                                                                                                                    | **Purpose**                                                                 |
| ----------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------- |
| **12:00 – 12:10** | **Welcome & Intro** <br> - Overview of workshop goals <br> - What is the Zumo robot? <br> - Arduino + Shield architecture                                                       | Set context, establish motivation, connect to real-world robotics           |
| **12:10 – 12:25** | **Zumo Hardware Walkthrough** <br> (use a disassembled robot for demo) <br> - Motors & H-bridges <br> - Sensor array <br> - Power system <br> - Pin mappings (Arduino ↔ Shield) | Familiarize students with the physical components they'll be coding against |
| **12:25 – 12:45** | **Activity 1: Basic Movement** <br> - `setSpeeds()` <br> - Drive forward, back, turns <br> - Challenge: Drive in a square or figure-8                                           | Motor control, basic timing logic                                           |
| **12:45 – 1:15** | **Activity 2: Obstacle Response** <br> - Use pushbutton or simulate bumper <br> - Add reverse/turn logic on “impact”                                                            | Introduce conditional logic, inputs                                         |
| **01:15 – 01:25** | **Break**                                                                                                                                                                       | Quick rest, reset energy                                    |
| **01:25 – 01:55** | **Activity 3: Line Following** <br> - Reflectance sensor intro <br> - Calibrate sensors <br> - Follow basic track using threshold logic                                         | Sensor input, real-time feedback control                                    |
| **01:55 – 02:15** | **Activity 4: Sound & Lights** <br> - Use buzzer to play a tone <br> - Flash LED on bump or lost line                                                                           | Simple peripherals, user feedback                                           |
| **02:15 – 02:50** | **Final Challenge: Race or Maze** <br> - Combine movement + sensors <br> - Race around a taped loop or navigate a basic arena                                                   | Integration of all concepts under time pressure                             |
| **02:50 – 03:00** | **Wrap-Up & Q\&A** <br> - Encourage follow-up projects <br> - Show how to extend Zumo (e.g., Bluetooth, remote control)                                                         | Solidify takeaways, gather feedback                                         |

## Welcome & Intro
- Overview of workshop goals
- What is the Zumo robot?
- Arduino + Shield architecture

### Download ZumoSheild Library for Arduino IDE
If you are using version 1.6.2 or later of the Arduino software (IDE), you can use the Library Manager to install this library:

1. In the Arduino IDE, open the "Sketch" menu, select "Include Library" then "Manage Libraries...".
2. Search for "ZumoShield".
3. Click the ZumoShield entry in the list.
4. Click "Install".

[ZumoSheild Documentation](https://pololu.github.io/zumo-shield-arduino-library/index.html)

[Pololu Zumo Shield for Arduino User’s Guide](https://www.pololu.com/docs/pdf/0j57/zumo_shield_for_arduino.pdf)



## Zumo Hardware Walkthrough

### Motors & H-bridges

### Sensor array

### Power system

### Pin mappings (Arduino ↔ Shield)


## Activity 1: Basic Movement
### Using `ZumoMotor` Class
```arduino
#include <Wire.h>
#include <ZumoShield.h>

ZumoMotors motors; 
```

### Moving the motors with `setSpeeds()`
The motor speed can be set using the `setSpeed()` method of the ZumoMotors class.
```arduino
motor.setSpeeds(int leftSpeed, int rightSpeed);
```
The Speed values can be between -400(Full Backwards) and 400(Full Forward).

Each motor can also be individually set

```arduino
motors.setLeftSpeed(int speed);
motors.setRightSpeed(int speed);
```
if you notice that your Zumos directions are wrone i.e. -400 moves forward use the flipmotor methods.
```arduino
motors.flipLeftMotor(boolean flip);
motors.flipRightMotor(boolean flip);
```
### Activity 1: Let's Get Driving 
Have a play around with the contol of the motors. you can use the `delay(uint seconds)` function to add a wait between turning on an off your motors

### Challenge: Drive in a square
Write a sketch to drive your Zumo in a square.

## Activity 2: Obstacle Course
- Use pushbutton or simulate bumper
- Add reverse/turn logic on “impact”

## Activity 3: Line Following
### Reflectance sensor intro
![Reflectance Sensor Image](https://shop.pimoroni.com/cdn/shop/products/0J4207.1200_768x768_crop_center.jpg?v=1548858770)
The reflectance sensor array on the Zumo robot is used to detect lines and surface contrast, making it ideal for line-following tasks.

It works by using infrared (IR) LEDs paired with phototransistors. Each sensor emits IR light onto the surface beneath the robot. The amount of light reflected back depends on the surface:

- White or light surfaces reflect more IR light
- Black or dark surfaces absorb light, reflecting less

Each sensor measures how much IR light is reflected, giving an analog value that tells how dark or light the surface is under that sensor.

By reading multiple sensors at once, the robot can "see" where the line is and adjust its movement to follow it.
### Calibrate sensors


### Follow basic track using threshold logic

## Activity 4: Sound & Lights
- Use buzzer to play a tone
- Flash LED on bump or lost line

## Final Challenge: Race or Maze
- Combine movement + sensors
- Race around a taped loop or navigate a basic arena

## Wrap-Up & Q&A
- Encourage follow-up projects
- Show how to extend Zumo (e.g., Bluetooth, remote control)