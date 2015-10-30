#include "Dataset.h"
#include "Leitura.h"
/*#include "Algoritmo.h"
#include "InicializacaoSimples.h"
#include "IteracaoSimples.h"*/

using namespace std;

int main() {
  Dataset d(150, 4, 3, true);
  Leitura l(&d);
  l.ler();

  /*Inicializacao *ini = new InicializacaoSimples();
  Iteracao *itr = new IteracaoSimples();

  Algoritmo kmeans(ini, itr);
  kmeans.rodar();*/

  for(unsigned long i = 0; i < d.getNExemplos(); ++i) {
    for(unsigned long j = 0; j < d.getNAtributos(); ++j) {
      cout << d.getExemplos().at(i).at(j) << ',';
    }
    cout << '\n';
  }

  return 0;
}
