.text
.global start

start:
    mrs x0, mpidr_el1
    ands x0, x0, #3
    beq kernel_entry

end:
    b end

kernel_entry:
    mov sp, #0x80000

    ldr x0, =bss_start
    ldr x1, #0
    ldr x2, =bss_end
    sub x2, x2, x0
    bl memset

    bl main
    b end
