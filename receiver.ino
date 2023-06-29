#include <SoftwareSerial.h>

const byte rxPin = 2;
const byte txPin = 3;
SoftwareSerial mySerial (rxPin, txPin);
SoftwareSerial mySerial2(4,5);

void setup()
{
  // put your setup code here, to run once:
Serial.begin (9600);
mySerial.begin (9600);
mySerial2.begin(9600);
Serial.println("started Master");
}

void loop() {
  char rc1, rc2;
  // put your main code here, to run repeatedly:
if(Serial.available()){
  rc1 = Serial.read();
  // delay(100);
  while(true){
    if(Serial.available()){
      rc2 = Serial.read();
      break;
    }
  }



  Serial.println(rc1);
  Serial.println(rc2);
    if(rc1 == '1'){
      mySerial.write(rc2);
    }
    else if(rc1 == '2'){
      mySerial2.write(rc2);
    }
    // delay(100);
}
}