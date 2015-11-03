#include "Centro.h"

long Centro::getQtdExemplos() const {
  return qtdExemplos;
}

void Centro::setQtdExemplos(long qtdExemplos) {
  Centro::qtdExemplos = qtdExemplos;
}

vector<float> &Centro::getAtributos() {
  return atributos;
}

void Centro::setAtributo(float atributo, unsigned pos) {
  atributos.at(pos) = atributo;
}
