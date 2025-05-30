#include <Servo.h>

#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"


Servo myservo;

#if (defined(ARDUINO_AVR_UNO) || defined(ESP8266))   // Using a soft serial port
#include <SoftwareSerial.h>
SoftwareSerial softSerial(/*rx =*/10, /*tx =*/11);
#define FPSerial softSerial
#else
#define FPSerial Serial1
#endif

DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);


const int OUT_PIN = 8;
long int del; 
int palma;
int cm = 0;
int distance = 0;
int inst = 0;


long readUltrasonicDistance(int triggerPin, int echoPin){  
  pinMode(triggerPin, OUTPUT);  // Clear the trigger  
  digitalWrite(triggerPin, LOW);  
  delayMicroseconds(2);  // Sets the trigger pin to HIGH state for 10 microseconds  
  digitalWrite(triggerPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);  // Reads the echo pin, and returns the sound wave travel time in microseconds  
  return pulseIn(echoPin, HIGH);}


void setup() {
  #if (defined ESP32)
    FPSerial.begin(9600, SERIAL_8N1, /*rx =*/D3, /*tx =*/D2);
  #else
    FPSerial.begin(9600);
  #endif
    Serial.begin(115200);
    Serial.println();
    Serial.println(F("DFRobot DFPlayer Mini Demo"));
    Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
    if (!myDFPlayer.begin(FPSerial, /*isACK = */true, /*doReset = */true)) {  //Use serial to communicate with mp3.
      Serial.println(F("Unable to begin:"));
      Serial.println(F("1.Please recheck the connection!"));
      Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.volume(25);  //Set volume value. From 0 to 30
  Serial.begin(9600);
  del = millis();
  
  pinMode(4, OUTPUT);
  myservo.attach(2);
}
void loop() {
  distance = 300;
  cm = readUltrasonicDistance(12, 13) * 0.01723;
  if (millis()-del > 2000){
    if (inst == 0){
      if (cm > distance){
        inst += 1;
        Serial.println(inst);
      }
    }
    if (inst == 1){
      inst ++;
      myDFPlayer.play(3);
      
    }
  }
  //Serial.println(digitalRead(OUT_PIN));
  if (millis() - del > 200){
    Serial.println(cm);
  }
  if (digitalRead(OUT_PIN) == 1){
    digitalWrite(4, HIGH);
    if (millis() - del > 200){
      palma += 1;
    }
    if ((millis() - del > 200)){ 
      if ((millis() - del < 1500) && millis() - del < 3000) {
        palma = 0;
      }
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
  if (palma == 10){
    myDFPlayer.play(4);
    myservo.write(180);
    palma = 0; 
  }
}
