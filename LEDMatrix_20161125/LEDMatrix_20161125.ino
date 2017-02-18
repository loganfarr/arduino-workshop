#define DATA 6
#define LATCH 8
#define CLOCK 10

void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
}

void loop() {
  byte a = B10101010;
//  byte a = B11111111;

  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, a);
  shiftOut(DATA, CLOCK, MSBFIRST, ~a);
  digitalWrite(LATCH, HIGH);
  do {} while (1);
}
