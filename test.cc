#include "myvec.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define ITER_NUM 128
#define MSG_NUM 100000

int main(int argc, char **argv) {
  srand(time(NULL));
  char buffer[128];
  for (int i = 0; i < 128; i++) {
    buffer[i] = (rand() % 26) + 'a';
  }

  myvec vec;
  origin ori;

  timeval t1, t2, t3, t4;
  gettimeofday(&t1, NULL);
  for (int i = 0; i < ITER_NUM; i++) {
    for (int j = 0; j < MSG_NUM; j++) {
      vec.append(buffer, (rand() % 128) + 1);
    }
  }
  gettimeofday(&t2, NULL);

  gettimeofday(&t3, NULL);
  for (int i = 0; i < ITER_NUM; i++) {
    for (int j = 0; j < MSG_NUM; j++) {
      ori.append(buffer, (rand() % 128) + 1);
    }
  }
  gettimeofday(&t4, NULL);

  int dur1 = (t2.tv_sec - t1.tv_sec) * 1000000 + (t2.tv_usec - t1.tv_usec);
  int dur2 = (t4.tv_sec - t1.tv_sec) * 1000000 + (t3.tv_usec - t1.tv_usec);

  printf("myvec: %d us\n", dur1);
  printf("origin: %d us\n", dur2);
}