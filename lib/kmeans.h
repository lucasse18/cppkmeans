#ifndef _KMEANS_H_
#define _KMEANS_H_


#include <stdlib.h>
#include <float.h>

void lloyd(double *ex, double *cen, int *pnex, int *pnat,
           int *pk, int *bcls, int *nexc, double *rss);

void InicializaClassico(double *ex, double *cen, int *pnex,
                        int *pnat, int *pk, int *gen);

#endif //CPPKMEANS_KMEANS_H
