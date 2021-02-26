const int sensorPin = A0;   //Konstanter int-Wert, da der Analogpin sich nicht ändert
const float baseTemp = 20.0;    //Konstanter float-Wert zum setzen der durchschnittlichen Zimmertemperatur

void setup() {
  
  Serial.begin(9600);   //Seriellen Monitor aktivieren, 9600 = Geschwindigkeit des Datenaustausches zwischen Arduino und PC in Bits
  
  for(int i = 3; i < 6; i++){   //For-Schleife zum Deklarieren von In/Outputs und setzen des Status (an/aus)
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  
  int sensorVal = analogRead(sensorPin);    //Ablesen des Temperatursensorwertes (ohne Umrechnung, Zahl bis 1024
  Serial.print(" Sensor Value: ");
  Serial.print(sensorVal);
  float voltage =  (sensorVal/1024) * 5.0;    //Sensorval = 0 wäre 0V und 1024 wäre 5V, Umrechnung von Bits in Volt
  Serial.print(" , Volts: ");
  Serial.print(voltage);
  Serial.print(" , degrees C: ");
  float temperature = (voltage - .5) * 100;   //10mV = 1°C
  Serial.print(temperature);
  
  if(temperature < baseTemp){
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    }
  else if(temperature >= baseTemp+2 && temperature < baseTemp+4){
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    }
  else if(temperature >= baseTemp+4 && temperature < baseTemp+6){
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    }
  else if(temperature >= baseTemp+6){
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    }
  delay(1);
}
