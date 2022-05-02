.data
message: .asciz "Hello raspberry pi"

.text
.global main

main:
    stp x29, x30, [sp, #-16]!

    bl init_uart

    adr x0, message
    bl write_string
    
print_keys:
    bl read_char
    bl write_char
    b print_keys
    
    mov x0, #0

    ldp x29, x30, [sp], #16
    ret
    
