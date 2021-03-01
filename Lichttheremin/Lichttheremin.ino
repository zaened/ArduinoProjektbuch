int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;    //SignalLED neben Pin 12

void setup() {
  
  pinMode(ledPin, OUTPUT);    //SignalLED wird angeschaltet, als Indikator für die Kalibrierung der Sensorwerte vom Fotowiderstand
  digitalWrite(ledPin, HIGH);

  while(millis() < 5000){   //millis misst die Zeit nach einem Neustart des Arduinos bzw. nach der Aktivierung des Arduinos; Es werden 5 Sekunden für die Kalibrierung gebraucht
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
      }
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;
      }
    }
  digitalWrite(ledPin, LOW);
}

void loop() {

  sensorValue = analogRead(A0);
  int pitch = map(sensorValue,sensorLow,sensorHigh,50,4000);
  tone(8,pitch,20);   //generiert den hörbaren Ton
  delay(10);
}
