.section    .text
.globl      hailstone_one_iteration

hailstone_one_iteration_mine:
    tst r0, #1
    bne odd
even:
    lsr r0, #1
    bx lr
odd:
    lsl r1, r0, #1
    add r0, r0, r1
    add r0, r0, #1
    bx lr

// this is what gcc -O3 gives... no branches but I guess you couldn't use this approach
// in AArch64:
hailstone_one_iteration:
    tst     r0, #1
    lsreq   r0, r0, #1
    addne   r0, r0, r0, lsl #1
    addne   r0, #1
    bx      lr

