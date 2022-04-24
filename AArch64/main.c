#include <stdio.h>

#include "asm.h"

int main() {
    int arg = 123;
    int result;

    printf("Gonna call some 64 bit ARM asm code from here!\n");

    result = identity(arg);

    printf("%d\n", result);
}
