#include <stdint.h>

#include "asm.h"
#include "kernstdlib.h"
#include "memory.h"

#define bit(n)          (1 << n)

#define IO_BASE_ADDR    P2V(0x3f200000)

#define UART0_DR        ((volatile uint32_t *)(IO_BASE_ADDR + 0x1000))
#define UART0_FR        ((volatile uint32_t *)(IO_BASE_ADDR + 0x1018))
    #define BUSY      bit(3)
#define UART0_CR        ((volatile uint32_t *)(IO_BASE_ADDR + 0x1030))
    #define UARTEN    bit(0)
    #define TXE       bit(8)
    #define RXE       bit(9)
#define UART0_LCRH      ((volatile uint32_t *)(IO_BASE_ADDR + 0x102c))
    #define WLEN_8_BITS     (0b11 << 6)
#define UART0_FBRD      ((volatile uint32_t *)(IO_BASE_ADDR + 0x1028))
#define UART0_IBRD      ((volatile uint32_t *)(IO_BASE_ADDR + 0x1024))
#define UART0_IMSC      ((volatile uint32_t *)(IO_BASE_ADDR + 0x1038))
    #define RXIM      bit(4)
#define UART0_MIS       ((volatile uint32_t *)(IO_BASE_ADDR + 0x1040))
    #define RXMIS     bit(4)
#define UART0_ICR       ((volatile uint32_t *)(IO_BASE_ADDR + 0x1044))
    #define RXIC      bit(4)

#define RXFE            bit(4)
#define TXFF            bit(5)

#define FEN             bit(4)

void uart_init() {
    *UART0_CR = 0;
    *UART0_IBRD = 26;
    *UART0_FBRD = 0;
    *UART0_LCRH = WLEN_8_BITS;
    *UART0_IMSC = RXIM;
    *UART0_CR = UARTEN | TXE | RXE;
}

int uart_read_char() {
    return *UART0_DR;
}

void uart_write_char(unsigned int ch) {
    while (*UART0_FR & BUSY) { }

    *UART0_DR = ch;
}

void uart_write_string(const char *str) {
    char ch;

    while (ch = *str++) {
        uart_write_char(ch);
    }
}

void uart_handler() {
    uint32_t status = *UART0_MIS;

    if (status & RXMIS) {
        char in_char = uart_read_char();

        // kprintf("got a char: %d\n", in_char);

        if (in_char == '\r') {
            uart_write_char('\n');
        } else {
            uart_write_char(in_char);
        }

        *UART0_ICR = RXIC;
    }
}
