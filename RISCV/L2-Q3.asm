lw s2, A
lw s3, B
lw s5, B

srli s2, s2, 4
slli s2, s2, 24
srli s2, s2, 4

slli s5, s5, 4
srli s5, s5, 4
sub s4, s3, s5

slli s5, s5, 12
srli s5, s5, 12
add s5, s5, s2
add s5, s5, s4
lw x10, A
add x11, x11, s5

halt
A : .word 0xffffffff
B : .word 0xaaaaaaaa
