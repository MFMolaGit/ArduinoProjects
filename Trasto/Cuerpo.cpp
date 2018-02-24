#include <Arduino.h>
#include "Cuerpo.hpp"

Cuerpo::Cuerpo() {}

Cuerpo::Cuerpo(int n, int m, int **pinsPorPata) {
  
  #ifdef TRAZAS
  Serial.println("Instanciando cuerpo con ");
  Serial.print(n);
  Serial.print(" Patas y ");
  Serial.print(m);
  Serial.println(" Ejes por Pata");
  #endif
  
  numPatas = n;
  patas = new Pata*[numPatas];
  for (int i = 0; i < numPatas; i++) {
    patas[i] = new Pata(i+1, m, pinsPorPata[i]);
  }
}

void Cuerpo::init() {
  
  #ifdef TRAZAS
  Serial.println("Inicializando cuerpo");
  #endif
  
  for (int i = 0; i < numPatas; i++) {
      patas[i]->init();
  }
}

void Cuerpo::move(int numPata, int numEje, int nuevaPos) {
  
  #ifdef TRAZAS
  Serial.println("Moviendo cuerpo");
  #endif
  
  patas[numPata-1]->move(numEje, nuevaPos);  
};
