#ifndef _KERNSTDLIB_H
#define _KERNSTDLIB_H

#include <stdarg.h>
#include <stdint.h> 

#include "uart.h"

int kprintf(const char *format, ...);

void memset(void *dst, int value, unsigned int size);
void memcpy(void *dst, void *src, unsigned int size);
void memmove(void *dst, void *src, unsigned int size);
int memcmp(void *dst, void *src, unsigned int size);

#define ASSERT(e) do {                      \
    if (!(e)) {                             \
        error_check(__FILE__, __LINE__);    \
    }                                       \
} while (0);

void error_check(char *file, uint64_t line);

#endif // _KERNSTDLIB_H
