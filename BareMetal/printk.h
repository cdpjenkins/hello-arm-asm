#ifndef _PRINTK_H
#define _PRINTK_H

#include "stdint.h"

#include "uart.h"

void printk_string(const char *str);
void printk_uint32_hex(uint32_t x);

#endif // _PRINTK_H
