# Arduino
## Als middel

In deze opdracht leer je de basis van werken met Arduino en kun je uiteindelijk lampjes aan en uitschakelen met een knopje. Wil je meer weten over Arduino? Er is een [basismodule](./Arduino%20module%20basis.pdf) en een [gevorderde module](./Arduino%20module%20gevorderd.pdf).

De opdrachten kun je maken met de gratis software van [Arduino](https://arduino.cc), maar er zijn ook online [emulators](https://wokwi.com/projects/new/arduino-uno).


**Opdracht 1**
1)	Bouw de onderstaande opstelling na. (let op het zwarte kabeltje naar GND en de lange poot van de LED is de + zijde)
2)	Download de [basiscode](basics.ino) en upload deze naar de Arduino.

```{code-cell} Arduino
:tags: [hide-input]
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

```

3)	Kijk goed naar de code, en naar wat er gebeurt met het lampje. Leg uit hoe lang het lampje brandt en hoe lang deze niet brandt.
4)	Verander de tijd die het lampje uit staat (vergeet niet je code opnieuw te uploaden). 

```{figure} Figures/Arduino1.png
:width: 70%
```

5)	Breid eerst de schakeling uit met een tweede LED verbonden met pin 8. Verander vervolgens de code zodat de groene LED brandt en de rode LED niet (en andersom). 

```{figure} Figures/Arduino2.png
:width: 70%
```

6)	Breid nu de schakeling uit door een drukknopje op te nemen, zie schakeling hieronder. Download de [code](drukknop.ino) en upload deze naar de Arduino. 

```{figure} Figures/Arduino3.png
:width: 70%
```

```{toggle}

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

```

7)	Probeer de code te lezen. Druk op de knop en zie wat er met de rode LED gebeurt. Had je dit, op basis van de gelezen code, verwacht?
8)	Bedenk zelf een opdracht die gedaan kan worden met deze opstelling. 

## Als doel
**Opdracht 2**
In deze opdracht doen we onderzoek naar de reactiesnelheid van een persoon. Daartoe bouwen we een eenvoudige opstelling met behulp van Arduino. De opstelling bestaat uit een rode en een groene LED’s en een drukknop. De rode LED brandt en gaat op een willekeurig moment uit. Tegelijkertijd gaat de groene LED branden. Je moet dan zo snel mogelijk op het knopje drukken. De tijd die je daarvoor nodig hebt wordt gemeten.

```{figure} Figures/Arduino4.png
:width: 70%
```

1)	Bouw de bovenstaande opstelling.
2)	Download de code [reactiesnelheid.ino](reactiesnelheid.ino) is en upload deze naar de Arduino.
3)	Doe elk een serie van vijf metingen. 
4)	Is de reactiesnelheid steeds hetzelfde? Zijn er grote verschillen in een enkele data set?
5)	Wie heeft de kortste reactietijd? Leg uit hoe je dat vergeleken hebt en hoe zeker je bent dat er een verschil zit in de reactiesnelheid.
6)	Wordt de reactiesnelheid minder als je langer moet wachten? Onderzoek dat door eerst de code aan te passen (weer te uploaden) en vervolgens elk weer een set van vijf metingen te verzamelen.
7)	Is er een groot (significant) verschil? Hoe zou je dat verschil kunnen kwantificeren?
8)	Om beter een mogelijke relatie tussen de wachttijd en de reactiesnelheid te onderzoeken, willen we niet alleen de reactiesnelheid printen maar ook de wachttijd. Pas de code aan en gebruik deze code om verder onderzoek te doen…


```{code-cell} Arduino
:tags: [hide-input]
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
```
