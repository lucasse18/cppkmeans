#ifndef CPPK_MEANS_INICIALIZACAOSIMPLES_H
#define CPPK_MEANS_INICIALIZACAOSIMPLES_H


#include "Inicializacao.h"

class InicializacaoSimples: public Inicializacao {

public:
  virtual bool inicializa() override;
};


#endif //CPPK_MEANS_INICIALIZACAOSIMPLES_H
