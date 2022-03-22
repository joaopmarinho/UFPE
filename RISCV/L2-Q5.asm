# PARAR TECLE ESPACO
# AUMENTE O TEMPO DO CLOCK

lw a3, A
lw a4, E
lw a5, I
lw a6, O
lw s2, U
lw s3, SPACE

loop: 
  lb a1, 1025(x0) # Tomando caracteres do teclado
  beq a1, s3, imprimir # Teclou SPACE
  beq a1, a3, adicionar # Teclou a
  beq a1, a4, adicionar # Teclou e
  beq a1, a5, adicionar # Teclou i
  beq a1, a6, adicionar # Teclou o
  beq a1, s2, adicionar # Teclou u
jal a2, loop

adicionar:
  addi s4, s4, 1
jal a2, loop

imprimir:
  addi a1, s4, 48
  sb a1, 1024(x0)
  sub s4, s4, s4
jal a2, loop

A: .word 97
E: .word 101
I: .word 105
O: .word 111
U: .word 117
SPACE: .word 32