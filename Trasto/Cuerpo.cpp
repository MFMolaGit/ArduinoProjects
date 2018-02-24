#include <Arduino.h>
#include "Cuerpo.hpp"

Cuerpo::Cuerpo() {}

Cuerpo::Cuerpo(int n, int m, int **pinsPorPata) {
  //Serial.println("Instanciando cuerpo");
  numPatas = n;
  patas = new Pata*[numPatas];
  for (int i = 0; i < numPatas; i++) {
    patas[i] = new Pata(m,pinsPorPata[i]);
  }
}

void Cuerpo::init() {
  //Serial.println("Inicializando cuerpo");
  for (int i = 0; i < numPatas; i++) {
      patas[i]->init();
  }
}

void Cuerpo::move(int numPata, int numEje, int nuevaPos) {
  //Serial.println("Moviendo cuerpo");
  /*Serial.print("Moviendo Eje ");
  Serial.print(numEje);
  Serial.print(" de Pata ");
  Serial.print(numPata);
  Serial.print(" a posicion ");
  Serial.println(nuevaPos);*/
  patas[numPata-1]->move(numEje, nuevaPos);  
};
