#include "KMeans.h"

/* construtor e destrutor */
KMeans::KMeans(Dataset *dados) : dados(dados) {
  ini = new Inicializacao;
  itr = new Iteracao;
}

KMeans::~KMeans() {
  //classe fica responsavel por desalocar somente ini e itr
  delete ini; delete itr;
}
/* construtor e destrutor */

bool KMeans::rodar() {
  if(ini->inicializaSimples(dados))
    return itr->iteraSimples(dados);

  return false;
}

bool KMeans::salvar() {
  return true;
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

Iteracao *KMeans::getItr() const {
  return itr;
}
/* getters e setters */
