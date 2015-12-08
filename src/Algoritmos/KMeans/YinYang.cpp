#include "YinYang.h"

YinYang::YinYang(Dataset *dados) : KMeans(dados) {
  setIni(new InicializacaoSimples);
  setItr(new IteracaoYY);
}

bool YinYang::hookSalvar() {
  return true;
}
