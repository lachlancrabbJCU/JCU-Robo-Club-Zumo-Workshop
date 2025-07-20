// JCU Robo Club Activity 3 Line Follower
#include <ZumoReflectanceSensorArray.h>
#include <ZumoMotors.h>

ZumoReflectanceSensorArray reflectanceSensors;
ZumoMotors motors;

void setup() {
  reflectanceSensors.init();
  delay(500);

  // Calibrate first
  for (int i = 0; i < 100; i++) {
    reflectanceSensors.calibrate();
    delay(20);
  }
}

void loop() {
  unsigned int sensorValues[6]; // stores each sensor value
  reflectanceSensors.read(sensorValues); //Read into sensorValues

  // Set a threshold
  int threshold = (reflectanceSensors.calibratedMinimumOn[0] + reflectanceSensors.calibratedMaximumOn[0]) / 2;

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
}