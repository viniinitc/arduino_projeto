const int BUZZER_PIN1 = 9; 
const int BUZZER_PINR = 8; 
const int TRIG_PIN = 2;
const int ECHO_PIN = 3;
int distance;
int cm;
int inst;
long int del; 
float teste = A1;
const int som = 16;


long readUltrasonicDistance(int triggerPin, int echoPin) {  
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);  
  delayMicroseconds(2);  
  digitalWrite(triggerPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);  
  return pulseIn(echoPin, HIGH);
}

void setup() {
  Serial.begin(115200);

  
  Serial.println("pode funciona");
  
  del = millis();
  teste = 0;
 
  pinMode(BUZZER_PIN1, OUTPUT);
  pinMode(BUZZER_PINR, OUTPUT);
  
  Serial.println("pode funcionar");
  pinMode(A1, INPUT);
}


void loop() {
  
  distance = 200;
  cm = readUltrasonicDistance(TRIG_PIN, ECHO_PIN) * 0.01723;

  if (millis() - del > 2000) {
    if (inst == 0) {
      if (cm < distance) {
        inst++;
       
      }
    }
    if (inst == 1) {
      inst++;
      tone(3, som, 300);
    }
  }

 Serial.println(cm);
 int  valor = analogRead(A1);
 valor = map(valor, 0, 1023, 15, 122);
  if (inst > 1) {
    
    if (millis() - del > 1000){
      tone(BUZZER_PINR, som, 300);
      delay(1000);
      tone(BUZZER_PIN1, valor, 300);
      del = millis();
    }


    if (valor == som) {
      inst = -1;
      for (int i = 0; i < 10; i++){
        tone(BUZZER_PINR, som, 300);
        delay(200);
        tone(BUZZER_PIN1, som, 300);
      }
      
    }
    }
  }
