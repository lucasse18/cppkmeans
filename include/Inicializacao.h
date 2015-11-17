#ifndef CPPK_MEANS_INICIALIZACAO_H
#define CPPK_MEANS_INICIALIZACAO_H


#include "Dataset.h"
#include "kmeans.h"

class Inicializacao {

public:
  virtual ~Inicializacao() { }

  bool inicializaSimples(Dataset *dados);
  bool inicializaPP(Dataset *dados);
};


#endif //CPPK_MEANS_INICIALIZACAO_H
