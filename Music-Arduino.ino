/* Written by Brihi Joshi, in reference to www.arduino.cc for the working of the various sensors used.*/

#include <Servo.h>
Servo servo1;
int buzzpin=9; //The output from the Piezzo Buzzer!
int sensorPin = A1;   // select the input pin for ldr
int sensorValue = 0;  // variable to store the value coming from the LDR sensor
const int flexpin = 0; 
int flexposition = A0;    // Input value from the analog pin of the Flex Sensor
int servoposition = 0;


#Describing the musical notes and mapping them to the frequencies
#define C1 262
#define D 294
#define E 330
#define F 349
#define G 392
#define A 440
#define B 494
#define C2 523
#define trigPin 7 //The input pin for the Ultrasonic Sensor
#define echoPin 2 // The output pin for the Ultrasonic Sensor

void setup() {
  Serial.begin (9600); // The command to print the output values on the serial screen
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(2, OUTPUT); //pin connected to the relay
  servo1.attach(9);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344; // Used to calculate the distance from the time readings taken by the Ultrasonic Sensor
  sensorValue = analogRead(sensorPin); 
  flexposition = analogRead(flexpin);
  servoposition = map(flexposition, 600, 900, 0, 180); // Mapping the Servo values to the angles by which the Flex Sensor bends
  servoposition = constrain(servoposition, 0, 180);
  servo1.write(servoposition);

 /*Given below are loop mappings of the readings from the three sensors with the allootted notes. 
 This can be done according to the coder as well.*/
 
if(distance < 9 || sensorValue<250 || servoposition <70) {
   tone(9,C1); //The tone function is used to play the frequency using the piezzo buzzer.
   delay(500);
  noTone(buzzpin);
  } 
  else if(distance<14 || sensorValue<350 || servoposition<85)  {
    tone(9,D);
    delay(500);
  noTone(buzzpin);
  }
  else if(distance<19 || sensorValue<450 || servoposition<100){
    tone(9,E);
    delay(500);
  noTone(buzzpin);
  }
  else if(distance<24 || sensorValue<550 || servoposition<115){
    tone(9,F);
    delay(500);
  noTone(buzzpin);
  }
  else if(distance<29 || sensorValue<650 || servoposition<130){
    tone(9,G);
    delay(1000);
  noTone(buzzpin);
  }
  else if(distance<34 || sensorValue<750 || servoposition<145){
    tone(9,A);
    delay(1000);
  noTone(buzzpin);
  }
  else if(distance<39 || sensorValue<850 || servoposition<160){
    tone(9,B);
    delay(1000);
  noTone(buzzpin);
  }
  else {
    tone(9,C2);
    delay(1000);
  noTone(buzzpin);
  }
}

