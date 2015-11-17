#ifndef CPPK_MEANS_ALGORITMO_H
#define CPPK_MEANS_ALGORITMO_H


#include "Inicializacao.h"
#include "Iteracao.h"
#include "kmeans.h"

class Algoritmo {

private:
  Dataset *dados;
  Inicializacao *ini;
  Iteracao *itr;

public:
  Algoritmo(Dataset *dados);
  virtual bool rodar() = 0;
  virtual bool salvar() = 0;
  Inicializacao * getIni() const;
  void setIni(Inicializacao *ini);
  Iteracao * getItr() const;
  void setItr(Iteracao *itr);

  virtual ~Algoritmo();
};


#endif //CPPK_MEANS_ALGORITMO_H
