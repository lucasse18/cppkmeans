#include "Algoritmo.h"

/* construtor e destrutor */
Algoritmo::Algoritmo(Dataset *dados) : dados(dados) { }

Algoritmo::~Algoritmo() {
  //classe fica responsavel por desalocar somente ini e itr
  delete ini; delete itr;
}
/* construtor e destrutor */


/* getters e setters */
Inicializacao *Algoritmo::getIni() const {
  return ini;
}

void Algoritmo::setIni(Inicializacao *ini) {
  Algoritmo::ini = ini;
}

Iteracao *Algoritmo::getItr() const {
  return itr;
}

void Algoritmo::setItr(Iteracao *itr) {
  Algoritmo::itr = itr;
}
/* getters e setters */
