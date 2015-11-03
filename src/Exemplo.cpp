#include "Exemplo.h"

vector<float> &Exemplo::getAtributos() {
  return atributos;
}

unsigned int Exemplo::getCentro() const {
  return centro;
}

void Exemplo::setCentro(unsigned int centro) {
  Exemplo::centro = centro;
}
