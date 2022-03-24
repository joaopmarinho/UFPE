# Setando varíavel enter
lw x16, end
lw x18, flag # flag1 = 1

jogo:
  lb x13, 1025(x0)
  # Leitura do teclado  
  lw x14, A
  beq x13, x14, cont1 # A
  addi x14, x14, 1    
  beq x13, x14, cont3 # B
  addi x14, x14, 1    
  beq x13, x14, cont3 # C
  addi x14, x14, 1    
  beq x13, x14, cont2 # D
  addi x14, x14, 1    
  beq x13, x14, cont1 # E
  addi x14, x14, 1    
  beq x13, x14, cont4 # F
  addi x14, x14, 1    
  beq x13, x14, cont2 # G
  addi x14, x14, 1    
  beq x13, x14, cont4 # H
  addi x14, x14, 1    
  beq x13, x14, cont1 # I
  addi x14, x14, 1    
  beq x13, x14, cont8 # J
  addi x14, x14, 1
  beq x13, x14, cont5 # K
  addi x14, x14, 1    
  beq x13, x14, cont8 # L
  addi x14, x14, 1    
  beq x13, x14, cont4 # M
  addi x14, x14, 1    
  beq x13, x14, cont3 # N
  addi x14, x14, 1    
  beq x13, x14, cont1 # O
  addi x14, x14, 1    
  beq x13, x14, cont3 # P
  addi x14, x14, 1    
  beq x13, x14, cont10 # Q
  addi x14, x14, 1    
  beq x13, x14, cont5 # R
  addi x14, x14, 1    
  beq x13, x14, cont5 # S
  addi x14, x14, 1    
  beq x13, x14, cont2 # T
  addi x14, x14, 1    
  beq x13, x14, cont1 # U
  addi x14, x14, 1    
  beq x13, x14, cont4 # V
  addi x14, x14, 1    
  beq x13, x14, cont4 # W
  addi x14, x14, 1    
  beq x13, x14, cont8 # X
  addi x14, x14, 1    
  beq x13, x14, cont4 # Y
  addi x14, x14, 1    
  beq x13, x14, cont10 # Z
  beq x13, x16, next # Se enter: próxima fase
jal x10, jogo

next:
  beq x17, x18, comp 
  # flag == flag1
  add x11, x11, x12  # Coloca os pontos no P1
  sub x12, x12, x12  # Zera a pontuação
  addi x17, x17, 1   # flag++
jal x10, jogo

comp:
  beq x11, x12, empate 
  # P1 == P2
  bge x11, x12, playerA
  # P1 > P2
  bltu x11, x12, playerB
  # P1 < P2
halt

playerA:
  lw x13, A
  sb x13, 1024(x0)
halt

playerB:
  lw x13, B
  sb x13, 1024(x0)
halt

empate:
  lw x13, E
  sb x13, 1024(x0)
halt

cont1:
  addi x12, x12, 1
jal x10, jogo

cont2:
  addi x12, x12, 2
jal x10, jogo

cont3:
  addi x12, x12, 3
jal x10, jogo

cont4:
  addi x12, x12, 4
jal x10, jogo

cont5:
  addi x12, x12, 5
jal x10, jogo

cont8:
  addi x12, x12, 8
jal x10, jogo

cont10:
  addi x12, x12, 10
jal x10, jogo

A: .word 'A'
B: .word 'B'
E: .word 'E'
flag: .word 1
end: .word 13