#include "Eje.hpp"

class Pata {
  private:
    int id;
    Eje** ejes;   
    int numEjes;
  public:
    Pata(int, int, int*);
    void init();    
    void move(int, int);
};
