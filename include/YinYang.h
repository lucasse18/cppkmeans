#ifndef CPPKMEANS_YINYANG_H
#define CPPKMEANS_YINYANG_H


#include "KMeans.h"
#include "InicializacaoSimples.h"
#include "IteracaoYY.h"

class YinYang : public KMeans {

public:
  YinYang(Dataset *dados);

  virtual bool hookSalvar() override;
};


#endif //CPPKMEANS_YINYANG_H
