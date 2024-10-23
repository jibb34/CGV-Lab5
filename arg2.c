#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int n;
  int i = 0;
  int sum = 0;
  int squares[100]; // can this work?

  struct timeval startTime, stopTime;
  long totalTime; // total time elapsed

  gettimeofday(&startTime, NULL);
  n = atoi(argv[1]);

  for (i = 1; i < n; i++) {
    squares[i] = i * i;
    printf("%d %d\n", i, squares[i]);
    sum += squares[i];
  }
  printf("The sum of %d squares is %d\n", n, sum);

  gettimeofday(&stopTime, NULL);
  totalTime = (stopTime.tv_sec * 1000000 + stopTime.tv_usec) -
              (startTime.tv_sec * 1000000 + startTime.tv_usec);
  printf("%ld\n", totalTime);
  return 0;
}
