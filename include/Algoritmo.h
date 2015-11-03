#ifndef CPPK_MEANS_ALGORITMO_H
#define CPPK_MEANS_ALGORITMO_H


#include "Inicializacao.h"
#include "Iteracao.h"
#include "Exemplo.h"

class Algoritmo {

private:
  Dataset *dados;
  vector<Centro> centros;
  Inicializacao *ini;
  Iteracao *itr;
  bool inicializar();
  bool iterar();

public:
  Algoritmo(Dataset *dados, Inicializacao *ini, Iteracao *itr);
  bool rodar();
  virtual ~Algoritmo();
};


#endif //CPPK_MEANS_ALGORITMO_H
