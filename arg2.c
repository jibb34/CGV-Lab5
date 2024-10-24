#include <omp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ARRAY_SIZE 1000
int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  int i = 0;
  int sum = 0;
  double time;
  n = atoi(argv[1]);
  // struct CacheAlignedInt {
  //   int value[16];
  // };
  // struct CacheAlignedInt array[ARRAY_SIZE];
  // struct CacheAlignedInt *array = malloc(n * sizeof(array->value));
  int *squares = malloc(n * sizeof(int));
  omp_set_dynamic(1);

  time = omp_get_wtime();
  //  Parallel Region
#pragma omp parallel shared(sum) private(i, squares)
  {
#pragma omp for nowait reduction(+ : sum) schedule(auto)
    for (i = 1; i < n; i++) {
      squares[i] = i * i;
      // printf("%d %d\n", i, squares.array[i]);
      sum += squares[i];
    }
  }
  time = omp_get_wtime() - time;
  printf("The sum of %d squares is %d\n", n, sum);

  printf("Time Taken: %f\n", time);
  free(squares);
  return 0;
}
