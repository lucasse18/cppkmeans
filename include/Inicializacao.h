#ifndef CPPK_MEANS_INICIALIZACAO_H
#define CPPK_MEANS_INICIALIZACAO_H


#include "Dataset.h"
#include "Exemplo.h"
#include "Centro.h"
#include <algorithm>

class Inicializacao {

public:
  virtual bool inicializa(Dataset *dados, vector<Centro> *centros) = 0;
  virtual ~Inicializacao() { }
};


#endif //CPPK_MEANS_INICIALIZACAO_H
