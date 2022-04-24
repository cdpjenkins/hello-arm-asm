.data
var1: .word 3
var2: .word 4

.text
.globl triangle_numbers_by_addition
.globl triangle_numbers_by_multiplication
.globl divide_me_do

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
    add r1, r1, #1
    mul r1, r0, r1
    mov r0, r1, lsr #1
    bx lr

divide_me_do:
    udiv r0, r0, r1
    bx lr
