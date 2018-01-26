#include <Servo.h>

class Pata {
  private:
    Servo servo1;
  public:
    Pata(int);
    void move(int n);
};

Pata::Pata(int pin) {
  servo1.attach(pin);
}

void Pata::move(int n) {
  servo1.write(n);
};
