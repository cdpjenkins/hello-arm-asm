#include <stdio.h>
#include <stdint.h>

#include "asm.h"

int main() {
    int arg = 123;
    int result;

    printf("Gonna call some 64 bit ARM asm code from here!\n");

    result = identity(arg);

    printf("%d\n", result);

    printf("%016X\n", zero());

    uint64_t result64 = deadbeef1cec0fee();
    printf("%016llX\n", result64);
}
