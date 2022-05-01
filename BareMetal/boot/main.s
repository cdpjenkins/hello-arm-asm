.data
message: .asciz "Hello raspberry pi"

.text
.global main

main:
    stp x29, x30, [sp, #-16]!

    bl init_uart

    adr x0, message
    bl write_string
    
    mov x0, #0

    ldp x29, x30, [sp], #16
    ret
