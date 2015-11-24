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

  virtual bool rodar();
  bool salvar();

  Dataset * getDados() const;
  void setDados(Dataset *dados);
  Inicializacao * getIni() const;
  Iteracao * getItr() const;

};


#endif //CPPK_MEANS_ALGORITMO_H
