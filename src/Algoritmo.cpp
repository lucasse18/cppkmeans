#include "Algoritmo.h"

Algoritmo::Algoritmo(Inicializacao *ini, Iteracao *itr) {
  this->ini = ini;
  this->itr = itr;
}

int Algoritmo::inicializar() {
  return ini->inicializa();
}

int Algoritmo::iterar() {
  return itr->itera();
}

int Algoritmo::rodar() {
  return inicializar() &&  iterar();
}

Algoritmo::~Algoritmo() {
  delete ini;
  delete itr;
}
