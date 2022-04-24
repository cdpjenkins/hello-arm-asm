#include <stdio.h>

#include "hello.h"

void print_triangle_numbers_by_addition() {
  int result, i, j;

  printf("Triangle numbers ftw!\n");
  for (i = 1; i < 20; i++) {
    result = triangle_numbers_by_addition(0, i);
    printf("%d %d\n", i, result);
  }
}

void print_triangle_numbers_by_multiplication() {
  int result, i, j;

  for (i = 1; i < 20; i++) {
    result = triangle_numbers_by_multiplication(i);
    printf("%d %d\n", i, result);
  }
}

void try_division() {
  int result, i, j;

  printf("Trying division!\n");
  for (i = 1; i < 100; i++) {
    result = divide_me_do(100, i);
    printf("%d %d\n", i, result);
  }
}

void print_max() {
  int max;
  int numbers[] = {9, 1, 4, 6, 55, 23, 56, 0, 23, 41};

  max = find_max(numbers, 10);

  printf("max is %d\n", max);
}

int main() {
  print_triangle_numbers_by_addition();
  print_triangle_numbers_by_multiplication();
  try_division();
  print_max();

  return 0;
}

void print32(unsigned int value) {
  printf("%08X\n", value);
}

