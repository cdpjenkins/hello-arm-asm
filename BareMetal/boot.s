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

    bl setup_vm
    bl enable_mmu

    // zero the whole BSS
    ldr x0, =bss_start
    ldr x1, #0
    ldr x2, =bss_end
    sub x2, x2, x0
    bl memset

    // set exception vectors
    ldr x0, =vector_table
    msr vbar_el1, x0

    mov x0, 0xFFFF000000000000
    add sp, sp, x0

    ldr x0, =kernel_main
    blr x0

    // switch to EL0
    mov x0, #0
    msr spsr_el1, x0
    adr x0, el0_entry
    msr elr_el1, x0
    eret
el0_entry:
    b end
