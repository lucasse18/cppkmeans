#include "Dataset.h"

Dataset::Dataset(unsigned long nExemplos, unsigned long nAtributos, int K, bool classe) {
  this->nExemplos = nExemplos;
  this->nAtributos = nAtributos;
  this->K = K;
  this->classe = classe;
}

vector<vector<float>> &Dataset::getExemplos() {
  return exemplos;
}

unsigned long Dataset::getNExemplos() const {
  return nExemplos;
}

unsigned long Dataset::getNAtributos() const {
  return nAtributos;
}

int Dataset::getK() const {
  return K;
}

bool Dataset::temClasse() const {
  return classe;
}
