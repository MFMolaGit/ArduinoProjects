#include <Arduino.h>
#include "Eje.hpp"

Adafruit_PWMServoDriver Eje::controller = Adafruit_PWMServoDriver(0x40);

Eje::Eje(int idEje, int n) {
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

  controller.begin(); 
  controller.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
  
  /*servo.attach(pin);
  pos = 90;
  servo.write(pos);
  delay(1200);
  servo.detach();*/

  int pulselength = map(90, 0, 180, SERVOMIN, SERVOMAX);
  controller.setPWM(pin,0,pulselength);
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
};
