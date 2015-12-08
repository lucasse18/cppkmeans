#ifndef CPPK_MEANS_INICIALIZACAO_H
#define CPPK_MEANS_INICIALIZACAO_H


#include "Dataset.h"

class Inicializacao {

public:
  virtual ~Inicializacao() { }

  virtual bool inicializa(Dataset *dados) = 0;
};


#endif //CPPK_MEANS_INICIALIZACAO_H
