#include "InicializacaoSimples.h"

//TODO verificar falha
bool InicializacaoSimples::inicializa(Dataset *dados, vector<Centro> *centros) {

  unsigned long rnd;
  vector<unsigned long> gerados;
  vector<unsigned long>::iterator it;
  srand48(time(NULL));//FIXME seed
  for(unsigned i = 0; i < dados->getK(); ++i) {
    centros->push_back(Centro());
    rnd = (lrand48() % dados->getNExemplos());
    it = find(gerados.begin(), gerados.end(), rnd);
    if (it == gerados.end()) {
      gerados.push_back(rnd);
      for(unsigned j = 0; j < dados->getNAtributos(); ++j) {
        centros->at(i).getAtributos().push_back((dados->getExemplos().at(rnd).getAtributos().at(j)));
      }
    }
    else
      i--;
  }

  //TODO salvar centros gerados em arquivo centros iniciais
  for(unsigned i = 0; i < dados->getK(); ++i) {
    cout << "Centro: ";
    for(unsigned j = 0; j < dados->getNAtributos(); ++j) {
      cout << centros->at(i).getAtributos().at(j) << ',';
    }
    cout << " exemplo: " << gerados.at(i) << '\n';
  }

  return true;
}
