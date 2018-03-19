#include "Eje.hpp"

class Pata {
  private:
    int id;
    Eje** ejes;   
    int numEjes;
  public:
    Pata(int, int, int*, Adafruit_PWMServoDriver);
    void init();    
    void move(int, int);
};
