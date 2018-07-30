#define TRIG_PIN A2
#define ECHO_PIN A3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp = readPing();
  if (temp < 1000) {
    Serial.print("Less than......");
  }
//  Serial.println(temp,DEC);
  delay(500);
}

int readPing() {
  long duration, inches, cm;

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
//inches = microsecondsToInches(duration);
//return inches;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

