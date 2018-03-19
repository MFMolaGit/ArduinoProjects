#include <Arduino.h>
#include <Wire.h>
#include "Eje.hpp"

Eje::Eje(int idEje, int n, Adafruit_PWMServoDriver controller) {
  id = idEje;
  
  #ifdef TRAZAS
  Serial.print("Instanciando Eje ");
  Serial.println(id);
  #endif
  
  pin = n;
}

void Eje::init() {
  #ifdef TRAZAS
  Serial.print("Inicializando Eje ");
  Serial.println(id);
  #endif
  
  /*servo.attach(pin);
  pos = 90;
  servo.write(pos);
  delay(1200);
  servo.detach();*/

  pos = 90;
  int pulselength = map(pos, 0, 180, SERVOMIN, SERVOMAX);
  printMove(id,pin,pulselength,pos);
  controller.setPWM(pin,0,pulselength);
  delay(1200);
}

void Eje::move(int nuevaPos) {
  #ifdef TRAZAS
  Serial.print("Moviendo Eje");
  Serial.print(id);
  Serial.print(" a posicion ");
  Serial.println(nuevaPos);
  #endif
  
  /*#ifdef TRAZAS
  Serial.print("Se atacha pin ");
  Serial.println(pin);
  #endif*/
  
  /*for (int i=0; i<abs(pos-nuevaPos); i++){
    delay(7);
    if(pos > nuevaPos) {
        servo.write(pos - i);
    } else {
        servo.write(pos + i);
    }
  }*/
  /*servo.write(nuevaPos);
  pos = nuevaPos;
  delay(1000);
  servo.detach();*/
  
  int pulselength = map(nuevaPos, 0, 180, SERVOMIN, SERVOMAX);
  controller.setPWM(pin,0,pulselength);
  pos = nuevaPos;
  printMove(id,pin,pulselength,pos);
  delay(1000);
};

void Eje::printMove(int id, int pin, int pulselength,int pos) {
  Serial.print("Moviendo eje ");
  Serial.print(id);
  Serial.print(" en canal ");
  Serial.print(pin);
  Serial.print(" con pulso ");
  Serial.print(pulselength);
  Serial.print(" (");
  Serial.print(pos);
  Serial.println(" grados)");
}
