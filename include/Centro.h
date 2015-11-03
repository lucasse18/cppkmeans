#ifndef CPPKMEANS_CENTRO_H
#define CPPKMEANS_CENTRO_H


//TODO fazer superclasse para centros e exemplos
#include <vector>

using namespace std;

class Centro {

private:
  vector<float> atributos;
  long qtdExemplos;

public:
  vector<float> & getAtributos();
  void setAtributo(float atributo, unsigned pos);
  long getQtdExemplos() const;
  void setQtdExemplos(long qtdExemplos);
};


#endif //CPPKMEANS_CENTRO_H
