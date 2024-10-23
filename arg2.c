#include <omp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char **argv) {
  int n;
  int i = 0;
  int sum = 0;
  double time;
  n = atoi(argv[1]);
  struct CacheAlignedInt {
    int value[16];
  };
  struct CacheAlignedInt *array = malloc(n * sizeof(struct CacheAlignedInt));
  // omp_set_dynamic(1);

  time = omp_get_wtime();
// Parallel Region
#pragma omp parallel shared(sum) private(i, array)
  {
#pragma omp for nowait reduction(+ : sum) schedule(auto)
    for (i = 1; i < n; i++) {
      array[i].value[0] = i * i;
      // printf("%d %d\n", i, squares.array[i]);
      sum += array[i].value[0];
    }
  }
  time = omp_get_wtime() - time;
  printf("The sum of %d squares is %d\n", n, sum);

  printf("Time Taken: %f\n", time);
  free(array);
  return 0;
}
