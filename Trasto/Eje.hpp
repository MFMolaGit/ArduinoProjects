#include <Adafruit_PWMServoDriver.h>
#include "Constantes.hpp"

class Eje {
  private:    
    int id;
    int pin;
    int pos;
  public:
    static Adafruit_PWMServoDriver controller;
    Eje(int,int);
    void init();
    void move(int);
};
