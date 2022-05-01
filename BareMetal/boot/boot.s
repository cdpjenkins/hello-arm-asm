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
    bl main
    b end
    