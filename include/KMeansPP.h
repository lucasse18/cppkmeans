#ifndef CPPKMEANS_KMEANSPP_H
#define CPPKMEANS_KMEANSPP_H


#include "Algoritmo.h"

class KMeansPP : public Algoritmo {

public:
  KMeansPP(Dataset *dados) : Algoritmo(dados) { }
};


#endif //CPPKMEANS_KMEANSPP_H
