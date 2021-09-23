#Estudando Oficina01 - Oficina de Python

nome = "Daniel"
idade = 20
salario = 499.9
animais = ["Zyra", "Nicolas", "Suzan"]
listaNumerica = [3,2,14,5]

print("Minha gata é "+animais[0], " e meu cadela é "+animais[2], "\n")
print("Meu nome é {}, tenho {} anos,".format(nome, idade, salario))
print(" e ganho um salário de aproximadamente %d reais. \n" %salario)

# type() mostra o tipo, você pode converter como float()

seuNome = input("Digite seu nome: ")
suaIdade = input("Digite sua idade: ")

print("\nSeu nome é {}, e tem {} anos".format(seuNome, suaIdade) )

# ##Questão de operadores é idêntico a outras linguagens, com apenas uma novidade
#and - verifica se multiplas verificações são validas (a and b)
# or - verifica se alguma verificação é valida (a or b)
# not - verifica se a verificação é invalida not(a and b)

#For é diferente, bem mais pobre e genérico

for x in "banana":
    print(x) #perceba que vem automaticamente com \n

#len() mede, seria o length

frutas = ["maçã", "banana", "cereja"]
for x in frutas:
  if x == "banana":
    continue #Interrompe a interação atual e continua na próxima!
  print(x) 

for x in range(2, 6): #Perceba que ele cria a váriavel x, pois x tinha antes...
    print(x)

#While é bem tranquilo, while i < 6, com a váriavel sendo criada anteriormente (continue e break)

# Numpy: manipulação de Dados
# Scipy: manipulação de Dados e estatística
# Pandas: manipulação de Dados
# Matplotlib: para Visualização de Dados
# Seaborn: para Visualização de Dados
# Scikit-learn: para Machine Learning
# TensorFlow: para Deep Learning
# NLTK: para Linguagem Natural
# StatsModel: estatística
# Scrapy: webscraping, raspagem de sites