#include "printk.h"

int init_uart();
int write_string(char *str);
int read_char();
void write_char(int ch);

int main() {
    int i;

    uart_init();
    printk_string("Hello from some C code!!!1\n\n\n");
    printk_string("LOL here is another string\n");

    for (i = 0; i < 4096; i++) {
        printk_uint32_hex(i);
        printk_string("\r\n");
    }

    for (;;) {
        char ch;

        ch = uart_read_char();
        uart_write_char(ch);
    }
}
