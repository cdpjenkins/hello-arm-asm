.text
.global main

main:
    stp x29, x30, [sp, #-16]!

    mov x0, #0

    ldp x29, x30, [sp], #16
    ret
    