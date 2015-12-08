#ifndef CPPKMEANS_INICIALIZACAOSIMPLES_H
#define CPPKMEANS_INICIALIZACAOSIMPLES_H


#include "Inicializacao.h"

class InicializacaoSimples : public Inicializacao {

public:
  virtual bool inicializa(Dataset *dados);
};


#endif //CPPKMEANS_INICIALIZACAOSIMPLES_H
