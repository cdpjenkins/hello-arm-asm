#include "kernstdlib.h"
#include "asm.h"
#include "handler.h"

int init_uart();
int write_string(char *str);
int read_char();
void write_char(int ch);

int kernel_main() {
    int64_t i;
 
    uart_init();
    kprintf("Hello from some C code!!!1\n\n\n");
    kprintf("LOL here is another string\n");

    // init_timer();
    init_interrupt_controller();
    enable_irq();

    kprintf("currentel: %d\n", get_el());

    kprintf("timer frequency: %d\n", read_timer_freq());
    kprintf("timer value: %d\n", read_timer_value);

    kprintf("Returning from main now innit\n");
}
