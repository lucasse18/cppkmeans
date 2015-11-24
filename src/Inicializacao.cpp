#include "Inicializacao.h"

bool Inicializacao::inicializaSimples(Dataset *dados) {

  int *index;

  try {
    index = new int[dados->getK()];

  } catch (bad_alloc &ba) {
    cerr << "bad alloc: " << ba.what() << '\n';
    return false;
  }

  /* TODO checar erro na inicialização */
  inicializaClassico(dados->getExemplos(), dados->getCentros(),
                       dados->getNExemplos(), dados->getNAtributos(),
                       dados->getK(), index);

  delete[] index;
  return true;
}

bool Inicializacao::inicializaPP(Dataset *dados) {
  return true;
}
