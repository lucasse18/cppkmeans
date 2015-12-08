#include "Dataset.h"
#include "Leitura.h"
#include "Lloyd.h"
#include "YinYang.h"

time_t time_ms(void);

int main(int argc, char *argv[]) {

  if (argc != 5)
    exit(EXIT_FAILURE);

  int nex, nat, k;
  nex = atoi(argv[1]);
  nat = atoi(argv[2]);
  k = atoi(argv[3]);

  bool temClasse = (argv[4][0] == 't' || argv[4][0] == 'T');

  Dataset dados(nex, nat, k, temClasse);
  Leitura::ler(&dados);

  srand48(time_ms());

  cout << "Lloyd: ";
  Lloyd lloyd(&dados);
  lloyd.inicializar();

  double *centros = dados.getCentros();
  double *mem_centros = new double[k * nat];
  for(int i = 0; i < k; i++) {
    for(int j = 0; j < nat; j++)
      mem_centros[j + i * nat] = centros[j + i * nat];
  }

  lloyd.iterar();

  for(int i = 0; i < k; i++) {
    for(int j = 0; j < nat; j++)
      centros[j + i * nat] = mem_centros[j + i * nat];
  }

  cout << "\nYinYang: ";
  YinYang yinyang(&dados);
  yinyang.iterar();

  return 0;
}

#if defined(__WIN32__)
#include <windows.h>

time_t time_ms(void) {
  return timeGetTime();
}

#else
#include <sys/time.h>

time_t time_ms() {
  struct timespec ts;
  clock_gettime(CLOCK_REALTIME, &ts);
  return ts.tv_sec * ts.tv_nsec;
}

#endif
