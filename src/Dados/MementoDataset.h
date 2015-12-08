#ifndef CPPKMEANS_MEMENTOCENTROS_H
#define CPPKMEANS_MEMENTOCENTROS_H


#include "Dataset.h"

class Dataset;

class MementoDataset {

private:
  double *centros;

public:
  MementoDataset(Dataset *dados);

  double * getCentros() const;
};


#endif //CPPKMEANS_MEMENTOCENTROS_H
