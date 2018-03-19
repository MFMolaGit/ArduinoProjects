#include "Pata.hpp"

class Cuerpo {
  private:
    Pata** patas;
    int numPatas;
  public:
    Cuerpo();
    Cuerpo(int, int, int**, Adafruit_PWMServoDriver);
    void init();
    void move(int, int, int);
};
