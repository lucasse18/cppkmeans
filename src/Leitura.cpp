#include "Leitura.h"

Leitura::Leitura(Dataset *dados) {
  this->dados = dados;
  this->ler();
}

//TODO verificar erros de formatacao na leitura
//TODO ler sem precisar da quantidade de atributos inicializada
int Leitura::ler() {
  std::ios_base::sync_with_stdio(false);//input utilizando buffers, mais rápido
  stringstream ss;
  string input;
  float valor;
  char sep;
  unsigned long i=0, j=0;

  while(getline(cin, input)) {
    if(input.front() != '%') {
      ss << input;
      j = 0;
      dados->getExemplos().push_back(Exemplo());
      while(ss >> valor) {
        dados->getExemplos().at(i).getAtributos().push_back(valor);
        ss >> sep;
        j++;
        if(dados->temClasse() && j == dados->getNAtributos())
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
