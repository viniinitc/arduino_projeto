
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


int distance1;
int distance2;
int pos;
int cm1;
int cm2;
int del = millis();
int inst1;
int inst2;
void setup() {
  
  Serial.begin(115200);

  Serial.println();
  del = millis();
 
  Serial.println("pode funcionar");
  
}

void loop() {

  distance1 = 20;
  distance2 = 200;
  cm1 = readUltrasonicDistance(12, 13) * 0.01723;
  cm2 = readUltrasonicDistance(5, 6) * 0.01723;

  
  Serial.print("Distance in CM: ");
  Serial.println(cm1);
  Serial.println(" ");
  Serial.println(cm2);
  
  if (cm2 < distance2){
    inst2++;
  }
  if (inst2 >= 1){
    if (millis() - del > 1250){
      tone(8, 16, 300);
      del = millis();
    }
  }
  if (cm1 < distance1) {
    inst1++;
  }
  if (inst1 == 1){
    for (int i = 0; i < 10; i++){
        tone(8, 16, 300);
        delay(200);
        tone(8, 16, 300);
    }
    for (int i = 0; i < 10; i++){
        tone(8, 280, 300);
        delay(200);
        tone(8, 180, 300);
      }
    inst2 = -10000;
    inst1 = -10000;
  }
}
