#include <Arduino.h>
#include "Pata.hpp"

Pata::Pata(int n, int* pins) {
  //Serial.println("Instanciando Pata");
  numEjes = n;
  ejes = new Eje*[numEjes];
  for (int i = 0; i < numEjes; i++) {
      ejes[i] = new Eje(pins[i]);
  }
}

void Pata::init() {
  //Serial.println("Inicializando Pata");
  for (int i = 0; i < numEjes; i++) {
      ejes[i]->init();
  }
}

void Pata::move(int numEje, int nuevaPos) {
  /*Serial.print("Moviendo Eje ");
  Serial.print(numEje);
  Serial.print(" a posicion ");
  Serial.println(nuevaPos);*/
  ejes[numEje-1]->move(nuevaPos);  
};
