#include "printk.h"

void printk_string(const char *str) {
    uart_write_string(str);
}
