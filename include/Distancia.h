#ifndef CPPKMEANS_DISTANCIA_H
#define CPPKMEANS_DISTANCIA_H


//FIXME header correto importar size_t
#include <stddef.h>
#include <vector>

using namespace std;

class Distancia {
public:
  static float calc(vector<float> v1, vector<float> v2, size_t size);
};


#endif //CPPKMEANS_DISTANCIA_H
