const int switchPin = 8;    //Pin des Kippschalters
unsigned long previousTime = 0;   //Variable zur Zeitmessung
int switchState = 0;    //aktueller Zustand des Schalters
int prevSwitchState = 0;    //vorheriger Zustand des Schalters
int led = 2;    //Erster Pin der LEDs
long interval = 600000;   //600000ms = 10min, fürs Anschalten der LEDs

void setup() {
for(int x = 2; x < 8;x++){
  pinMode(x, OUTPUT);
  }
pinMode(switchPin, INPUT);
}

void loop() {
unsigned long currentTime = millis();
if(currentTime - previousTime > interval){
  previousTime = currentTime;
  digitalWrite(led, HIGH);
  led++;
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState){
    for(int x = 2;x < 8;x++){
      digitalWrite(x, LOW);
      }
    led = 2;
    previousTime = currentTime;
   }
  prevSwitchState = switchState;
  }
}
