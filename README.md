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
![Zumo Shield Image](https://littlebirdelectronics.com.au/cdn/shop/products/image_5f49cb58-7ae4-4f33-a623-96606832f563_1224x1224.jpg?v=1698749682)
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
Have a play around with the contol of the motors. you can use the `delay(uint milliseconds)` function to add a wait between turning on an off your motors

### Challenge: Drive in a square
Write a sketch to drive your Zumo in a square.

## Activity 2: Obstacle Course
### Use pushbutton or simulate bumper
Zumo doesn’t have built-in mechanical bumpers, but we can simulate a collision using the onboard pushbutton to trigger an action like reversing or turning — just like if it hit an obstacle.\
We will need to include Pushbutton.h
```arduino
#include <ZumoMotors.h>
#include <Pushbutton.h>

ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON); // onboard pushbutton
```
To check if the button is pressed
```arduino 
if (button.isPressed()) {
  // Do Action
}
```
Lets start off by writing some code were the zumo will stop if the button is pushed (it is in a collision).

### Add reverse/turn logic on “impact”

```arduino
void loop() {
  // Check if button is pressed (simulated collision)
  if (button.isPressed()) {
    // Simulate "collision response"
    motors.setSpeeds(-150, -150); // reverse
    delay(500);
    motors.setSpeeds(-100, 100);  // spin turn
    delay(400);
  } else {
    // Drive forward
    motors.setSpeeds(150, 150);
  }
}
```

## Activity 3: Line Following
### Reflectance sensor intro
![Reflectance Sensor Image](https://shop.pimoroni.com/cdn/shop/products/0J4207.1200_768x768_crop_center.jpg?v=1548858770)\
The reflectance sensor array on the Zumo robot is used to detect lines and surface contrast, making it ideal for line-following tasks.

It works by using infrared (IR) LEDs paired with phototransistors. Each sensor emits IR light onto the surface beneath the robot. The amount of light reflected back depends on the surface:

- White or light surfaces reflect more IR light
- Black or dark surfaces absorb light, reflecting less

Each sensor measures how much IR light is reflected, giving an analog value that tells how dark or light the surface is under that sensor. By reading multiple sensors at once, the robot can "see" where the line is and adjust its movement to follow it.

### Calibrate sensors
The sensor array is represented in code by a 6 value array, with each value being a measurement of each sensors analog level
Calibration helps the robot learn the difference between light and dark surfaces. It does this by taking multiple readings as you move it over both white and black areas. This allows it to set a reliable range for line detection.

```arduino
#include <ZumoReflectanceSensorArray.h>

ZumoReflectanceSensorArray reflectanceSensors;

void setup() {
  reflectanceSensors.init(); // initialize sensors
  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);

  // Calibrate by moving robot manually over line
  for (int i = 0; i < 100; i++) {
    reflectanceSensors.calibrate();
    delay(20);
  }

  digitalWrite(LED_BUILTIN, HIGH); // indicate done
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // Not used here — see next example
}
```

### Follow basic track using threshold logic
After calibration, we can check each sensor’s reading. If a sensor sees "dark" (low reflectance), it’s likely over the line. We use this to steer the robot. We will set a threshold value that will act as the decision point between "dark" and "light"

```arduino
  unsigned int sensorValues[6]; // storesd each sensor value
  reflectanceSensors.read(sensorValues); //Read into sensorValues
  // Set a threshold
  int threshold = (reflectanceSensors.calibratedMinimumOn[0] + reflectanceSensors.calibratedMaximumOn[0]) / 2;
```
After getting the sensor values we can control the motors to follow the line. 

If the left most sensor see dark (`if (sensorValues[0] < threshold)`) turn left, etc.

```arduino
  //Movement from decision
  if (sensorValues[0] < threshold) {
    // Leftmost sensor sees line -> turn left
    motors.setSpeeds(-50, 150);
  } else if (sensorValues[5] < threshold) {
    // Rightmost sensor sees line -> turn right
    motors.setSpeeds(150, -50);
  } else {
    // Go straight
    motors.setSpeeds(150, 150);
  }

  delay(50); // small delay to smooth movement
```
## Activity 4: Sound & Lights
### Use buzzer to play a tone
```arduino 
#include <ZumoMotors.h>
#include <ZumoBuzzer.h>
#include <Pushbutton.h>

ZumoMotors motors;
ZumoBuzzer buzzer;
Pushbutton button(ZUMO_BUTTON);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  button.waitForButton();
}

void loop() {
  if (button.isPressed()) {
    // Simulate impact: alert + reverse
    digitalWrite(LED_BUILTIN, HIGH);
    buzzer.playFrequency(1000, 250, 15); // 1kHz for 250ms

    motors.setSpeeds(-150, -150);
    delay(500);

    digitalWrite(LED_BUILTIN, LOW);
    motors.setSpeeds(150, -150); // turn
    delay(300);
  } else {
    motors.setSpeeds(150, 150);
  }
}

```
### Flash LED on bump or lost line
```arduino 
#include <ZumoMotors.h>
#include <ZumoReflectanceSensorArray.h>
#include <ZumoBuzzer.h>

ZumoMotors motors;
ZumoReflectanceSensorArray sensors;
ZumoBuzzer buzzer;

void setup() {
  sensors.init();
  pinMode(LED_BUILTIN, OUTPUT);

  // Calibrate sensors
  for (int i = 0; i < 100; i++) {
    sensors.calibrate();
    delay(20);
  }
}

void loop() {
  unsigned int sensorValues[6];
  sensors.read(sensorValues);

  int threshold = 600;

  // Check if all sensors see white (line lost)
  bool lineLost = true;
  for (int i = 0; i < 6; i++) {
    if (sensorValues[i] < threshold) {
      lineLost = false;
      break;
    }
  }

  if (lineLost) {
    // Alert: line lost
    digitalWrite(LED_BUILTIN, HIGH);
    buzzer.playFrequency(2000, 200, 15);
    motors.setSpeeds(0, 0);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
  } else {
    // Normal movement
    motors.setSpeeds(150, 150);
  }
}

```

## Final Challenge: Race or Maze
- Combine movement + sensors
- Race around a taped loop or navigate a basic arena

## Wrap-Up & Q&A
- Encourage follow-up projects
- Show how to extend Zumo (e.g., Bluetooth, remote control)