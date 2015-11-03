#include "Algoritmo.h"

Algoritmo::Algoritmo(Dataset *dados, Inicializacao *ini, Iteracao *itr) {
  this->dados = dados;
  this->ini = ini;
  this->itr = itr;
}

bool Algoritmo::inicializar() {
  return ini->inicializa(dados, &centros);
}

bool Algoritmo::iterar() {
  return itr->itera(dados, &centros);
}

bool Algoritmo::rodar() {
  return inicializar() && iterar();
}

Algoritmo::~Algoritmo() {
  delete ini;
  delete itr;
}
