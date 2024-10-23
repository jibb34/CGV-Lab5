#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ARRAY_SIZE 100
int main(int argc, char **argv) {
  int n;
  int i = 0;
  int sum = 0;
  double time;
  n = atoi(argv[1]);
  // int squares[100]; // can this work?
  struct Parallel_Friendly_Array {
    int array[ARRAY_SIZE];
  };
  struct Parallel_Friendly_Array squares;
  // omp_set_dynamic(1);

  time = omp_get_wtime();
// Parallel Region
#pragma omp parallel shared(sum) private(i, squares)
  {
#pragma omp for nowait reduction(+ : sum) schedule(auto)
    for (i = 1; i < n; i++) {
      squares.array[i] = i * i;
      // printf("%d %d\n", i, squares.array[i]);
      sum += squares.array[i];
    }
  }
  time = omp_get_wtime() - time;
  printf("The sum of %d squares is %d\n", n, sum);

  printf("Time Taken: %f\n", time);
  return 0;
}
