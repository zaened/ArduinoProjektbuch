/*Author : Zäned
Date : 01.12.2021*/

#define SWITCH 2
#define LED1 8
#define LED2 9
#define LED3 10
#define LED4 11
#define LED5 12
#define LED6 13
int switchState = 0;

void setup() {
  pinMode(SWITCH, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
}

void loop() {
  //Überprüfe, ob Strom an Pin 2 anliegt
  switchState = digitalRead(SWITCH);
  
  //Falls ja, lass LEDs leuchten
  if (switchState == HIGH){
    //Zufallszahl generieren
    int dicenumber = random(1,7);
    //Basierend auf Zufallszahl LEDs leuchten lassen
    if (dicenumber == 1){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      delay(2000);
      }
    else if (dicenumber == 2){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      delay(2000);
      }
    else if (dicenumber == 3){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      delay(2000);
      }
    else if (dicenumber == 4){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      delay(2000);
      }
    else if (dicenumber == 5){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, LOW);
      delay(2000);
      }
    else if (dicenumber == 6){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      delay(2000);
      }
   }
   else{
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    }
}
