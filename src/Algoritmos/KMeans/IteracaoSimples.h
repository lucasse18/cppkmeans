#ifndef CPPKMEANS_ITERACAOSIMPLES_H
#define CPPKMEANS_ITERACAOSIMPLES_H


#include "Iteracao.h"

class IteracaoSimples : public Iteracao {

public:
  virtual bool itera(Dataset *dados);
};


#endif //CPPKMEANS_ITERACAOSIMPLES_H
