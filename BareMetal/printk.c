#include "printk.h"

static inline char to_hex_char(int hex_digit) {
    if (hex_digit >= 0x0 && hex_digit <= 0x9) {
        return hex_digit + '0';
    } else {
        return hex_digit - 10 + 'A';
    }
}

void printk_string(const char *str) {
    uart_write_string(str);
}

void printk_uint32_hex(uint32_t x) {
    char buffer[9];
    int i;

    buffer[8] = '\0';
    for (i = 7; i >= 0; i--, x /= 16) {
        buffer[i] = to_hex_char(x % 16);
    }

    uart_write_string(buffer);
}
