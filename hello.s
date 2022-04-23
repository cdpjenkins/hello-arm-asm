.data
var1: .word 3
var2: .word 4

.text
.globl thang
.globl print_me_do

thang:
    push {fp, lr}
    add r0,r0,r1
    subs r1,r1,#1
    bne thang

    push {r0,r1}
    bl print32
    pop {r0,r1}

    pop {fp, lr}    // could totally pop into pc...
    bx lr
