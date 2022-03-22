# PARAR PASSAR A OUTRO JOGADOR: TECLE ESPACO
# AUMENTE O TEMPO DO CLOCK
# PLAYER 1 WINS: µ
# PLAYER 2 WINS: Þ
# TIE (EMPATE): ½

lw s3, SPACE
addi s2, s2, 1 # flag true

loop: 
  lb a1, 1025(x0) # Tomando caracteres do teclado
  beq a1, s3, troca # Teclou SPACE
  lw a3, A # Iniciando no A
# Verificar todo alfabeto:
  beq a1, a3, plusOne # Teclou A
  addi a3, a3, 1 
  beq a1, a3, plusThree # Teclou B
  addi a3, a3, 1 
  beq a1, a3, plusThree # Teclou C
  addi a3, a3, 1 
  beq a1, a3, plusTwo # Teclou D
  addi a3, a3, 1 
  beq a1, a3, plusOne # Teclou E
  addi a3, a3, 1 
  beq a1, a3, plusFour # Teclou F
  addi a3, a3, 1 
  beq a1, a3, plusTwo # Teclou G
  addi a3, a3, 1 
  beq a1, a3, plusFour # Teclou H
  addi a3, a3, 1 
  beq a1, a3, plusOne # Teclou I
  addi a3, a3, 1 
  beq a1, a3, plusEight # Teclou J
  addi a3, a3, 1 
  beq a1, a3, plusFive # Teclou K
  addi a3, a3, 1 
  beq a1, a3, plusEight # Teclou L
  addi a3, a3, 1 
  beq a1, a3, plusThree # Teclou M
  addi a3, a3, 1 
  beq a1, a3, plusThree # Teclou N
  addi a3, a3, 1 
  beq a1, a3, plusOne # Teclou O
  addi a3, a3, 1 
  beq a1, a3, plusThree # Teclou P
  addi a3, a3, 1 
  beq a1, a3, plusTen # Teclou Q
  addi a3, a3, 1 
  beq a1, a3, plusFive # Teclou R
  addi a3, a3, 1 
  beq a1, a3, plusFive # Teclou S
  addi a3, a3, 1 
  beq a1, a3, plusTwo # Teclou T
  addi a3, a3, 1 
  beq a1, a3, plusOne # Teclou U
  addi a3, a3, 1 
  beq a1, a3, plusFour # Teclou V
  addi a3, a3, 1 
  beq a1, a3, plusFour # Teclou W
  addi a3, a3, 1 
  beq a1, a3, plusEight # Teclou X
  addi a3, a3, 1 
  beq a1, a3, plusFour # Teclou Y
  addi a3, a3, 1 
  beq a1, a3, plusTen # Teclou Z
  addi a3, a3, 1 
jal a2, loop

troca:
  beq a6, s2, verificar
  addi a5, a4, 0 # Guardando a pontuação do P1
  sub a4, a4, a4 # Zerando para contabilizar o P2
  addi a6, a6, 1
jal a2, loop

verificar:
  beq a4, a5, tie # P1 == P2 Tie
  bge a5, a4, playerOne # P1 > P2
  bltu a5, a4, playerTwo # P1 < P2
halt

plusOne:
  addi a4, a4, 1
jal a2, loop

plusTwo:
  addi a4, a4, 2
jal a2, loop

plusThree:
  addi a4, a4, 3
jal a2, loop

plusFour:
  addi a4, a4, 4
jal a2, loop

plusFive:
  addi a4, a4, 5
jal a2, loop

plusEight:
  addi a4, a4, 8
jal a2, loop

plusTen:
  addi a4, a4, 10
jal a2, loop

# Player One wins
playerOne:
  sub a1, a1, a1
  addi a1, s4, 49 # 1
  sb a1, 1024(x0)
halt

# Player Two wins
playerTwo:
  sub a1, a1, a1
  addi a1, s4, 50 # 2
  sb a1, 1024(x0)
halt

# Tie
tie:
  sub a1, a1, a1
  addi a1, s4, 48 # 0
  sb a1, 1024(x0)
halt

A: .word 65
SPACE: .word 32