# Pondo variáveis em registradores
    lw a1, a
    lw a2, b
    lw a3, c
    lw a4, x
# Variáveis de condicionais:
    lw a5, zero
    lw x15, um
    lw x16, vinteCinco
    lw x17, trintaDois
# a >= 0
    bge a1, zero, condA
halt

# b <= 32
condA:
	bltu a2, x17, condB
	beq a2, x17, condB
halt
# c > 25
condB:
	beq a3, x16, condC
	bltu a3, x16, condC
	add a4, a4, x15
halt
# exit
condC:
halt
# Pondo na memória uma variável.
a: .word 10
b: .word 10
c: .word 10
x: .word 0

zero: .word 0
um: .word 1
vinteCinco: .word 25
trintaDois: .word 32

