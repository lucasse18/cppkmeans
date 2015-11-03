#include "Distancia.h"

float Distancia::calc(vector<float> v1, vector<float> v2, size_t size) {
  float dlt, dst = 0;
  for(unsigned i = 0; i < size; ++i) {
    dlt = v1.at((unsigned long) i) - v2.at((unsigned long) i);
    dst += dlt * dlt;
  }
  return dst;
}
