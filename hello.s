.data
var1: .word 3
var2: .word 4

.text
.globl thang
.globl print_me_do

thang:
    add r0,r0,r1
    subs r1,r1,#1
    bne thang
    bx lr
