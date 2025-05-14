#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

const int OUT_PIN = 8;
long int del; 
int palma;
void setup() {
  del = millis();
  Serial.begin(9600);
  pinMode(4, OUTPUT);
}
void loop() {

  Serial.println(digitalRead(OUT_PIN));
  Serial.println(palma);
  if (digitalRead(OUT_PIN) == 1){
    digitalWrite(4, HIGH);
    palma ++;
    if ((millis() - del > 500) && millis() - del < 5000) {
      palma = 0;
    }
    del = millis();
  }
  else{
    if ((millis() - del) > 500){
      digitalWrite(4, LOW);
    }
  }
  
  

  if (millis() - del > 5000){
    palma = 0;
    del = millis();
  }
}