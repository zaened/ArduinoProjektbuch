const int greenLEDPin = 9;    //Pins der RGB-LED
const int redLEDPin = 11;
const int blueLEDPin = 10;

const int redSensorPin = A0;    //Sensorpins (Photowiderstände)
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;   //Werte für die Dimmung
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;   //Sensorwerte als Variablen
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  Serial.print("Raw Sensor Value \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.print(blueSensorValue);

  redValue = redSensorValue/4;    //Länge für die PMW - 255 bedeutet konstant an und 0 konstant aus. Ein Wert von 127 bedeutet 50% an und 50% aus.
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.print(blueValue);

  analogWrite(redLEDPin, redValue);     //Ansteuern der PMW-Pins auf dem Arduino (Pin, Wert(0-255))
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}
