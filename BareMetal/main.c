#include "uart.h"

int init_uart();
int write_string(char *str);
int read_char();
void write_char(int ch);

int main() {

    init_uart();

    write_string("Hello from some C code!!!1\n");

    for (;;) {
        char ch;

        ch = uart_read_char();
        uart_write_char(ch);
    }
}
