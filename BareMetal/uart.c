
// TODO turn all of this into a big struct
#define IO_BASE_ADDR    0x3f200000
#define UART0_DR        ((volatile unsigned int *) (IO_BASE_ADDR + 0x1000))
#define UART0_FR        ((volatile unsigned int *) (IO_BASE_ADDR + 0x1018))
#define UART0_CR        ((volatile unsigned int *) (IO_BASE_ADDR + 0x1030))
#define UART0_LCRH      ((volatile unsigned int *) (IO_BASE_ADDR + 0x102c))
#define UART0_FBRD      ((volatile unsigned int *) (IO_BASE_ADDR + 0x1028))
#define UART0_IBRD      ((volatile unsigned int *) (IO_BASE_ADDR + 0x1024))
#define UART0_IMSC      ((volatile unsigned int *) (IO_BASE_ADDR + 0x1038))

#define RXFE            4
#define TXFF            5

int uart_read_char() {
    while (*UART0_FR & (1 << RXFE)) {
        // wait until we actually have a char to read
    }

    return *UART0_DR;
}



void uart_write_char(unsigned int ch) {
    while (*UART0_FR & (1 << TXFF)) {
        // wait until there is room in the transmit FIFO for our char
    }

    *UART0_DR = ch;
}
