#define DATA 6
#define LATCH 8
#define CLOCK 10

int number = 0;
int answer = 0;

void setup() {
  pinMode(LATCH, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);

  Serial.begin(9600);
  randomSeed(analogRead(0));

  displayNumber(0);
}

void displayNumber(byte a) {
  // Sends byte to be displayed on the LEDs
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, a);
  digitalWrite(LATCH, HIGH);
}

void getAnswer() {
  // Receive answer from player
  int z = 0;
  Serial.flush();
  
  while(Serial.available() == 0) {
    // Do nothing until something comes into the serial buffer
  }

  //One character of serial data is available, begin calculating
  while(Serial.available() > 0) {
    // Move any previous digit to the next column on the left; in
    // other words, 1 becomes 10 while there is data in the buffer
    answer = answer * 10;

    // Read the next number in the buffer and subtract the character '0'
    // from it to convert it to the actual integer number
    z = Serial.read() - '0';

    // Add this digit into the accumulating value
    answer += z;

    // Allow a short delay for any more numbers to come into Serial.available
    delay(5);
  }

  Serial.print("You entered: ");
  Serial.println(answer);
}

void checkAnswer() {
  // Check the answer from the player and show the results
  if(answer == number) { // Correct!
    Serial.print("Correct! ");
    Serial.print(answer, BIN);
    Serial.print(" equals ");
    Serial.println(number);
    Serial.println();
  }
  else { // Incorrect!
    Serial.print("Incorrect, ");
    Serial.print(number, BIN);
    Serial.print(" equals ");
    Serial.println(number);
    Serial.println();
  }

  answer = 0;
  delay(10000); // Give the player time to review his/her answers.
}

void loop() {
  number = random(256);
  displayNumber(number);
  Serial.println("What is the binary number in base-10?");
  getAnswer();
  checkAnswer();
}
