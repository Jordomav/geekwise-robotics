#include <Servo.h>

#define SERVO_PIN 10

Servo neckController;

int pos = 0;
void setup() {
  // put your setup code here, to run once:
  neckController.attach(SERVO_PIN);
  neckController.write(90);
  delay(1000);
  neckController.detach();
}

void loop() {
  // put your main code here, to run repeatedly:
  neckController.attach(SERVO_PIN);
  for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    neckController.write(pos);
    delay(1000);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    neckController.write(pos);
    delay(1000);
  }
}
