/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

int sensorPin0 = A0;
int sensorValue0 = 0;
int sensorPin1 = A1;
int sensorValue1 = 0;
int sensorPin2 = A2;
int sensorValue2 = 0;
int sensorPin3 = A3;
int sensorValue3 = 0;
int sensorPin4 = A4;
int sensorValue4 = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  fireLaser();
  sensorValue0 = analogRead(sensorPin0);
  sensorValue1 = analogRead(sensorPin1);
  Serial.print("Sensor0: ");
  Serial.println(sensorValue0);
  Serial.print("Sensor1: ");
  Serial.println(sensorValue1); 
  if ((sensorValue0 > 500) || (sensorValue1 > 500)){
    Serial.println("Hit");
  }
  else {
    Serial.println("Miss");
  } 
  delay(100);
}

void fireLaser() { 
  digitalWrite(13, HIGH); 
}
