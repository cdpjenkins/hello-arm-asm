#include <stdint.h>
#include "kernstdlib.h"
#include "handler.h"
#include "asm.h"

static uint32_t timer_interval = 0;
static uint32_t ticks = 0;

static void timer_interrupt_handler(void)
{
    uint32_t status = read_timer_status();
    if (status & (1 << 2)) {
        ticks++;

        if (ticks % 100 == 0) {
            kprintf("ticks %d\n", ticks);
        }

        set_timer_interval(timer_interval);
    }
}

static uint32_t get_irq_number() {
    return *IRQ_BASIC_PENDING;
}

void handler(uint64_t numid, uint64_t spsr, uint64_t elr) {
    uint32_t irq;

    switch (numid) {
        case 1:
            kprintf("sync error at %X: %X\n", elr, spsr);
            while (1) ;
            break;
        case 2:
            irq = *CNTP_STATUS_EL0;
            if (irq & (1 << 1)) {
                timer_interrupt_handler();
            } else if (get_irq_number() & (1 << 19)) {
                uart_handler();
            } else {
                kprintf("unknown irq\n");
                while (1) { }
            }
            break;

        default:
            kprintf("unknown exception: %d\n", numid);
            kprintf("%X: %X\n", elr, spsr);
            while (1) ;
            break;
    }
}

void init_timer(void)
{
    // Not yet sure what to call to get the C runtime to initialise the variable so setting it here
    ticks = 0;

    kprintf("in init_timer ticks %X\n", ticks);

    timer_interval = read_timer_freq() / 100;
    enable_timer();
    *CNTP_EL0 = (1 << 1);
}

void init_interrupt_controller() {
    *DISABLE_BASIC_IRQS = 0xffffffff;
    *DISABLE_IRQS_1 = 0xffffffff;
    *DISABLE_IRQS_2 = 0xffffffff;

    *ENABLE_IRQS_2 = (1 << 25);
}
