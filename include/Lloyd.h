#ifndef CPPKMEANS_KMEANS_H
#define CPPKMEANS_KMEANS_H


#include "Algoritmo.h"

class Lloyd : public Algoritmo {

public:
  Lloyd(Dataset *dados) : Algoritmo(dados) { }
  bool rodar();
  bool salvar();
};


#endif //CPPKMEANS_KMEANS_H
