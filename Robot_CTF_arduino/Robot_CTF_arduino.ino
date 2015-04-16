//This motor shield use Pin 6,5,7,4 to control the motor
// Simply connect your motors to M1+,M1-,M2+,M2-
// Upload the code to Arduino/Roboduino
// Through serial monitor, type 'a','s', 'w','d','x' to control the motor
// www.dfrobot.com
// Last modified on 24/12/2009
 
int EN1 = 6; 
int EN2 = 5;  //Roboduino Motor shield uses Pin 9
int IN1 = 7;
int IN2 = 4; //Latest version use pin 4 instead of pin 8

int can_move = 1;
int can_turn = 1;

void setup()
{
    int i;
   // for(i=6;i<=9;i++) //For Roboduino Motor Shield
   // pinMode(i, OUTPUT);  //set pin 6,7,8,9 to output mode
 
    for(i=4;i<=7;i++)  //For Arduino Motor Shield
    pinMode(i, OUTPUT);  //set pin 4,5,6,7 to output mode
 
    pinMode(13, OUTPUT);  // Initialize pin 13 as output for laser
    pinMode(12, OUTPUT);  
    pinMode(7, OUTPUT);   //lives
    pinMode(8, OUTPUT);   
    pinMode(9, OUTPUT);   
    
    digitalWrite(12, HIGH);  

    Serial.begin(115200);  
    
    can_move = 1;
    can_turn = 1;
}
 
int forward = 0;
int turn = 0;
int i = 0;
int flashing = 0;
void loop()
{

//  int x;

//    Serial.print(i++);
  if(Serial.available()>0)
  {
    char x = Serial.read();
    
    Serial.print(x);
    
    if (x >= 'a' && x <= 'u') { //if forward
      forward = ('k' - x) * 10;
    } else if (x >= 'A' && x <= 'U') { //if forward
      turn = ('K' - x) * 10;
    } else if (x == 'z') {
      fireLaser(); 
    } else if (x == '0') {
      digitalWrite(7, LOW); 
      digitalWrite(8, LOW); 
      digitalWrite(9, LOW);  
    } else if (x == '1') {
      digitalWrite(7, HIGH); 
      digitalWrite(8, LOW); 
      digitalWrite(9, LOW);  
    } else if (x == '2') {
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, LOW);  
    } else if (x == '3') {
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH);  
    }
    
    
    
    
    //left wheel
    
    
    int left = forward;
    int right = forward;
    
    
    if (turn < 0) {
      right += turn;
    } else {
       left -= turn; 
    }
    
    
    if (left < 0) {
      Motor1(-left, false);
    } else {
      Motor1(left, true);
    }
    //right wheel
    
    if (right < 0) {
      Motor2(-right, false);
    } else {
      Motor2(right, true);
    }
    
  }
    
    int sensorValue1 = analogRead(A1);
    int sensorValue4 = analogRead(A4);
    
//        Serial.print(sensorValue1);
//        Serial.print(sensorValue4);
    if ((sensorValue1 > 500) || (sensorValue4 > 500)) {
//      if (random(1,10) == 1)
//        if (flashing == 0) {
//        flashing = 1;
        digitalWrite(8, HIGH);
//        delay(300);
//        digitalWrite(8, LOW);
//        delay(100);
//        digitalWrite(8, HIGH);
//        delay(300);
//        digitalWrite(8, LOW);
//        delay(100);
//        digitalWrite(8, HIGH);
//        delay(300);
//        digitalWrite(8, LOW);
//        delay(100);
//        digitalWrite(8, HIGH);
//        delay(300);
//        digitalWrite(8, LOW);
//        delay(100);
//        }
//        flashing = 0;
    }                    
}

 
void Motor1(int pwm, boolean reverse)
        {
          analogWrite(EN1,pwm); //set pwm control, 0 for stop, and 255 for maximum speed
         if(reverse)
         {
          digitalWrite(IN1,HIGH);   
         }
        else
        {
          digitalWrite(IN1,LOW);   
         }
        } 
         
void Motor2(int pwm, boolean reverse)
        {
          analogWrite(EN2,pwm);
         if(reverse)
         {
          digitalWrite(IN2,HIGH);   
         }
        else
        {
          digitalWrite(IN2,LOW);   
         }
        } 
        

// Call method when fire laser command has been read in through blue tooth
void fireLaser() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
}

