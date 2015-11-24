#include "YinYang.h"

bool YinYang::rodar() {
  if (getIni()->inicializaSimples(getDados()))
    return getItr()->iteraYinYang(getDados());
  return false;
}
