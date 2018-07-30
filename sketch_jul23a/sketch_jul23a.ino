int ledPin = 13;
int counter = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(ledPin, HIGH);
//  delay(15);
//  digitalWrite(ledPin, LOW);
//  delay(15);
  if(1 == 1){
      flashCount();
//        flashStop(10);
    } else {
      flash(1000);
    }
}

void flash(int fast) {
  digitalWrite(ledPin, LOW);
  delay(fast);
  digitalWrite(ledPin, HIGH);
  delay(fast);  
}

void flashCount() {
  counter++;
  int rate = counter * 10;
  flash(rate);
}

void flashStop(int amount){
  if (counter < 10) {
    counter++;
    flash(1000);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
