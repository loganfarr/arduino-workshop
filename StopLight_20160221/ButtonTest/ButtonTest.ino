#define buttonOne 2
#define ledOne 3

#define buttonTwo 9
#define ledTwo 10

void setup() {
  pinMode(buttonOne, INPUT);
  pinMode(ledOne, OUTPUT);

  pinMode(buttonTwo, INPUT);
  pinMode(ledTwo, OUTPUT);

  digitalWrite(ledOne, LOW);
  digitalWrite(ledTwo, LOW);

}

void loop() {
  if(digitalRead(buttonOne) == HIGH) {
    digitalWrite(ledOne, HIGH);
  }
  else {
    digitalWrite(ledOne, LOW);
  }

  if(digitalRead(buttonTwo) == HIGH) {
    digitalWrite(ledTwo, HIGH);
  }
  else {
    digitalWrite(ledTwo, LOW);
  }

}
