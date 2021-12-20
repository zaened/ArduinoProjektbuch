#define PIN1 12
#define PIN2 13
#define LANGER_IMPULS 1
#define KURZER_IMPULS 2
#define DAUER_LANGER_IMPULS 600
#define DAUER_KURZER_IMPULS 100
int signal[] = {
  KURZER_IMPULS, KURZER_IMPULS, KURZER_IMPULS,
  LANGER_IMPULS, LANGER_IMPULS, LANGER_IMPULS,
  KURZER_IMPULS, KURZER_IMPULS, KURZER_IMPULS};

void setup() {
  pinMode(PIN1, OUTPUT);
  pinMode(PIN2, OUTPUT);
}

void loop() {
  for(int i = 0; i < 9; i++){
    int impuls = signal[i];
    if(impuls == KURZER_IMPULS){
      digitalWrite(PIN1, HIGH);
      delay(DAUER_KURZER_IMPULS);
      digitalWrite(PIN1, LOW);
      delay(DAUER_KURZER_IMPULS);
    }
    else{
      digitalWrite(PIN2, HIGH);
      delay(DAUER_LANGER_IMPULS);
      digitalWrite(PIN2, LOW);
      delay(DAUER_LANGER_IMPULS);  
    }
  }
  delay(3000);
}
