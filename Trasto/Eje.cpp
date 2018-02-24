#include <Arduino.h>
#include "Eje.hpp"

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
  
  servo.attach(pin);
  pos = 90;
  servo.write(pos);
  delay(1200);
  servo.detach();
}

void Eje::move(int nuevaPos) {
  #ifdef TRAZAS
  Serial.print("Moviendo Eje");
  Serial.print(id);
  Serial.print(" a posicion ");
  Serial.println(nuevaPos);
  #endif
  
  servo.attach(pin);
  
  #ifdef TRAZAS
  Serial.print("Se atacha pin ");
  Serial.println(pin);
  #endif
  
  for (int i=0; i<abs(pos-nuevaPos); i++){
    delay(7);
    if(pos > nuevaPos) {
        servo.write(pos - i);
    } else {
        servo.write(pos + i);
    }
  }
  servo.write(nuevaPos);
  pos = nuevaPos;
  delay(15);
  servo.detach();
};
