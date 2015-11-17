#ifndef CPPK_MEANS_ITERACAO_H
#define CPPK_MEANS_ITERACAO_H


#include "Dataset.h"
#include "kmeans.h"

class Iteracao {

public:
  virtual ~Iteracao() { }
  bool iteraSimples(Dataset *dados);
  bool iteraYinYang(Dataset *dados);
};


#endif //CPPK_MEANS_ITERACAO_H
