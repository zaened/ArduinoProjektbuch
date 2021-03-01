int notes[] = {262,294,330,349};    //Frequenzen für die verschiedenen Töne

void setup() {
  Serial.begin(9600);
}

void loop() {
  int keyVal = analogRead(A0);    //Je nachdem, welche Taste gedrückt wird, strömt ein anderer Strom in A0 ein, was dann für die if-Abfrage genutzt wird
  Serial.println(keyVal);
  if(keyVal <= 1023 && keyVal >= 1011){
    tone(8, notes[0]);
    }
  else if(keyVal >= 516 && keyVal <= 700){
    tone(8, notes[1]);
    }
  else if(keyVal >= 505 && keyVal <= 515){
    tone(8, notes[2]);
    }
  else if(keyVal >= 5 && keyVal <= 10){
    tone(8, notes[3]);
    }
  else{
    noTone(8);
    }
}
