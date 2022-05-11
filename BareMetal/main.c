#include "kernstdlib.h"
#include "asm.h"

int init_uart();
int write_string(char *str);
int read_char();
void write_char(int ch);

int main() {
    int64_t i;

    uart_init();
    kprintf("Hello from some C code!!!1\n\n\n");
    kprintf("LOL here is another string\n");

    for (i = 0; i < 4096; i++) {
        kprintf("%d\n", i);
    }

    kprintf("currentel: %d\n", get_el());
    kprintf("\n");

    ASSERT(0);

    for (;;) {
        char ch;

        ch = uart_read_char();
        uart_write_char(ch);
    }
}
