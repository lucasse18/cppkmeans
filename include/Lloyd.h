#ifndef CPPKMEANS_KMEANS_H
#define CPPKMEANS_KMEANS_H


#include "KMeans.h"

class Lloyd : public KMeans {

public:
  Lloyd(Dataset *dados) : KMeans(dados) { }
};


#endif //CPPKMEANS_KMEANS_H
