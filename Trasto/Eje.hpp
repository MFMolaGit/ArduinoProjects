#include <Servo.h>
#include "Constantes.hpp"

class Eje {
  private:
    Servo servo;
    int id;
    int pin;
    int pos;
  public:
    Eje(int,int);
    void init();
    void move(int);
};
