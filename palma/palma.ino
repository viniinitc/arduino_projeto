const int OUT_PIN = 8;
long int del; 
void setup() {
  del = millis();
  Serial.begin(9600);
  pinMode(4, OUTPUT);
}
void loop() {

  Serial.println(digitalRead(OUT_PIN));
  if (digitalRead(OUT_PIN) == 1){
    digitalWrite(4, HIGH);
    del = millis();
  }
  else{
    if ((millis() - del) > 1000){
      digitalWrite(4, LOW);
      del = millis();
    }
  }
}