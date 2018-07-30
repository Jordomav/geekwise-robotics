#define leftFactor 10
#define rightFactor 5
#define speedSet 150
#include <UCMotor.h>

UC_DCMotor leftMotor(3, MOTOR34_64KHZ);
UC_DCMotor rightMotor(4, MOTOR34_64KHZ);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  turnRight();
  delay(2000);
  turnLeft();
  delay(2000);
}

void moveForward() {
   leftMotor.run(FORWARD);
   rightMotor.run(FORWARD);
   leftMotor.setSpeed(speedSet + leftFactor);
   rightMotor.setSpeed(speedSet + rightFactor);
}

void moveBackward(){
  leftMotor.run(BACKWARD);
  rightMotor.run(BACKWARD);
  leftMotor.setSpeed(speedSet + leftFactor);
  rightMotor.setSpeed(speedSet + rightFactor);
}

void turnRight() {
  leftMotor.run(FORWARD);
  rightMotor.run(BACKWARD);
  leftMotor.setSpeed(speedSet + leftFactor);
  rightMotor.setSpeed(speedSet + rightFactor);
  delay(400);
  moveStop();
}

void turnLeft(){
  leftMotor.run(BACKWARD);
  rightMotor.run(FORWARD);
  leftMotor.setSpeed(speedSet + leftFactor);
  rightMotor.setSpeed(speedSet + rightFactor);
  delay(400);
  moveStop();
}

void moveStop() {
  leftMotor.run(5);
  rightMotor.run(5);
  leftMotor.setSpeed(0);
  rightMotor.setSpeed(0);
}

void square() {
  moveForward();
  delay(1000);
  moveStop();
  delay(500);
  turnRight();
  delay(250);
}

void triangle() {
  moveForward();
  delay(1000);
  moveStop();
  delay(500);
  turnRight();
  delay(400);
}

void trapezoid(){
  moveForward();
  delay(1000);
  moveStop();
  delay(1000);
  turnRight();
  delay(250);
  moveForward();
  delay(500);
  moveStop();
  delay(1000);
  turnRight();
  delay(250);
  moveForward();
  delay(1500);
  moveStop();
  delay(1000);
  turnRight();
  delay(400);
  moveForward();
  delay(1000);
  moveStop();
  delay(1000);
}

void triangle2() {
  moveForward();
  delay(1000);
  moveStop();
  delay(1000);
  turnLeft();
  delay(400);
  moveForward();
  delay(800);
  moveStop();
  delay(1000);
  turnLeft();
  delay(350);
  moveForward();
  delay(500);
  moveStop();
  delay(1000);
  turnLeft();
  delay(400);
}

