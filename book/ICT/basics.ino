int ledPinrood = 13;

void setup() {
  pinMode(ledPinrood, OUTPUT);
}

void loop() {
  digitalWrite(ledPinrood, HIGH);   
  delay(1000);                       
  digitalWrite(ledPinrood, LOW);    
  delay(500);                       
}
