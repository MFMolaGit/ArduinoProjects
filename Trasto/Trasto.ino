#include "Cuerpo.hpp"

#define PATAS 1
#define EJES 1

int** initParams() {
  int **pins = pins = new int*[PATAS];
  for (int i = 0; i < PATAS; i++) {
    pins[i] = new int[EJES];
  }

  pins[0][0] = 8; //Pata 1 Eje 1 => Pin 8
  
  return pins;
}

Cuerpo *cuerpo;
int angulo;

void setup() {  
  Serial.begin(9600);
  cuerpo = new Cuerpo(1,1,initParams());
  cuerpo->init();
  // Mensaje inicial en el monitor serial
  Serial.println("Escribir la posicion de angulo de 0 a 180: ");
}

void loop() {
  if (Serial.available()) {   // Verificacion que el puerto serial recibe datos                                  
   delay(10);
 
   angulo = Serial.parseInt(); // Lee solo los datos tipo int del buffer
   if(angulo > 1) {
     cuerpo->move(1,1, angulo);
   }
      
   // Mensaje de confirmacion del angulo ingresado por Monitor Serial
   Serial.print("Posicion angular: "); 
   Serial.print(angulo);
   Serial.println(" grados");

   // Rutina de limpieza del buffer del puerto serial
   while (Serial.available() > 0) {
    Serial.read();
   }
  }
}

