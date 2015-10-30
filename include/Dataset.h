#ifndef CPPK_MEANS_DATASET_H
#define CPPK_MEANS_DATASET_H

#include <iostream>
#include <vector>

using namespace std;

class Dataset {

private:
  vector<vector<float>> exemplos;
  unsigned long nExemplos;
  unsigned long nAtributos;
  int K;
  bool classe;

public:
  Dataset(unsigned long nExemplos, unsigned long nAtributos, int K, bool classe);
  vector<vector<float>> & getExemplos();
  unsigned long getNExemplos() const;
  unsigned long getNAtributos() const;
  int getK() const;
  bool temClasse() const;
};


#endif //CPPK_MEANS_DATASET_H
