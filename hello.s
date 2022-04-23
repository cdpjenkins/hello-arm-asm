.data
var1: .word 3
var2: .word 4

.text
.globl triangle_numbers_by_addition
.globl triangle_numbers_by_multiplication

triangle_numbers_by_addition:
    push {fp, lr}
loop:
    add r0,r0,r1
    subs r1,r1,#1
    bne loop

    push {r0,r1}
    bl print32
    pop {r0,r1}

    pop {fp, pc}

triangle_numbers_by_multiplication:
    mov r1, r0
    mov r2, r0
    add r1, r1, #1
    mul r0, r2, r1
    lsr r0, r0, #1

    bx lr
