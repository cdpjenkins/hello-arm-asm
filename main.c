#include <stdio.h>


#include "hello.h"

int main() {
  int result, i;

  printf("Triangle numbers ftw!\n");

  for (i = 1; i < 20; i++) {
    result = thang(0, i);
    printf("%d %d\n", i, result);
  }

  return 0;
}

