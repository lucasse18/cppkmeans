#ifndef CPPK_MEANS_ITERACAO_H
#define CPPK_MEANS_ITERACAO_H


#include "Dataset.h"
#include "kmeans.h"

class Iteracao {

public:
  virtual ~Iteracao() { }

  virtual bool itera(Dataset *dados) = 0;
};


#endif //CPPK_MEANS_ITERACAO_H
