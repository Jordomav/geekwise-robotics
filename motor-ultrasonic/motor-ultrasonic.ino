#define leftFactor 10
#define rightFactor 10
#define speedSet 200
#define TRIG_PIN A2
#define ECHO_PIN A3
#define SERVO_PIN 10

#include <UCMotor.h>
#include <Servo.h>

UC_DCMotor leftMotor(3, MOTOR34_64KHZ);
UC_DCMotor rightMotor(4, MOTOR34_64KHZ);

Servo neckController;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  neckController.attach(SERVO_PIN);
  neckController.write(90);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp = readPing();
  if (temp < 10) {
    moveStop();
    delay(1000);
    neckController.write(0);
    if (temp < 10) {
      turnRight();
      delay(1000);
      neckController.write(90);
    } else {
      neckController.write(180);
      if (temp < 10) {
        turnLeft();
        delay(1000);
        neckController.write(90);
      }
    }
  } else {
    moveForward();
  }
}

int readPing() {
  long duration, cm;
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, LOW);

  pinMode(ECHO_PIN, INPUT);
  duration = pulseIn(ECHO_PIN, HIGH);

  cm = microsecondsToCentimeters(duration);
  return cm;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
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

