#ifndef CPPK_MEANS_DATASET_H
#define CPPK_MEANS_DATASET_H


#include <iostream>
#include "MementoDataset.h"

using namespace std;

class Dataset {

private:
  double *exemplos;
  double *centros;
  int nExemplos;
  int nAtributos;
  int K;
  bool classe;

public:
  Dataset(int nExemplos, int nAtributos, int K, bool classe);
  virtual ~Dataset();

  double * getExemplos() const;
  void setExemplos(double *exemplos);
  double * getCentros() const;
  void setCentros(double *centros);
  int getNExemplos();
  void setNExemplos(int nExemplos);
  int getNAtributos();
  void setNAtributos(int nAtributos);
  int getK();
  void setK(int K);
  bool hasClasse() const;
  void setClasse(bool classe);
};


#endif //CPPK_MEANS_DATASET_H
