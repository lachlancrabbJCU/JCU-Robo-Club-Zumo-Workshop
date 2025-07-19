// JCU Robo Club Zumo Workshop Activity 1

#include <Wire.h>
#include <ZumoShield.h>

ZumoMotors motors;

void setup()
{
  // uncomment one or both of the following lines if your motors' directions need to be flipped
  //motors.flipLeftMotor(true);
  //motors.flipRightMotor(true);
}

void loop()
{
  // run left motor forward

  digitalWrite(LED_PIN, HIGH);

  for (int speed = 0; speed <= 400; speed++)
  {
    motors.setLeftSpeed(speed);
    delay(2);
  }

  for (int speed = 400; speed >= 0; speed--)
  {
    motors.setLeftSpeed(speed);
    delay(2);
  }

  // run left motor backward

  digitalWrite(LED_PIN, LOW);

  for (int speed = 0; speed >= -400; speed--)
  {
    motors.setLeftSpeed(speed);
    delay(2);
  }

  for (int speed = -400; speed <= 0; speed++)
  {
    motors.setLeftSpeed(speed);
    delay(2);
  }

  // run right motor forward

  digitalWrite(LED_PIN, HIGH);

  for (int speed = 0; speed <= 400; speed++)
  {
    motors.setRightSpeed(speed);
    delay(2);
  }

  for (int speed = 400; speed >= 0; speed--)
  {
    motors.setRightSpeed(speed);
    delay(2);
  }

  // run right motor backward

  digitalWrite(LED_PIN, LOW);

  for (int speed = 0; speed >= -400; speed--)
  {
    motors.setRightSpeed(speed);
    delay(2);
  }

  for (int speed = -400; speed <= 0; speed++)
  {
    motors.setRightSpeed(speed);
    delay(2);
  }

  delay(500);
}
