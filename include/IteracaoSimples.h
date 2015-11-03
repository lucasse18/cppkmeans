#ifndef CPPK_MEANS_ITERACAOSIMPLES_H
#define CPPK_MEANS_ITERACAOSIMPLES_H


#include "Iteracao.h"

class IteracaoSimples : public Iteracao {

private:
  void recomputa(Dataset *dados, vector<Centro> *centros);
  unsigned long atribui(Dataset *dados, vector<Centro> *centros);

public:
  bool itera(Dataset *dados, vector<Centro> *centros) override;
};


#endif //CPPK_MEANS_ITERACAOSIMPLES_H
