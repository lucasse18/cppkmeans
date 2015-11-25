#ifndef CPPK_MEANS_ALGORITMO_H
#define CPPK_MEANS_ALGORITMO_H


#include "Inicializacao.h"
#include "Iteracao.h"
#include "kmeans.h"

class KMeans {

private:
  Dataset *dados;
  Inicializacao *ini;
  Iteracao *itr;

public:
  KMeans(Dataset *dados);
  virtual ~KMeans();

  virtual bool rodar() final;
  virtual bool hookSalvar();

  Dataset * getDados() const;
  void setDados(Dataset *dados);
  Inicializacao * getIni() const;
  void setIni(Inicializacao *ini);
  Iteracao * getItr() const;
  void setItr(Iteracao *itr);
};


#endif //CPPK_MEANS_ALGORITMO_H
