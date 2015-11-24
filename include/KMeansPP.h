#ifndef CPPKMEANS_KMEANSPP_H
#define CPPKMEANS_KMEANSPP_H


#include "KMeans.h"

class KMeansPP : public KMeans {

public:
  KMeansPP(Dataset *dados) : KMeans(dados) { }
};


#endif //CPPKMEANS_KMEANSPP_H
