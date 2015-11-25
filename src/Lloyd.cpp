#include "Lloyd.h"

Lloyd::Lloyd(Dataset *dados) : KMeans(dados) {
  setIni(new InicializacaoSimples);
  setItr(new IteracaoSimples);
}

bool Lloyd::hookSalvar() {
  return true;
}
