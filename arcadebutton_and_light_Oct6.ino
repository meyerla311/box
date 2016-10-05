/* sketch 1 
turn on a LED when the button is pressed
turn it off when the button is not pressed (or released)
*/
int pinRedButton = 8; //the pin we connect the button
//int RedLight = 13; // the pin we connect to the LED

int pinGreenButton = 11; 
//int GreenLight = 12;
//
int pinToggle = 9; 
int ToggleLight = 10;
//
int pinYellowButton = 2; 
//int YellowLight = 3;
//
int pinBlueButton = 6; 
//int BlueLight = 7;
//
unsigned long timeGreenButton;
unsigned long timeYellowButton;
unsigned long timeRedButton;
unsigned long timeBlueButton;
unsigned long timeLastSwitch = millis();
int wait = 300;

int redindex = 0;
int blueindex = 1;
int greenindex = 2;
int yellowindex = 3;
int Light[] = {13,3,12,7}; 

//
int potentioValue = 0; //Value of Potentiometer

void setup() {

Serial.begin(9600);
  
  // put your setup code here, to run once:
  // www.electroschematics.com/8964/turn-on-led-button-arduino/
  pinMode(pinRedButton, INPUT); //set the button pin as INPUT
  pinMode(Light[redindex], OUTPUT); // 
  //
  pinMode(pinGreenButton, INPUT); //set the button pin as INPUT
  pinMode(Light[greenindex], OUTPUT); // 
   //
  pinMode(pinYellowButton, INPUT); //set the button pin as INPUT
  pinMode(Light[yellowindex], OUTPUT); // 
  //
  pinMode(pinBlueButton, INPUT); //set the button pin as INPUT
  pinMode(Light[blueindex], OUTPUT); //  
  //
  pinMode(pinToggle, INPUT); //set the button pin as INPUT
  pinMode(ToggleLight, OUTPUT); // 
  //
  pinMode(A0,INPUT); 
pinMode(5, OUTPUT); // we select any PWM pin the ones with this sign “~”
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int stateRedButton = digitalRead(pinRedButton); //read the state of the button
  if(stateRedButton == 1) { //if is pressed
 timeRedButton=millis();
    digitalWrite(Light[redindex], HIGH); //write 1 or HIGH to led pin
  }
  if(millis()-timeRedButton>1000){
    digitalWrite(Light[redindex], LOW);
  }
  //Fenia
  int stateGreenButton = digitalRead(pinGreenButton); //read the state of the button
  if(stateGreenButton == 1) { //if is pressed
    timeGreenButton=millis();
    digitalWrite(Light[greenindex], HIGH); //write 1 or HIGH to led pin
  }
  if(millis()-timeGreenButton>1000){
    digitalWrite(Light[greenindex], LOW);
}
/*
  int stateToggle = digitalRead(pinToggle); //read the state of the button
  if(stateToggle == 1) { //if is pressed
    digitalWrite(RedLight, HIGH);
    delay(wait);
    digitalWrite(RedLight, LOW);
    digitalWrite(GreenLight, HIGH);
    delay(wait);
    digitalWrite(GreenLight, LOW);
    digitalWrite(BlueLight, HIGH);
    delay(wait);
    digitalWrite(BlueLight, LOW);
    digitalWrite(YellowLight, HIGH);
    delay(wait);
    digitalWrite(YellowLight, LOW);
    digitalWrite(ToggleLight, HIGH);
    delay(wait);
    digitalWrite(ToggleLight, LOW);
    digitalWrite(ToggleLight, HIGH); //write 1 or HIGH to led pin
    delay(wait); // waits for a second
    digitalWrite(ToggleLight, LOW);
    digitalWrite(RedLight, HIGH);
    digitalWrite(GreenLight, HIGH);
    digitalWrite(BlueLight, HIGH);
    digitalWrite(YellowLight, HIGH);
    digitalWrite(ToggleLight, HIGH);
    delay(600);
    digitalWrite(RedLight, LOW);
    digitalWrite(GreenLight, LOW);
    digitalWrite(BlueLight, LOW);
    digitalWrite(YellowLight, LOW);
    digitalWrite(ToggleLight, LOW);

    
  }
  */
//
  int stateYellowButton = digitalRead(pinYellowButton); //read the state of the button
  if(stateYellowButton == 1) { //if is pressed
    timeYellowButton=millis();
    digitalWrite(Light[yellowindex], HIGH); //write 1 or HIGH to led pin
  }
   
  if(millis()-timeYellowButton>1000){
    digitalWrite(Light[yellowindex], LOW);
  }
  
  int stateBlueButton = digitalRead(pinBlueButton); //read the state of the button
  if(stateBlueButton == 1) { //if is pressed
   timeBlueButton=millis();
    digitalWrite(Light[blueindex], HIGH); //write 1 or HIGH to led pin
  }
  
  if(millis()-timeBlueButton>1000){
    digitalWrite(Light[blueindex], LOW); 
  }

if (millis()-timeLastSwitch > 5000){
  Serial.println("start loop");
  timeLastSwitch = millis();
  redindex = random(0,4);
   Serial.println("red index");
   Serial.print(redindex);

  while(yellowindex == redindex) { 
    yellowindex = random(0,4);
   Serial.println("yellow index");
   Serial.print(yellowindex);
    }
   while(greenindex == redindex || greenindex == yellowindex) { 
    greenindex = random(0,4);
   Serial.println("green index");
   Serial.print(greenindex);
    } 
   while(blueindex == redindex || blueindex == yellowindex || blueindex == greenindex) { 
    blueindex = random(0,4);
   Serial.println("blue index");
   Serial.print(blueindex);
    } 
  
  
  }
  
}


  
