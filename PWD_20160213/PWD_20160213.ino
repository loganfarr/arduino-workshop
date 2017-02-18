int d = 5;

void setup () {
  pinMode(3, OUTPUT);
}

void loop() {
  for(int i = 0; i < 256; i++) {
   analogWrite(3, i);
   delay(d); 
  }
  
  for(int i = 255; i >= 0; i--) {
   analogWrite(3, i);
   delay(d); 
  }
  
  delay(200);
}
