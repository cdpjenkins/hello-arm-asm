.data
my_const:  .quad 0xDEADBEEF1CEC0FEE

.text
.global zero
.global deadbeef1cec0fee

zero:
    mov x0, #0
    ret

deadbeef1cec0fee:
    ldr x1, =my_const
    ldr x0, [x1]
    ret
