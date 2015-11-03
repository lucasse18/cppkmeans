#include "Dataset.h"
#include "Leitura.h"
#include "Algoritmo.h"
#include "InicializacaoSimples.h"
#include "IteracaoSimples.h"

using namespace std;

int main(int argc, char *argv[]) {

  Dataset dados(150, 4, 3, true);
  Leitura leitura(&dados);

  Algoritmo kmeans(&dados, new InicializacaoSimples(), new IteracaoSimples());
  kmeans.rodar();

  return 0;
}
