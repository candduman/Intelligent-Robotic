#include <Servo.h>
Servo M1,M2;

int Th1, Th2, tmp;

void setup() 
{
  Serial.begin(9600); //Soracak 
  pinMode(13,OUTPUT); 
  digitalWrite(13,0);
  Th1 = 0;
  Th2 = 0;
  M1.attach(A1);
  M2.attach(A2);
  M1.write(90);
  M2.write(90);
}

void loop() 
{
  delay(200);// c# daha yavaş olmalı.

  if(Serial.available()>=2)// soracak
  {
    Th1 = Serial.read();// read only one byte;
    Th2 = Serial.read();//soracak

    //Remove any extra worng reading
    while(Serial.available()) tmp = Serial.read();    
    
    // Run the robotic arm here. For testing, we will 
    M1.write(Th1);
    M2.write(Th2);
    digitalWrite(13,1);
    delay(500);
    digitalWrite(13,0);
   
    //switch On or switch off a LED according to Th1 value
   
  }
}
