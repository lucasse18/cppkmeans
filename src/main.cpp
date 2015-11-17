#include "Dataset.h"
#include "Leitura.h"
//#include "Lloyd.h"

using namespace std;

int main(int argc, char *argv[]) {

  Dataset dados(150, 4, 3, true);
  Leitura::ler(&dados);

  double *ex = dados.getExemplos();

  for(int i = 0; i < 150; ++i) {
    for(int j = 0; j < 4; ++j) {
      if(j != 3)
        cout << ex[j + (i * 4)] << ',';
      else
        cout << ex[j + (i * 4)];
    }
    cout << '\n';
  }

//  Lloyd kmeans(&dados);
//  kmeans.rodar();

  return 0;
}
