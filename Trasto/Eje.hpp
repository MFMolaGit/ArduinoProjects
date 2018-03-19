#include <Adafruit_PWMServoDriver.h>
#include "Constantes.hpp"

class Eje {
  private: 
    Adafruit_PWMServoDriver controller;
    int id;
    int pin;
    int pos;
  public:
    Eje(int, int, Adafruit_PWMServoDriver);
    void init();
    void move(int);
    void printMove(int,int,int,int);
};
