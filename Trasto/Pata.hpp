#include "Eje.hpp"

class Pata {
  private:
    Eje** ejes;
    int numEjes;
  public:
    Pata(int, int*);
    void init();    
    void move(int, int);
};
