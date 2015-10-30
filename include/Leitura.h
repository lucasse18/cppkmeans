#ifndef CPPK_MEANS_LEITURA_H
#define CPPK_MEANS_LEITURA_H


#include <iostream>
#include <sstream>
#include "Dataset.h"

using namespace std;

class Leitura {

private:
  Dataset *dados;

public:
  Leitura(Dataset *dados);
  int ler();
};


#endif //CPPK_MEANS_LEITURA_H
