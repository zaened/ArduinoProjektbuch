#define BLAUER_LED_PIN 12
#define ROTER_LED_PIN 13
#define FERTIG 1
#define UNFERTIG 0
#define MAX_BLINKRYTHMUS 2000
#define SCHRITTWEITE 100

int zustand = UNFERTIG;
int blinkRythmus = 50;

void setup() {
  pinMode(BLAUER_LED_PIN, OUTPUT);
  pinMode(ROTER_LED_PIN, OUTPUT);
}

void loop() {
  if(zustand == UNFERTIG){
    while(blinkRythmus < MAX_BLINKRYTHMUS){   // Begrenzung des Blinkens
      digitalWrite(BLAUER_LED_PIN, HIGH);   // Blinken der LEDS
      delay(blinkRythmus);
      digitalWrite(BLAUER_LED_PIN, LOW);
      digitalWrite(ROTER_LED_PIN, HIGH);
      delay(blinkRythmus);
      digitalWrite(ROTER_LED_PIN, LOW);
      blinkRythmus += SCHRITTWEITE;   // Zum Verlangsamen des Blinkens
      }
    int startwert = analogRead(1);    // Bis zu 1024 verschiedene Werte
    randomSeed(startwert);    // Erstelle zufällige Zahl als globale Variable als Startwert für ergebnis
    int ergebnis = random();
    if(ergebnis < 0){
      ergebnis *= -1;
      }
    if(ergebnis % 2 == 0){    // Entscheide, welche LED am Ende an bleibt und die Entscheidung darstellt
      digitalWrite(ROTER_LED_PIN, HIGH);
      }
    else{
      digitalWrite(BLAUER_LED_PIN, HIGH);
      }
    zustand = FERTIG;   // Abbruchbedingung
    }
}
