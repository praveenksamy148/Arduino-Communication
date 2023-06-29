#include <Stepper.h>
#include <SoftwareSerial.h>

const byte rxPin = 4;
const byte txPin = 5;
const int stepsPerRevolution = 2038;
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
SoftwareSerial mySerial (rxPin, txPin);
int direction = 1;

void setup()
{
  // put your setup code here, to run once:
Serial.begin (9600);
mySerial.begin (9600);
Serial.println("started Slave-2");
myStepper.setSpeed(8);
}

void loop() {
  // put your main code here, to run repeatedly:
if(mySerial.available())
{
  char rc= mySerial.read();
 Serial.println(rc);
  if(rc=='1')
    direction = 1;
   else if(rc=='2'){
    direction =-1;
   }
   else if(rc == '3'){
     direction = 0; 
   }
   
}
  myStepper.step(direction*100);
}