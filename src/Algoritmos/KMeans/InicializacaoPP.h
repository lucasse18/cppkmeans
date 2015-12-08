#ifndef CPPKMEANS_INICIALIZACAOPP_H
#define CPPKMEANS_INICIALIZACAOPP_H


#include "Inicializacao.h"

class InicializacaoPP : public Inicializacao {

public:
  virtual bool inicializa(Dataset *dados);

};


#endif //CPPKMEANS_INICIALIZACAOPP_H
