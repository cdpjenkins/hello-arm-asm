#ifndef UART_H
#define UART_H

void uart_init();
int uart_read_char();
void uart_write_char(unsigned int ch);
void uart_write_string(const char *str);

#endif // UART_H
