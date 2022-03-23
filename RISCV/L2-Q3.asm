addi a1, x0, 0xff
lw a2, t1
lw a3, t2
slli a1, a1, 16
and a4, a2, a1
and a3, a4, a3
halt
t1: .word 0xffff0000
t2: .word 0x0000ffff