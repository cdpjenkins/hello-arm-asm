#include <stdio.h>

#include "hello.h"

int main() {
  int result, i;

  printf("Triangle numbers ftw!\n");

  for (i = 1; i < 20; i++) {
    result = triangle_numbers_by_addition(0, i);
    printf("%d %d\n", i, result);
  }

  return 0;
}

void print32(unsigned int value) {
  printf("%08X\n", value);
}

