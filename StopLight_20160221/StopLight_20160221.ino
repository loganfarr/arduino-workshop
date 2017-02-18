#define westButton 5
#define eastButton 13

#define westGreen 2
#define westYellow 3
#define westRed 4

#define eastGreen 10
#define eastYellow 11
#define eastRed 12

#define yellowBlinkTime 500 // 0.5 seconds for yellow light blink

bool trafficWest = true; //West = true, East = false
int flowTime = 10000;
int changeDelay = 2000;

void setup() {
 //setup digital I/0 pins
 pinMode(westButton, INPUT);
 pinMode(eastButton, INPUT);
 pinMode(westRed, OUTPUT);
 pinMode(westYellow, OUTPUT);
 pinMode(westGreen, OUTPUT);
 pinMode(eastRed, OUTPUT);
 pinMode(eastYellow, OUTPUT);
 pinMode(eastGreen, OUTPUT);
 
 //set initial state for lights - west side is green first
 digitalWrite(westRed, LOW);
 digitalWrite(westYellow, LOW);
 digitalWrite(westGreen, HIGH);
 
 digitalWrite(eastRed, HIGH);
 digitalWrite(eastYellow, LOW);
 digitalWrite(eastGreen, LOW);
}

void loop() {
  if(digitalRead(westButton) == HIGH && trafficWest != true) {
    trafficWest = true; //Set traffic flow to west
    delay(flowTime); 
    digitalWrite(eastGreen, LOW); //Turn off the east green light
    
    digitalWrite(eastYellow, HIGH); //Turn on the east yellow light 
    delay(changeDelay); //Stay on
    digitalWrite(eastYellow, LOW); //Turn off the east yellow light
    digitalWrite(eastRed, HIGH); //Turn on the east red light
    delay(changeDelay);
    
    //Traffic to the east has stopped now
     
    for (int i = 0; i < 5; ++i)
    {
      digitalWrite(westYellow, LOW); //West yellow turned off
      delay(yellowBlinkTime);
      digitalWrite(westYellow, HIGH); //West yellow turned on
      delay(yellowBlinkTime);
    }

    digitalWrite(westYellow, LOW); //West yellow turned off
    digitalWrite(westRed, LOW); //West red turned off
    digitalWrite(westGreen, HIGH); //West green turned off
    
    //Traffic now flowing west
  } 

  if(digitalRead(eastButton) == HIGH && trafficWest == true) {
    trafficWest = false; //Set traffic flow to east
    delay(flowTime);
    digitalWrite(westGreen, LOW); //Turn off west green light

    digitalWrite(westYellow, HIGH); //Turn on west yellow light
    delay(changeDelay);
    digitalWrite(westYellow, LOW); //Turn off west yellow light
    digitalWrite(westRed, HIGH); //Turn on west red light
    delay(changeDelay);
    
    for (int i = 0; i < 5; ++i)
    {
      digitalWrite(eastYellow, LOW); //Turn off east yellow light
      delay(yellowBlinkTime);
      digitalWrite(eastYellow, HIGH); //Turn on east yellow light
      delay(yellowBlinkTime);
    }

    digitalWrite(eastYellow, LOW);
    digitalWrite(eastRed, LOW);
    digitalWrite(eastGreen, HIGH);

  }
} 
