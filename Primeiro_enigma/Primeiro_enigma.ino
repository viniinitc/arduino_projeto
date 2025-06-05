
#define BUTTON_PIN 4 

long int del;
int inst;
int grilo = 16;
int bau;
int coco;
bool isTouchPressed(int pin) 
{ 
   return digitalRead(pin) == HIGH; 
} 


struct touch { 
   byte wasPressed = LOW; 
   byte isPressed = LOW; 
}; 
touch touch; 
void setup() 
{ 

  
   Serial.begin(115200);
   del = millis();
   pinMode(BUTTON_PIN, INPUT); 
   pinMode(9, INPUT);
   
} 
void loop() 
{ 
  int state = digitalRead(9);
  Serial.println(state);
  if (millis()-del > 1000){
    if (state == HIGH){
      coco ++;
    }
    
  }
  
  if (coco >= 1){
   if (millis() - del > 1000){
     tone(8, grilo,300);
     del = millis();
   }
  }
   touch.isPressed = isTouchPressed(BUTTON_PIN); 
   
   if (touch.wasPressed != touch.isPressed) { 
     Serial.println("touch being pressed");
     inst ++;
     Serial.println(inst);
   }
   if (inst == 1){
    for ( int i =   0; i < 5; i++){
       tone(8, 16, 300);
       delay(300);
    }
    inst = 2;
    grilo = 0;
   }
   touch.wasPressed = touch.isPressed; 
} 
