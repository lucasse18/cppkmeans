#include <float.h>
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

  Lloyd lloyd(&dados);
  lloyd.rodar();

  /*YinYang yinyang(&dados);
  yinyang.rodar();*/

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
