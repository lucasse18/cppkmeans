#include "Inicializacao.h"

bool Inicializacao::inicializaSimples(Dataset *dados) {

  int *index;

  try {
    index = new int[(*dados->getAddrK())];

    /* TODO checar erro na inicialização */
    InicializaClassico(dados->getExemplos(), dados->getCentros(),
                       dados->getAddrNExemplos(), dados->getAddrNAtributos(),
                       dados->getAddrK(), index);
  } catch (bad_alloc &ba) {
    cerr << "bad alloc: " << ba.what() << '\n';
    delete index;
    return false;
  }

  return true;
}

bool Inicializacao::inicializaPP(Dataset *dados) {
  return true;
}
