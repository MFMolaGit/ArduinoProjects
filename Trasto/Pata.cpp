#include <Arduino.h>
#include "Pata.hpp"

Pata::Pata(int idPata, int n, int* pins, Adafruit_PWMServoDriver controller) {
  id = idPata;
  
  #ifdef TRAZAS  
  Serial.print("Instanciando Pata ");
  Serial.println(id);
  #endif
  
  numEjes = n;
  ejes = new Eje*[numEjes];
  for (int i = 0; i < numEjes; i++) {
      ejes[i] = new Eje(i+1, pins[i], controller);
  }
}

void Pata::init() {
  #ifdef TRAZAS  
  Serial.print("Inicializando Pata ");
  Serial.println(id);
  #endif
  
  for (int i = 0; i < numEjes; i++) {
      ejes[i]->init();
  }
}

void Pata::move(int numEje, int nuevaPos) {
  #ifdef TRAZAS
  Serial.print("Moviendo Pata ");
  Serial.println(id);
  #endif
  
  ejes[numEje-1]->move(nuevaPos);  
};
