#ifndef CPPKMEANS_KMEANS_H
#define CPPKMEANS_KMEANS_H


#include "KMeans.h"
#include "IteracaoSimples.h"
#include "InicializacaoSimples.h"

class Lloyd : public KMeans {

public:
  Lloyd(Dataset *dados);

  virtual bool hookSalvar() override;
};


#endif //CPPKMEANS_KMEANS_H
