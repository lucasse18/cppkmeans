#ifndef CPPK_MEANS_INICIALIZACAOSIMPLES_H
#define CPPK_MEANS_INICIALIZACAOSIMPLES_H


#include "Inicializacao.h"
#include "Dataset.h"

using namespace std;

class InicializacaoSimples: public Inicializacao {

public:
  bool inicializa(Dataset *dados, vector<Centro> *centros) override;
};


#endif //CPPK_MEANS_INICIALIZACAOSIMPLES_H
