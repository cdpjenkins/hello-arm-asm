.text
.global start

start:
    mrs x0, mpidr_el1
    ands x0, x0, #3
    beq kernel_entry

end:
    b end

kernel_entry:
    // switch to EL1
    mrs x0, currentel
    lsr x0, x0, #2
    cmp x0, #2
    bne end                 // if we're not in EL2 then that's an error and we terminate
    msr sctlr_el1, xzr
    mov x0, #(1 << 31)
    msr hcr_el2, x0
    mov x0, #0b1111000101
    msr spsr_el2, x0
    adr x0, el1_entry
    msr elr_el2, x0
    eret
el1_entry:

    // setup initial stack pointer
    mov sp, #0x80000

    // zero the whole BSS
    ldr x0, =bss_start
    ldr x1, #0
    ldr x2, =bss_end
    sub x2, x2, x0
    bl memset

    bl main
    b end
