#include <omp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char **argv) {
  int n;
  int i = 0;
  u_int32_t sum = 0;
  double time;
  n = atoi(argv[1]);
  struct CacheAlignedInt {
    int value[16];
  };
  // struct CacheAlignedInt array[ARRAY_SIZE];
  struct CacheAlignedInt *array = malloc(n * sizeof(struct CacheAlignedInt));

  time = omp_get_wtime();
  //  Parallel Region
#pragma omp parallel shared(sum) firstprivate(n, array)
  {
#pragma omp for nowait reduction(+ : sum) schedule(auto)
    for (i = 1; i < n + 1; i++) {
      array[i].value[0] = i * i;
      printf("%d %d\n", i, array[i].value[0]);
      sum += array[i].value[0];
    }
  }
  time = omp_get_wtime() - time;
  printf("The sum of %d squares is %d\n", n, sum);

  printf("Time Taken: %f\n", time);
  // free(array);
  return 0;
}
