#include "kmeans.h"

/* ex   = pnex * pnat * sizeof double
 * cen  = pk   * pnat * sizeof double
 * pnex = sizeof int
 * pnat = sizeof int
 * pk   = sizeof int
 * bcls = pnex * sizeof int
 * nexc = pk   * sizeof int
 * rss  = pk   * sizeof double
 */

void lloyd(double *ex, double *cen, int *pnex, int *pnat, int *pk, int *bcls, int *nexc, double *rss) {

  int trocou;
  int i, j, l, novoMelhor = -1;
  double distAtual, distMenor, delta;
  int numEx = *pnex, numAtr = *pnat, numCls = *pk;
  int *numExCls = nexc;
  *rss = 0;
  /* inicializa todos os exemplos no cluster -1 */
  for (i = 0; i < numEx; i++) bcls[i] = -1;

  while(1) {
    trocou = 0;

    /* etapa 1: atribuir cada exemplo a um cluster */
    for(i = 0; i < numEx; i++) {
      distMenor = DBL_MAX;
      for(j = 0; j < numCls; j++) {
        distAtual = 0.0;
        for (l = 0; l < numAtr; l++) {
          delta = ex[i + (numAtr*l)] - cen[j + (numCls*l)];
          distAtual += delta * delta;
        }
        if(distAtual < distMenor) {
          distMenor = distAtual;
          novoMelhor = j;
        }
      }
      if(bcls[i] != novoMelhor) {
        trocou = 1;
        bcls[i] = novoMelhor;
      }
      numExCls[novoMelhor]++;
      *rss += distMenor;
    }

    if(!trocou) break;

    /* etapa 2: recalcular o novo centro */
    for (i = 0; i < numCls * numAtr; i++) cen[i] = 0.0;
    for (i = 0; i < numCls; i++)numExCls[i] = 0;
    for (i = 0; i < numEx; i++) {
      numExCls[bcls[i]]++;
      for (j = 0; j < numAtr; j++)
        cen[bcls[i] + (j*numCls)] += ex[i + (j*numEx)];
    }
    for (j = 0; j < numCls*numEx; j++)
      cen[j] /= numExCls[j%numCls];
  }

  for(i = 0; i < numCls; i++) rss[i] = 0.0;
  for(i = 0; i < numEx; i++) {
    for(j = 0; j < numAtr; j++) {
      delta = ex[i + (numEx*j)] - cen[bcls[i] + (numCls*j)];
      rss[bcls[i]] += delta * delta;
    }
  }
}

int compInt(const void *a, const void *b) {
  if ((*(int *)a) < (*(int *)b)) return -1;
  if ((*(int *)a) > (*(int *)b)) return -1;
  return 0;
}

int search(int key, int *base, int size) {
  int i;
  for (i = 0; i < size; i++) {
    if (key == base[i])
      return 1;
  }
  return 0;
}

/* gen = pk * sizeof int */
void InicializaClassico(double *ex, double *cen, int *pnex, int *pnat, int *pk, int *gen) {
  int i, rnd;
  int numEx = *pnex, numAtr = *pnat, numCls = *pk;
  for(i = 0; i < numCls; i++) {

    gen[i] = 0;
    do {
      rnd = lrand48() % numEx;
    } while(search(rnd, gen, i) != 0);
    gen[i] = rnd;

    for(i = 0; i < numAtr; i++)
      cen[i] = ex[rnd];
  }
}
