// De pinnen definieeren
const int buttonPin = 2;
const int ledPingroen = 8;
const int ledPinrood =  13; 

// De variabelen definieren
unsigned long starttimer;
unsigned long stoptimer;

int sleeptime;

void setup() {
//toewijzen van de pinnen  
  pinMode(buttonPin,INPUT);
  pinMode(ledPingroen, OUTPUT);
  pinMode(ledPinrood, OUTPUT);

  Serial.begin(9600);
}

void loop() {
//groen uit, rood aan
  digitalWrite(ledPingroen, LOW); 
  digitalWrite(ledPinrood, HIGH);

//random switch
  sleeptime = random(2000, 7000);
  delay(sleeptime);

//start stopwatch
  starttimer = millis();
  digitalWrite(ledPingroen, HIGH);
  digitalWrite(ledPinrood, LOW);

//stop stopwatch
  while(digitalRead(buttonPin)==LOW){}
  stoptimer = millis();
  digitalWrite(ledPingroen, LOW);

//print tijd
  Serial.println(stoptimer - starttimer);
  delay(1000);
}
