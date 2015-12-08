#include "KMeans.h"

/* construtor e destrutor */
KMeans::KMeans(Dataset *dados) : dados(dados) { }

KMeans::~KMeans() {
  delete ini;
  delete itr;
}
/* construtor e destrutor */

bool KMeans::rodar() {
  if(ini->inicializa(dados) && itr->itera(dados))
    return hookSalvar();

  return false;
}

bool KMeans::hookSalvar() {
  return true;
}

void KMeans::iterar() {
  itr->itera(dados);
}

void KMeans::inicializar() {
  ini->inicializa(dados);
}

/* getters e setters */
Dataset *KMeans::getDados() const {
  return dados;
}

void KMeans::setDados(Dataset *dados) {
  KMeans::dados = dados;
}

Inicializacao *KMeans::getIni() const {
  return ini;
}

void KMeans::setIni(Inicializacao *ini) {
  KMeans::ini = ini;
}

Iteracao *KMeans::getItr() const {
  return itr;
}

void KMeans::setItr(Iteracao *itr) {
  KMeans::itr = itr;
}
/* getters e setters */
