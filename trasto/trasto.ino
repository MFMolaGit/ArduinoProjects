#include "pata.cpp"
 
Pata pata(11);    // Nombre asignado al servo
int angulo;                // Variable de almacenamiento del angulo ingresado por Monitor Serial

void loop() {
  if (Serial.available()) {   // Verificacion que el puerto serial recibe datos                                  
   delay(10);               
   angulo = Serial.parseInt(); // Lee solo los datos tipo int del buffer
   //pata.move(angulo); // Escritura de microsegundos ingresado por Monitor Serial
    
   // Mensaje de confirmacion del angulo ingresado por Monitor Serial
   Serial.print("Posicion angular: "); 
   Serial.print(angulo);
   Serial.println(" grados");
    
    while (Serial.available() > 0){Serial.read();} // Rutina de limpieza del buffer del puerto serial
  }
}
