#ifndef CPPK_MEANS_DATASET_H
#define CPPK_MEANS_DATASET_H


#include <iostream>
#include <vector>
#include "Exemplo.h"

using namespace std;

class Dataset {

private:
  vector<Exemplo> exemplos;
  unsigned long nExemplos;
  unsigned long nAtributos;
  unsigned K;
  bool classe;

public:
  Dataset(unsigned long nExemplos, unsigned long nAtributos, unsigned int K, bool classe);
  vector<Exemplo> & getExemplos();
  unsigned long getNExemplos() const;
  unsigned long getNAtributos() const;
  unsigned getK() const;
  bool temClasse() const;
};


#endif //CPPK_MEANS_DATASET_H
