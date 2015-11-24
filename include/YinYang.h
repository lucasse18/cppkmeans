#ifndef CPPKMEANS_YINYANG_H
#define CPPKMEANS_YINYANG_H


#include "KMeans.h"

class YinYang : public KMeans {

public:
  YinYang(Dataset *dados) : KMeans(dados) { }

  bool rodar();
};


#endif //CPPKMEANS_YINYANG_H
