#define IO_BASE_ADDR    0x3f200000
#define UART0_DR        (volatile unsigned int *) (IO_BASE_ADDR + 0x1000)
#define UART0_FR        (volatile unsigned int *) (IO_BASE_ADDR + 0x1018)
#define UART0_CR        (volatile unsigned int *) (IO_BASE_ADDR + 0x1030)
#define UART0_LCRH      (volatile unsigned int *) (IO_BASE_ADDR + 0x102c)
#define UART0_FBRD      (volatile unsigned int *) (IO_BASE_ADDR + 0x1028)
#define UART0_IBRD      (volatile unsigned int *) (IO_BASE_ADDR + 0x1024)
#define UART0_IMSC      (volatile unsigned int *) (IO_BASE_ADDR + 0x1038)

#define RXFE            4


int uart_read_char() {
    volatile unsigned int *uart0_fr = UART0_FR;
    volatile unsigned int *uart0_dr = UART0_DR;
    int counter = 0;
    volatile unsigned int value;

    while ((value = *uart0_fr) & (1 << RXFE)) {
        *((volatile int*)0x70000) = counter++;
        *((volatile int*)0x70004) = value;

        // wait until we actually have a byte to read
    }

    return *uart0_dr;
}
