#include "kmeans.h"

void lloyd(double *ex, double *cen, int nex, int nat, int k, int *bcls,
           int *nexcl, double *rss) {

  int trocou;
  int i, j, l, novoMelhor = -1;
  double dist, distMenor, delta;

  /* inicializa todos os exemplos no cluster -1 */
  for (i = 0; i < nex; i++) bcls[i] = -1;

  while(1) {

    *rss = 0;
    trocou = 0;
    for(i = 0; i < k; i++) nexcl[i] = 0;

    /* etapa 1: atribuir cada exemplo a um cluster */
    for(i = 0; i < nex; i++) {
      distMenor = DBL_MAX;
      for(j = 0; j < k; j++) {
        dist = 0.0;
        for (l = 0; l < nat; l++) {
          delta = ex[l + nat * i] - cen[l + nat * j];
          dist += delta * delta;
        }
        if(dist < distMenor) {
          distMenor = dist;
          novoMelhor = j;
        }
      }
      if(bcls[i] != novoMelhor) {
        trocou = 1;
        bcls[i] = novoMelhor;
      }
      nexcl[bcls[i]]++;
      *rss += distMenor;
    }

    if(!trocou) break;

    /* etapa 2: recalcular o novo centro */
    for (i = 0; i < k * nat; i++) cen[i] = 0.0;
    for (i = 0; i < nex; i++) {
      for (j = 0; j < nat; j++)
        cen[j + nat * bcls[i]] += ex[j + nat * i];
    }
    for (i = 0; i < k; i++) {
      for (j = 0; j < nat; ++j)
        if (nexcl[i] != 0)
          cen[j + nat * i] /= nexcl[i];
    }
  }

  /*for(i = 0; i < k; ++i)
    printf("Exemplos no cluster [%d](kmeans.c(lloyd)): %d\n",i, nexcl[i]);*/
  printf("%f\n", *rss);
}

double max(double *v, int size) {
  double maior = DBL_MIN;
  for(int i = 0; i < size; i++) {
    if(v[i] > maior)
      maior = v[i];
  }
  return maior;
}

void yinyang(double *ex, double *c, double *cant, double *ub,
             double *lb, double *var, int nex, int nat, int k,
             int *bcls, int *secbcls, int *nexcl, double *rss) {

  int trocou;
  int i, j, l, novoMelhor = -1;
  double dist, distMenor, segDistMenor,delta;

  /* inicializa todos os exemplos no cluster -1 */
  for (i = 0; i < nex; i++) bcls[i] = secbcls[i] = -1;
  for (i = 0; i < k; i++) {
    /* garante que a primeira atribuicao ocorra normalmente */
    var[i] = 0.0;
    lb[i] = 0.0;
    ub[i] = 1.0;
  }

  while(1) {

    *rss = 0.0;
    trocou = 0;
    for(i = 0; i < k; i++) nexcl[i] = 0;

    /* etapa 1: atribuir cada exemplo a um cluster */
    //FIXME max(var, k) retorna DOUBLE_MIN
    for(i = 0; i < nex; i++) {
      distMenor = segDistMenor = DBL_MAX;
      for(j = 0; j < k; j++) {
        double maxVar = max(var, k);
        dist = 0.0;
        for (l = 0; l < nat; l++) {
          delta = c[l + nat * j] - cant[l + nat * j];
          dist += delta * delta;
        }
        if(ub[i] + maxVar < lb[i] - dist) {
          dist = 0.0;
          for(l = 0; l < nat; l++) {
            delta = ex[l + nat * i] - c[l + nat * j];
            dist += delta * delta;
          }
          //FIXME se k=1 secbcls[i] sera -1
          if(dist < distMenor) {
            segDistMenor = distMenor;
            secbcls[i] = novoMelhor;
            distMenor = dist;
            novoMelhor = j;
          }
          else if(dist < segDistMenor) {
            segDistMenor = dist;
            secbcls[i] = j;
          }
        }
        if(bcls[i] != novoMelhor) {
          trocou = 1;
          bcls[i] = novoMelhor;
        }
      }
      nexcl[bcls[i]]++;
      *rss += ub[i];
    }

    if(!trocou) break;

    /* etapa 2: atualizar cada cluster */
    for (i = 0; i < k * nat; i++) {
      cant[i] = c[i];
      c[i] = 0.0;
    }
    for (i = 0; i < nex; i++) {
      for (j = 0; j < nat; j++)
        c[j + nat * bcls[i]] += ex[j + nat * i];
    }
    for (i = 0; i < k; i++) {
      for (j = 0; j < nat; ++j)
        if (nexcl[i] != 0)
          c[j + nat * i] /= nexcl[i];
    }

    /* atualizar ub e lb */
    for(i = 0; i < nex; ++i) {
      ub[i] = 0.0; lb[i] = 0.0;
      for(j = 0; j < nat; ++j) {
        delta = ex[j + nat * i] - c[j + nat * bcls[i]];
        ub[i] += delta * delta;
        delta = ex[j + nat * i] - c[j + nat * secbcls[i]];
        lb[i] += delta * delta;
      }
    }

    /* calcular variacao de cada cluster */
    for(i = 0; i < k; ++i) {
      var[i] = 0.0;
      for(j = 0; j < nat; ++j) {
        delta = c[j + nat * i] - cant[j + nat * i];
        var[i] += delta * delta;
      }
    }

  }

  /*for(i = 0; i < k; ++i)
    printf("Exemplos no cluster [%d](kmeans.c(yy)): %d\n",i, nexcl[i]);*/
  printf("%f\n", *rss);
}

int buscaLinear(int key, int *base, int size) {
  int i;
  for (i = 0; i < size; i++) {
    if (key == base[i])
      return 1;
  }
  return 0;
}

void inicializaClassico(double *ex, double *cen, int nex, int nat, int k, int *gen) {
  int i, j,rnd;
  for(i = 0; i < k; i++) {

    gen[i] = 0;
    do {
      rnd = (int) (lrand48() % nex);//FIXME overflow ?
    } while(buscaLinear(rnd, gen, i) != 0);
    gen[i] = rnd;
    fprintf(stderr, "[DEBUG] Exemplo %d escolhido como centro inicial: \n", gen[i]);

    fprintf(stderr, "[DEBUG] ");
    for(j = 0; j < nat; j++) {
      cen[j + i * nat] = ex[j + rnd * nat];
      if(j != k)
        fprintf(stderr, "%f,", cen[j + (i * nat)]);
      else
        fprintf(stderr, "%f", cen[j + (i * nat)]);
    }
    fputc('\n', stderr);
  }
}

int compDouble(const void *a, const void *b) {
  if((*(double *) a) > (*(double *) b)) return 1;
  if((*(double *) a) < (*(double *) b)) return -1;
  return 0;
}

void inicializaPP(double *ex, double *cen, int nex, int nat, int k, int *gen) {

}
