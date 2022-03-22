lw a1, m
lw a2, b
sub a1, a1, a2
halt
m: .word 10
b: .word 10

#a == m portanto, só precisa de um