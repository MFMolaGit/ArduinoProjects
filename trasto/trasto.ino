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

Servo servos[14];
int angulo;

Pata::Pata(int n) {
  pin = n;
}

void Pata::init() {
  servos[pin].attach(pin);
  pos = 90;
  servos[pin].write(pos);
  delay(1200);
  servos[pin].detach();
}

void Pata::move(int n) {
  servos[pin].attach(pin);
  for (int i=0; i<abs(pos-n); i++){
    delay(7);
    if(pos > n) {
        servos[pin].write(pos - i);
    } else {
        servos[pin].write(pos + i);
    }
  }
  servos[pin].write(n);
  pos = n;
  delay(15);
  servos[pin].detach();
};

Pata pata1(8);

void setup() {
  Serial.begin(9600);
  pata1.init();
  // Mensaje inicial en el monitor serial
  Serial.println("Escribir la posicion de angulo de 0 a 180: ");
}

void loop() {
  if (Serial.available()) {   // Verificacion que el puerto serial recibe datos                                  
   delay(10);
 
   angulo = Serial.parseInt(); // Lee solo los datos tipo int del buffer
   if(angulo > 1) {
     pata1.move(angulo);
   }
   
   
   // Mensaje de confirmacion del angulo ingresado por Monitor Serial
   Serial.print("Posicion angular: "); 
   Serial.print(angulo);
   Serial.println(" grados");
    
    while (Serial.available() > 0){Serial.read();} // Rutina de limpieza del buffer del puerto serial
  }
}

