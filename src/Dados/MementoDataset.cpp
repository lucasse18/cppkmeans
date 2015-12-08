#include "MementoDataset.h"
#include "Dataset.h"

MementoDataset::MementoDataset(Dataset *dados) {

  int size = dados->getK() * dados->getNAtributos();
  centros = new double[size];
  double *centros = dados->getCentros();

  for(int i = 0; i < size; i++) {
    this->centros[i] = centros[i];
  }
}

double *MementoDataset::getCentros() const {
  return centros;
}
