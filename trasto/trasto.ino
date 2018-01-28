#include <Servo.h>

class Pata {
  private:
    int pin;
    int pos;
  public:
    Pata(int);
    void move(int n);
    void init();
};

Servo servo1;
int angulo;


Pata::Pata(int n) {
  pin = n;
}

void Pata::init() {
  servo1.attach(pin);
  pos = 90;
  servo1.write(pos);
}

void Pata::move(int n) {
  for (int i=0; i<abs(pos-n); i++){
    delay(7);
    if(pos > n) {
        servo1.write(pos - i);
    } else {
        servo1.write(pos + i);
    }
  }
  pos = n;
};

Pata pata(11);

void setup() {
  Serial.begin(9600);
  pata.init();
  // Mensaje inicial en el monitor serial
  Serial.println("Escribir la posicion de angulo de 0 a 180: ");
}

void loop() {
  if (Serial.available()) {   // Verificacion que el puerto serial recibe datos                                  
   delay(10);
 
   angulo = Serial.parseInt(); // Lee solo los datos tipo int del buffer
   pata.move(angulo); // Escritura de microsegundos ingresado por Monitor Serial
   
   // Mensaje de confirmacion del angulo ingresado por Monitor Serial
   Serial.print("Posicion angular: "); 
   Serial.print(angulo);
   Serial.println(" grados");
    
    while (Serial.available() > 0){Serial.read();} // Rutina de limpieza del buffer del puerto serial
  }
}

