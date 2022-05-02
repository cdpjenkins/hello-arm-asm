typedef struct {
    volatile unsigned int dr;
    volatile unsigned int rsrecr;
    volatile unsigned char padding[0x10];
    volatile unsigned int fr;
    volatile unsigned int ilpr;
    volatile unsigned int ibrd;
    volatile unsigned int fbrd;
    volatile unsigned int lcrh;
    volatile unsigned int cr;
    volatile unsigned int ifls;
    volatile unsigned int imsc;
    volatile unsigned int ris;
    volatile unsigned int mis;
    volatile unsigned int icr;
    volatile unsigned int dmacr;
    // there are loads more regs that we don't use
} UART_Registers;

#define bit(n)          (1 << n)

#define RXFE            bit(4)
#define TXFF            bit(5)

#define FEN             bit(4)
#define WLEN_8_BITS     (0b11 << 6)

#define UARTEN          bit(0)
#define TXE             bit(8)
#define RXE             bit(9)

#define IO_BASE_ADDR    0x3f200000
#define UART0 ((UART_Registers *) (IO_BASE_ADDR + 0x1000))

void uart_init() {
    UART0->cr = 0;

    // Setting the baud rate here
    UART0->ibrd = 26;
    UART0->fbrd = 0;

    UART0->lcrh = FEN | WLEN_8_BITS;
    UART0->imsc = 0;
    UART0->cr = UARTEN | TXE | RXE;
}

int uart_read_char() {
    while (UART0->fr & RXFE) { } // wait until we actually have a char to read


    return UART0->dr;
}

void uart_write_char(unsigned int ch) {
    while (UART0->fr & TXFF) { } // wait until there is room in the transmit FIFO for our char

    UART0->dr = ch;
}

void uart_write_string(const char *str) {
    char ch;

    while (ch = *str++) {
        uart_write_char(ch);
    }
}
