#include "Leitura.h"

Leitura::Leitura(Dataset *data) : dados(data) { }

int Leitura::ler() {
  std::ios_base::sync_with_stdio(false);
  stringstream ss;
  string input;
  float valor;
  char sep;
  unsigned long i=0, j=0;

  while(getline(cin, input)) {
    if(input.front() != '%') {
      dados->getExemplos().push_back(vector<float>());
      ss << input;
      j = 0;
      while(ss >> valor) {
        dados->getExemplos().at(i).push_back(valor);
        ss >> sep;
        j++;
        if(dados->temClasse() && j == dados->getNAtributos()) {
          ss >> input;
        }
      }
      ss.clear();
      i++;
    }
  }

  for(unsigned long k = 0; k < i; ++k) {
    for(unsigned long l = 0; l < dados->getNAtributos(); ++l) {
      cout << dados->getExemplos().at(k).at(l) << ',';
    }
    cout << '\n';
  }

  //}
  return 1;
}
