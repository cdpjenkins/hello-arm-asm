#include "kernstdlib.h"

static inline char to_hex_char(int hex_digit) {
    if (hex_digit >= 0x0 && hex_digit <= 0x9) {
        return hex_digit + '0';
    } else {
        return hex_digit - 10 + 'A';
    }
}

static inline char to_dec_char(int digit) {
    return digit + '0';
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

void printk_uint64_hex(uint64_t x) {
    char buffer[17];
    int i;

    buffer[16] = '\0';
    for (i = 15; i >= 0; i--, x /= 16) {
        buffer[i] = to_hex_char(x % 16);
    }

    uart_write_string(buffer);
}

void printk_uint64_dec(uint64_t x) {
    char reverse_buffer[30];
    int i;

    for (i = 0; i < 30, x > 0; i++, x /= 10) {
        reverse_buffer[i] = to_dec_char(x % 10);
    }

    for (; i >= 0; i--) {
        uart_write_char(reverse_buffer[i]);
    }
}

int kprintf(const char *format, ...) {
    const char *ptr;

    for (ptr = format; *ptr != '\0'; ptr++) {
        uart_write_char(*ptr);
    }
}

void memset(void *dst, int value, unsigned int size) {
    char *dst_byte;
    int signed_size;

    for (signed_size = size, dst_byte = dst; signed_size >= 0; signed_size--) {
        *dst_byte++ = value;
    }
}

void memcpy(void *dst, void *src, unsigned int size) {
    char *src_byte;
    char *dst_byte;

    if (src < dst && src + size >= dst && src + size < dst + size) {
        for (src_byte = src + size, dst_byte = dst + size; size >= 0; size--) {
            *dst_byte-- = *src_byte--;
        }
    } else {
        for (src_byte = src, dst_byte = dst; size >= 0; size--) {
            *dst_byte++ = *src_byte++;
        }
    }
}

void memmove(void *dst, void *src, unsigned int size) {
    memcpy(dst, src, size);
}

int memcmp(void *dst, void *src, unsigned int size) {
    char *src_byte;
    char *dst_byte;

    for (src_byte = src, dst_byte = dst; size >= 0; size--) {
        if (*src_byte++ != *dst_byte++) {
            return 1;
        }
    }

    return 0;
}

void error_check(char *file, uint64_t line) {
    printk_string("Error in ");
    printk_string(file);
    printk_string(" at line ");
    printk_uint64_dec(line);
    printk_string("\n");

    while (1);
}
