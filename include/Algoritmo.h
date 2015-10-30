#ifndef CPPK_MEANS_ALGORITMO_H
#define CPPK_MEANS_ALGORITMO_H


#include "Inicializacao.h"
#include "Iteracao.h"

class Algoritmo {

private:
  Inicializacao *ini;
  Iteracao *itr;
  int inicializar();
  int iterar();

public:
  Algoritmo(Inicializacao *ini, Iteracao *itr);
  int rodar();
  virtual ~Algoritmo();
};


#endif //CPPK_MEANS_ALGORITMO_H
