#include "IteracaoYY.h"

bool IteracaoYY::itera(Dataset *dados) {
  int *melhorCluster, *segMelhorCluster;
  int *numeroExCluster;
  double rss;

  double *centrosAnt, *ub, *lb, *variacao;

  try {
    melhorCluster = new int[dados->getNExemplos()];
    numeroExCluster = new int[dados->getK()];

    segMelhorCluster = new int[dados->getNExemplos()];
    ub = new double[dados->getNExemplos()];
    lb = new double[dados->getNExemplos()];
    variacao = new double[dados->getK()];
    centrosAnt = new double[dados->getK() * dados->getNAtributos()];

  }
  catch (bad_alloc &ba) {
    cerr << "bad alloc: " << ba.what() << '\n';
    return false;
  }

  /* TODO checar erro na iteracao */
  yinyang(dados->getExemplos(), dados->getCentros(), centrosAnt, ub, lb, variacao,
          dados->getNExemplos(), dados->getNAtributos(), dados->getK(), melhorCluster,
          segMelhorCluster, numeroExCluster, &rss);

  /*cout << "RSS(iteracao.cpp): " << rss << '\n';
  for(int i = 0; i < dados->getK(); ++i)
    cout << "Exemplos no cluster [" << i << "](iteracao.c): "
         << numeroExCluster[i] << '\n';*/

  delete[] numeroExCluster;
  delete[] melhorCluster;
  delete[] segMelhorCluster;
  delete[] centrosAnt;
  delete[] ub;
  delete[] lb;
  delete[] variacao;
  return true;
}
