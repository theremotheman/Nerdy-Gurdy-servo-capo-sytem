#include <Servo.h>

const int  buttonPin1 = 2;
const int  buttonPin2 = 7;
const int  buttonPin3 = 4;
const byte servoPin1 = 9;
const byte servoPin2 = 5;
const int ledPin1 = 8;
const int ledPin2 = 15;
const int ledPin3 = 14;
const int buzzer = 6;

Servo servo1;
Servo servo2;
int buttonPushCounter1 = 0;   // counter for the number of button presses
int buttonPushCounter2 = 0;
int buttonPushCounter3 = 0;
int buttonState1 = 0;// current state of the button
int buttonState2 = 0; 
int buttonState3 = 0;
int lastButtonState1 = 0;     // previous state of the button
int lastButtonState2 = 0;
int lastButtonState3 = 0;

void setup()
{
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo1.write(4);
  servo2.write(4);
  delay(500);
  servo1.detach();
  servo2.detach();
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  tone(buzzer, 1000); 
  delay(250);        
  noTone(buzzer);     
  delay(250);        
  tone(buzzer, 1500); 
  delay(250);        
  noTone(buzzer);     
  delay(250);        
  tone(buzzer, 2000); 
  delay(250);        
  noTone(buzzer);     
  delay(250);         
  tone(buzzer, 2500); 
  delay(250);        
  noTone(buzzer);     
  delay(250);        
  tone(buzzer, 1000); 
  delay(250);        
  noTone(buzzer);     
  delay(250);        
  tone(buzzer, 1500); 
  delay(250);        
  noTone(buzzer);     
  delay(250);        
  tone(buzzer, 2000); 
  delay(250);        
  noTone(buzzer);     
  delay(250);         
  tone(buzzer, 2500);
  delay(250);        
  noTone(buzzer);        
}

void loop()
{
  // read the pushbutton input pin:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  // compare the buttonState to its previous state
  if (buttonState1 != lastButtonState1)
  {
    // if the state has changed, increment the counter
    if (buttonState1 == LOW)
    {
      // if the current state is LOW then the button
      // went from off to on:
      buttonPushCounter1++;      
      if(buttonPushCounter1 == 1)
      {
        digitalWrite(8, LOW);
        digitalWrite(15, LOW);
        servo1.attach(servoPin1);
        servo1.write(4);
        delay(500);
        servo1.detach();
      }
      if(buttonPushCounter1 == 2)
      {
        digitalWrite(8, HIGH);
        digitalWrite(15, LOW);
        servo1.attach(servoPin1);
        servo1.write(190);
        delay(500);
        servo1.detach();
        buttonPushCounter1 = 0;
      }
    }
  }
   if (buttonState2 != lastButtonState2)
   {
     // if the state has changed, increment the counter
     if (buttonState2 == LOW)
     {
       // if the current state is LOW then the button
       // went from off to on:
       buttonPushCounter2++;      
       if(buttonPushCounter2 == 1)
       {
         digitalWrite(15, LOW);
         digitalWrite(14, LOW);
         servo2.attach(servoPin2);
         servo2.write(4);
         delay(500);
         servo2.detach();
       }
       if(buttonPushCounter2 == 2)
       {
         digitalWrite(14, HIGH);
         digitalWrite(15, LOW);
         servo2.attach(servoPin2);
         servo2.write(190);
         delay(500);
         servo2.detach();
         buttonPushCounter2 = 0;
       }
     }
   }
    if (buttonState3 != lastButtonState3)
   {
     // if the state has changed, increment the counter
     if (buttonState3 == LOW)
     {
       // if the current state is LOW then the button
       // went from off to on:
       buttonPushCounter1++;
       buttonPushCounter2++;
       buttonPushCounter3++;      
       if(buttonPushCounter3 == 1)
       {
         digitalWrite(14, LOW);
         digitalWrite(15, LOW);
         digitalWrite(8, LOW);
         servo1.attach(servoPin1);
         servo2.attach(servoPin2);
         servo1.write(4);
         servo2.write(4);
         delay(500);
         servo1.detach();
         servo2.detach();
       }
       if(buttonPushCounter3 == 2)
       {
         digitalWrite(14, HIGH);
         digitalWrite(15, HIGH);
         digitalWrite(8, HIGH);
         servo1.attach(servoPin1);
         servo2.attach(servoPin2);
         servo1.write(190);
         servo2.write(190);
         delay(500);
         servo1.detach();
         servo2.detach();
         buttonPushCounter1 = 0;
         buttonPushCounter2 = 0;
         buttonPushCounter3 = 0;
       }
     }
   }  
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;
  lastButtonState3 = buttonState3;
}
