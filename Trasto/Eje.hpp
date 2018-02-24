#include <Servo.h>

class Eje {
  private:
    Servo servo;
    int pin;
    int pos;
  public:
    Eje(int);
    void init();
    void move(int);
};
