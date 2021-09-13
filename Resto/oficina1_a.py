from sklearn import datasets 
#visualização de dados:
import seaborn as sns 
#manipulação de dados:
import pandas as pd
# Visualização de Dados
import matplotlib.pyplot as plt 
# mesma importação para rcParams
import matplotlib as mpl
#plotar curvas
from pandas.plotting import andrews_curves

irisP = datasets.load_iris() #utilizando primeiro import

irisB = sns.load_dataset('iris') #utilizando o segundo import
# print(irisB.head()) #mostrar o irisB

url = 'https://raw.githubusercontent.com/jbrownlee/Datasets/master/iris.csv'
irisU = pd.read_csv(url) #utilizando terceiro import
# print(irisU) #mostrar o irisU 

# print(irisU.shape) #tamanho linhas/colunas
# print(irisU.info) #também mostra com mais informações

# mpl.rcParams['figure.figsize'] = (10,8)
# sns.scatterplot(x = irisB.petal_length, y= irisB.petal_width, hue=irisB.species)
# print(sns.swarmplot(x='species', y = 'sepal_width', data=irisB))
# sns.swarmplot(x='species', y='sepal_width', data=irisB)

print(pd.plotting.andrews_curves(irisB, 'species'))