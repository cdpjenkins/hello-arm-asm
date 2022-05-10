#ifndef _KERNSTDLIB_H
#define _KERNSTDLIB_H

#include "stdint.h"

#include "uart.h"

void printk_string(const char *str);
void printk_uint32_hex(uint32_t x);
void printk_uint64_hex(uint64_t x);

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
