#include "Dataset.h"

Dataset::Dataset(unsigned long nExemplos, unsigned long nAtributos, unsigned int K, bool classe) {
  this->nExemplos = nExemplos;
  this->nAtributos = nAtributos;
  this->K = K;
  this->classe = classe;
}

vector<Exemplo> &Dataset::getExemplos() {
  return exemplos;
}

unsigned long Dataset::getNExemplos() const {
  return nExemplos;
}

unsigned long Dataset::getNAtributos() const {
  return nAtributos;
}

unsigned Dataset::getK() const {
  return K;
}

bool Dataset::temClasse() const {
  return classe;
}
