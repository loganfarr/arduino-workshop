#define DATA 6
#define LATCH 8
#define CLOCK 10

int binary[] = {1, 2, 4, 8, 16, 32, 64, 128};
int r, c = 0;

void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  randomSeed(analogRead(0));
}

void setLED(int row, int column, int del) {
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, ~binary[column]);
  shiftOut(DATA, CLOCK, MSBFIRST, binary[row]);
  digitalWrite(LATCH, HIGH);
  delay(del);
}

void loop() {
  r = random(8);
  c = random(8);
  setLED(r, c, 3);
}
