#include "IteracaoSimples.h"
#include <kmeans.h>

bool IteracaoSimples::itera(Dataset *dados) {
  int *melhorCluster;
  int *numeroExCluster;
  double rss;

  try {
    melhorCluster = new int[dados->getNExemplos()];
    numeroExCluster = new int[dados->getK()];
  }
  catch (bad_alloc &ba) {
    cerr << "bad alloc: " << ba.what() << '\n';
    return false;
  }

  /* TODO checar erro na iteracao */
  lloyd(dados->getExemplos(), dados->getCentros(), dados->getNExemplos(),
          dados->getNAtributos(), dados->getK(), melhorCluster, numeroExCluster, &rss);

  delete[] melhorCluster;
  delete[] numeroExCluster;
  return true;
}
