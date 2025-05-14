int cm = 0;
int distance = 0;

long readUltrasonicDistance(int triggerPin, int echoPin){  
  pinMode(triggerPin, OUTPUT);  // Clear the trigger  
  digitalWrite(triggerPin, LOW);  
  delayMicroseconds(2);  // Sets the trigger pin to HIGH state for 10 microseconds  
  digitalWrite(triggerPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);  // Reads the echo pin, and returns the sound wave travel time in microseconds  
  return pulseIn(echoPin, HIGH);}

void setup()
{
  pinMode(9, OUTPUT);
}

void loop()
{
  distance = 10;
  cm = readUltrasonicDistance(7, 5) * 0.01723;
  delay(100); // 
  if (cm > distance){
    digitalWrite(9, LOW);
  }
  if (cm < distance) {
   digitalWrite(9, HIGH); 	
  }
}