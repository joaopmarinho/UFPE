# Intructions
# [Set Potentiometer in 10000, in A1]
# Dont start in temperature sensor > 30

# LEDS:
# red    3  // red     5
# yellow 6  // yellow  9
# green  10 // green   11

# Leitura analógica: 
sw x10, 1030(x0)

loop:
  lw x10, 1031(x0)

  lw x14, ten
    # < 10?
  bltu x10, x14, acender3
  beq x10, x14, acender3
  addi x14, x14, 100

    # 10 <= 15?
  bltu x10, x14, acender6
  beq x10, x14, acender6
  addi x14, x14, 100

    # 15 <= 20?
  bltu x10, x14, acender9
  beq x10, x14, acender9
  addi x14, x14, 100

    # 20 <= 25?
  bltu x10, x14, acender10
  beq x10, x14, acender10
  addi x14, x14, 100
  
    # 25 <= 30?
  bltu x10, x14, acender11
  beq x10, x14, acender11
  
    # > 30?
  jal x13, acender5

# Escolher pino analógico a acender:
acender3:
  sub x11, x11, x11
  addi x11, x0, 5
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
  addi x11, x0, 6
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 9
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 10
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 11
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

# Acender analogicamente: 
  sub x11, x11, x11
	addi x11, x0, 3
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  addi x12, x12, 511
  sw x12, 1034(x0)
  addi x12, x12, 511

jal x13, loop # Voltar ao loop incial

# Escolher pino analógico a acender:
acender5: 
  sub x11, x11, x11
	addi x11, x0, 3
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 6
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 9
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 10
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 11
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

# Acender analogicamente: 
  addi x11, x0, 5
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  addi x12, x12, 511
  sw x12, 1034(x0)
  addi x12, x12, 511

jal x13, loop # Voltar ao loop incial

# Escolher pino analógico a acender:
acender6:
  sub x11, x11, x11
	addi x11, x0, 3
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
  addi x11, x0, 5
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 9
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 10
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 11
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

# Acender analogicamente: 
  sub x11, x11, x11
	addi x11, x0, 6
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  addi x12, x12, 511
  sw x12, 1034(x0)
  addi x12, x12, 511

jal x13, loop # Voltar ao loop incial

# Escolher pino analógico a acender:
acender9:
  sub x11, x11, x11
	addi x11, x0, 3
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 5
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 6
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 10
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 11
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

# Acender analogicamente: 
  sub x11, x11, x11
	addi x11, x0, 9
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  addi x12, x12, 511
  sw x12, 1034(x0)
  addi x12, x12, 511

jal x13, loop # Voltar ao loop incial

# Escolher pino analógico a acender:
acender10:
  sub x11, x11, x11
	addi x11, x0, 3
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 5
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 6
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 9
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 11
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

# Acender analogicamente: 
  sub x11, x11, x11
	addi x11, x0, 10
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  addi x12, x12, 511
  sw x12, 1034(x0)
  addi x12, x12, 511

jal x13, loop # Voltar ao loop incial

# Escolher pino analógico a acender:
acender11:
  sub x11, x11, x11
	addi x11, x0, 3
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 5
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 6
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 9
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

  sub x11, x11, x11
	addi x11, x0, 10
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  sub x12, x12, x12
  sw x12, 1034(x0)
  sub x12, x12, x12

# Acender analogicamente: 
  sub x11, x11, x11
	addi x11, x0, 11
  sw x11, 1033(x0)

  sw x12, 1034(x0)
  addi x12, x12, 511
  sw x12, 1034(x0)
  addi x12, x12, 511

jal x13, loop # Voltar ao loop incial

ten: .word 200