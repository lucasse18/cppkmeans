#include "Dataset.h"

/* construtor e destrutor */
Dataset::Dataset(int nExemplos, int nAtributos, int K, bool classe) :
    nExemplos(nExemplos), nAtributos(nAtributos), K(K), classe(classe) {
  //FIXME usar padrao factory? unique_ptr?
  try {
    exemplos = new double[nExemplos * nAtributos];
  } catch (bad_alloc &ba) {
    cerr << "bad alloc: " << ba.what() << '\n';
    return;
  }

  try {
    centros = new double [K * nAtributos];
  } catch (bad_alloc &ba) {
    cerr << "bad alloc: " << ba.what() << '\n';
    return;
  }
}

Dataset::~Dataset() {
  delete[] exemplos;
  delete[] centros;
}
/* construtor e destrutor */


/* getters e setters */
double *Dataset::getExemplos() const {
  return exemplos;
}

void Dataset::setExemplos(double *exemplos) {
  Dataset::exemplos = exemplos;
}

double *Dataset::getCentros() const {
  return centros;
}

void Dataset::setCentros(double *centros) {
  Dataset::centros = centros;
}

int Dataset::getNExemplos() {
  return nExemplos;
}

void Dataset::setNExemplos(int nExemplos) {
  //TODO realocar memoria exemplos
  Dataset::nExemplos = nExemplos;
}

int Dataset::getNAtributos() {
  return nAtributos;
}

void Dataset::setNAtributos(int nAtributos) {
  //TODO realocaer memoria exemplos e centros
  Dataset::nAtributos = nAtributos;
}

int Dataset::getK() {
  return K;
}

void Dataset::setK(int K) {
  //TODO realocaer memoria centros
  Dataset::K = K;
}

bool Dataset::hasClasse() const {
  return classe;
}

void Dataset::setClasse(bool classe) {
  Dataset::classe = classe;
}
/* getters e setters */
