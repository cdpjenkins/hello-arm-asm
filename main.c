#include <stdio.h>
#include <stdlib.h>

#include "hello.h"

static void print_triangle_numbers_by_addition() {
  int result, i, j;

  printf("Triangle numbers ftw!\n");
  for (i = 1; i < 20; i++) {
    result = triangle_numbers_by_addition(0, i);
    printf("%d %d\n", i, result);
  }
}

static void print_triangle_numbers_by_multiplication() {
  int result, i, j;

  for (i = 1; i < 20; i++) {
    result = triangle_numbers_by_multiplication(i);
    printf("%d %d\n", i, result);
  }
}

static void try_division() {
  int result, i, j;

  printf("Trying division!\n");
  for (i = 1; i < 100; i++) {
    result = divide_me_do(100, i);
    printf("%d %d\n", i, result);
  }
}

static void print_max() {
  int max;
  int numbers[] = {9, 1, 4, 6, 55, 23, 56, 0, 23, 41};

  max = find_max(numbers, 10);

  printf("max is %d\n", max);
}

int hailstone_one_iteration_c(unsigned int i) {
  if (i % 2 == 0) {
    return i / 2;
  } else {
    return 3*i +1;
  }
}

static void print_hailstone_numbers() {
  int result, i, iterations, n, nc;

  printf("Hailstone numbers!\n");

  for (i = 1; i < 100; i++) {
    iterations = 0;
    n = i;
    while (n != 1) {
      iterations++;
      nc = hailstone_one_iteration_c(n); 
      n = hailstone_one_iteration(n);
      if (n != nc) {
        printf("argh, they are not equal: %d %d %d\n", i, n, nc);
        exit(1);
      }
    }
    printf("%8d %8d\n", i, iterations);
  }
}

int main() {
  print_triangle_numbers_by_addition();
  print_triangle_numbers_by_multiplication();
  try_division();
  print_max();
  print_hailstone_numbers();

  return 0;
}

void print32(unsigned int value) {
  printf("%08X\n", value);
}

