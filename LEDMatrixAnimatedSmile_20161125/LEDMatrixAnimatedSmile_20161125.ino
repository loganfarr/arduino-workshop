#define DATA 6
#define LATCH 8
#define CLOCK 10

byte smile[] = {
  B00000000,
  B00000110,
  B01000110,
  B00000000,
  B00011000,
  B00000000,
  B11000011,
  B01111110 };
int binary[] = {1, 2, 4, 8, 16, 32, 64, 128};

void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
}

void loop() {
  for(int shift = 0; shift < 9; shift++){
    for(int hold = 0; hold < 25; hold++){
      for(int a = 0; a < 8; a++){
        digitalWrite(LATCH, LOW);
        shiftOut(DATA, CLOCK, MSBFIRST, ~smile[a] >> shift);
        shiftOut(DATA, CLOCK, LSBFIRST, binary[a]);
        digitalWrite(LATCH, HIGH);
        delay(1);
      }
    }
  }
}
