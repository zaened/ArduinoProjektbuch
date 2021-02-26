int switchstate = 0;    //Variable für den Drucktaster

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
//Deklaration der Digitalpins in Out/Inputs (pinnummer, status)
}

void loop() {
  switchstate = digitalRead(2);   //Überprüfe eingehende Spannung an Digitalpin 2
  if(switchstate == LOW){     //Drucktaster wird nicht gedrückt
    digitalWrite(3, HIGH);    //Output anschalten (HIGH) oder ausschalten (LOW)
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else{
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(250);   //Verzögerung von 1/4 Sekunde
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);
  } 
}
