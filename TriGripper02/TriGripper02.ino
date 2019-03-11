#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

int pot;

int bend1;
int bend2;
int bend3;

int servoOut1;
int servoOut2;
int servoOut3;

int force1;
int force2;
int force3;

int forceDemand1;

void setup() {

  Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);

  servoOut1 = 550;
  servoOut2 = 550;
  servoOut3 = 550;

}

void loop() {

  pot = analogRead(0);
  
  bend1 = analogRead(1);
  bend2 = analogRead(2);
  bend3 = analogRead(3);

  bend1 = map(bend1,508,392,550,1200);
  bend2 = map(bend2,531,420,550,1200);
  bend3 = map(bend3,507,398,550,1200);

  force1 = servoOut1 - bend1;
  force2 = servoOut2 - bend2;
  force3 = servoOut3 - bend3;

  force1 = map(force1, 0,1900,0,1023);
  force2 = map(force2, 0,1900,0,1023);
  force3 = map(force3, 0,1900,0,1023);

  if (pot > force1) {
    servoOut1 = servoOut1 + 20;
  }
  else {
    servoOut1 = servoOut1 - 20;
  }

  if (pot > force2) {
    servoOut2 = servoOut2 + 20;
  }
  else {
    servoOut2 = servoOut2 - 20;
  }

  if (pot > force3) {
    servoOut3 = servoOut3 + 20;
  }
  else {
    servoOut3 = servoOut3 - 20;
  }


  Serial.print(pot);
  Serial.print('\t');
  Serial.print("bends: ");
  Serial.print(bend1);
  Serial.print('\t');
  Serial.print(bend2);
  Serial.print('\t');
  Serial.print(bend3);
  Serial.print('\t');
  Serial.print("servos: ");
  Serial.print(servoOut1);
  Serial.print('\t');
  Serial.print(servoOut2);
  Serial.print('\t');
  Serial.print(servoOut2);
  Serial.print('\t');
  Serial.print("force: ");
  Serial.print(force1);
  Serial.print('\t');
  Serial.print(force2);
  Serial.print('\t');
  Serial.println(force3);

  servoOut1 = constrain(servoOut1,550,2400);
  servoOut2 = constrain(servoOut2,550,2400);
  servoOut3 = constrain(servoOut3,250,2400);
  
  servo1.writeMicroseconds(servoOut1);
  servo2.writeMicroseconds(servoOut2);
  servo3.writeMicroseconds(servoOut3);

}
