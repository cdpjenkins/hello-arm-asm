.equ IO_BASE_ADDR,    0x3f200000

.equ UART0_DR,        IO_BASE_ADDR + 0x1000
.equ UART0_FR,        IO_BASE_ADDR + 0x1018
.equ UART0_CR,        IO_BASE_ADDR + 0x1030
.equ UART0_LCRH,      IO_BASE_ADDR + 0x102c
.equ UART0_FBRD,      IO_BASE_ADDR + 0x1028
.equ UART0_IBRD,      IO_BASE_ADDR + 0x1024
.equ UART0_IMSC,      IO_BASE_ADDR + 0x1038

.section .text
.global init_uart

init_uart:
    stp x29, x30, [sp, #-16]!

    mov x1, #0
    ldr x0, =UART0_CR
    bl out_word

    mov x1, #26
    ldr x0, =UART0_IBRD
    bl out_word

    mov x1, #0
    ldr x0, =UART0_FBRD
    bl out_word

    mov x1, #(1 << 4) | (1 << 5) | (1 << 6)
    ldr x0, =UART0_LCRH
    bl out_word

    mov x1, #0
    ldr x0, =UART0_IMSC
    bl out_word

    mov x1, #(1 << 0) | (1 << 8) | (1 << 9)
    ldr x0, =UART0_CR
    bl out_word

    ldp x29, x30, [sp], #16
    ret
    