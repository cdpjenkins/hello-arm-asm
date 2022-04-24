ptr         .req    r0
count       .req    r1
max         .req    r3
next        .req    r4

.section    .text
.globl      find_max

find_max:
            mov max, #0
loop:
            ldr next, [ptr],#4
            cmp max, next
            bhs dont_update_max
            mov max, next
dont_update_max:
            subs count, count, #1
            bne loop

            mov r0, max
            bx lr
