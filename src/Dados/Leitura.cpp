#include "Leitura.h"

//TODO verificar erros de formatacao na leitura
//TODO determinar o numero de atributos antes de ler
int Leitura::ler(Dataset *dados) {

  //std::ios_base::sync_with_stdio(false);//input com buffers

  int nAtr = dados->getNAtributos();
  double *ex = dados->getExemplos();
  bool temClasse = dados->hasClasse();
  int i=0, j=0;
  double valor;

  stringstream ss;
  string input;
  char sep;

  while(getline(cin, input)) {
    if(input.front() != '%') {
      ss << input;
      j = 0;
      while(ss >> valor) {
        ex[j+(i * nAtr)] = valor;
        ss >> sep;
        j++;
        if(temClasse && j == nAtr)
          ss >> input;
      }
      ss.clear();
      i++;
    }
  }

  //dados->setNExemplos(i);
  //dados->setNAtributos(j);
  return 1;
}
