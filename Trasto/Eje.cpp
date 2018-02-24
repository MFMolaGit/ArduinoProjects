#include <Arduino.h>
#include "Eje.hpp"

Eje::Eje(int n) {
  //Serial.println("Instanciando Eje");
  pin = n;
}

void Eje::init() {
  //Serial.println("Inicializando Eje");
  servo.attach(pin);
  pos = 90;
  servo.write(pos);
  delay(1200);
  servo.detach();
}

void Eje::move(int nuevaPos) {
  //Serial.println("Moviendo Eje");
  servo.attach(pin);
  Serial.print("Se atacha pin ");
  Serial.println(pin);
  /*for (int i=0; i<abs(pos-nuevaPos); i++){
    delay(7);
    if(pos > nuevaPos) {
        Serial.print("Posicion nueva menor a posicion anterior");
        servo.write(pos - i);
    } else {
      Serial.print("Posicion nueva mayor a posicion anterior");
        servo.write(pos + i);
    }
  }*/
  servo.write(nuevaPos);
  pos = nuevaPos;
  //delay(15);
  servo.detach();
};
