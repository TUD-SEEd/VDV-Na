//pinnen definieren 
const int ledPinrood = 13;
const int ledPingroen = 8;
const int drukknop = 2;

//variabelen definieren
int counter = 0;
int knop_staat = 0;
int knop_vorige_staat = 0;

void setup() {
  pinMode(ledPinrood, OUTPUT);
  pinMode(ledPingroen, OUTPUT);
  pinMode(drukknop, INPUT);
}

void loop() {
  knop_staat = digitalRead(drukknop);
  if(knop_staat == 1 && knop_vorige_staat == 0){
    counter = counter + 1;
  }
  
  digitalWrite(ledPinrood, counter%2); //check of counter even of oneven is 
  digitalWrite(ledPingroen, (counter+1)%2);

  knop_vorige_staat = knop_staat;
  delay(100);
  
}
