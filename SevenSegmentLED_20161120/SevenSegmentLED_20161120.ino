#define DATA 6
#define LATCH 8
#define CLOCK 10

#define DELAY 300

int digits[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156, 122, 158, 142};
int bytes[] = {128, 64, 32, 16, 8, 4, 2, 1, 0};

void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 16; i++){
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[i]);
    digitalWrite(LATCH, HIGH);
    Serial.println(digits[i]);
    delay(DELAY);
  }

  for(int i = 0; i < 16; i++){
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[i] + 1);
    digitalWrite(LATCH, HIGH);
    Serial.println(digits[i]);
    delay(DELAY);
  }

  // for(int i=0; i<8; i++){
  //   digitalWrite(LATCH, LOW);
  //   shiftOut(DATA, CLOCK, LSBFIRST, bytes[i]);
  //   digitalWrite(LATCH, HIGH);
  //   delay(150);
  // }
}
