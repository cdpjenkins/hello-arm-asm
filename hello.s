.data
var1: .word 3
var2: .word 4

.text
.globl thang
.globl print_me_do

thang:
    add r0,r0,r1
    bx lr
