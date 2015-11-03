#ifndef CPPK_MEANS_EXEMPLO_H
#define CPPK_MEANS_EXEMPLO_H


//TODO fazer superclasse para centros e exemplos
#include <vector>

using namespace std;

class Exemplo {
private:
  vector<float> atributos;
  unsigned centro;

public:
  vector<float> & getAtributos();
  unsigned int getCentro() const;
  void setCentro(unsigned int centro);
};


#endif //CPPK_MEANS_EXEMPLO_H
