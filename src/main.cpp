// I, Frank Kufer, student number 000805328, certify that this material is my
// original work. No other person's work has been used without due
// acknowledgement and I have not made my work available to anyone else.
#include <Arduino.h>

// boolean Toggele to switch ligh on or off
bool lastButtonState = false;   
// clickOnce variable is to restrict the button to change lastButtonState state so fast as the user is not up to the loop speed.
//and resolves unusual behaviour toggling the LED light ON or OFF.
int clickOnce=0;
void setup() {
  Serial.begin(115200); 

  // set default PWM range 
  analogWriteRange(1023); 

  // configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 

  // // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 



}



void loop() {
  int iButton = digitalRead(D5); 
  int iVal = analogRead(A0); 

 // check if button is pressed
  if(iButton==0 && clickOnce==0){
    //if true set the state to false 
    if(lastButtonState){
       lastButtonState=false;
    }
    //otherwise set state to true
    else if(lastButtonState==false){
      lastButtonState=true;
    }
    // change clickOnce to now is clicked by setting to int 1
    clickOnce=1;
  }

//check if button is true turn on the LED with 
  if(lastButtonState){
     analogWrite(D4, iVal);  
  }
  //otherwise turn off the LED
  else if (lastButtonState==false){
     digitalWrite(D4, HIGH );
  }
  // Once Button is released by the user switch to 0 so next time the user click will be able to switch light on or off.
  if(iButton==1 ){
    clickOnce=0;
  }
  
  
}