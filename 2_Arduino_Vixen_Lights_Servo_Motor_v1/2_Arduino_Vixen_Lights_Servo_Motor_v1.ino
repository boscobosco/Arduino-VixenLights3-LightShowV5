#include <VarSpeedServo.h> 
 
VarSpeedServo myservo1;  // create servo object to control a servo 
                         // a maximum of eight servo objects can be created 
VarSpeedServo myservo2;
 
const int servoPin1 = 7; // the digital pin used for the first servo
const int servoPin2 = 8; // the digital pin used for the second servo

int data_input1 = A1; //Left Servo Motor Input data
int data_input2 = A2; //Rght Servo Motor Input data

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
  myservo1.attach(servoPin1);  // attaches the servo on pin 9 to the servo object
  myservo1.write(90,30,false); // set the intial position of the servo, as fast as possible, run in background
  myservo2.attach(servoPin2);  // attaches the servo on pin 9 to the servo object
  myservo2.write(0,30,false);  // set the intial position of the servo, as fast as possible, wait until done
  pinMode(data_input1, INPUT);
  pinMode(data_input2, INPUT);
  Serial.println("Start");
}

void loop() {
  int i1 = analogRead(data_input1); // i1 = data inputA1
  int d1 = i1/11.25275;  //degree, 1024/181 = 5.65746 OR 1024/91=11.25275
  int i2 = analogRead(data_input2); // i2 = data inputA2
  int d2 = i2/11.25275;  //degree, 1024/181 = 5.65746 OR 1024/91=11.25275
  /*Serial.print("input1=");
  Serial.println(i1);
  Serial.print("Angle1=");
  Serial.println(d1);
  Serial.print("input2=");
  Serial.println(i2);
  Serial.print("Angle2=");
  Serial.println(d2);*/

  if (d1<15){
    //Left Servo Motor @ 90 degree
    myservo1.write(90,50,false); //write(degrees 0-180, speed 1-255, wait to complete true-false
    }
 
  else{
    //Left Servo Motor @ 0 degree
    myservo1.write(0,40,false); //write(degrees 0-180, speed 1-255, wait to complete true-false
  }

 if (d2<15){
   //Right Servo Motor @ 0 degree
   myservo2.write(0,50,false); //write(degrees 0-180, speed 1-255, wait to complete true-false
  }
  else{
   //Right Servo Motor @ 90 degree
   myservo2.write(90,40,false); //write(degrees 0-180, speed 1-255, wait to complete true-false
  }
}
