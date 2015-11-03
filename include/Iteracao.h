#ifndef CPPK_MEANS_ITERACAO_H
#define CPPK_MEANS_ITERACAO_H


#include "Dataset.h"
#include "Distancia.h"
#include "Exemplo.h"
#include "Centro.h"

class Iteracao {

public:
  virtual bool itera(Dataset *dados, vector<Centro> *centros) = 0;
  virtual ~Iteracao() { }
};


#endif //CPPK_MEANS_ITERACAO_H
