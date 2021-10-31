#include<stdio.h>
#include<string.h>

int main()
{
	int N, i, j, k;
	int soma = 0;
	char pedaco_de_senha[30];
	printf("Digite a dimensão da matriz: ");
	scanf("%d", &N);

	//flags
	int diagonal = 1;

	//definindo a matriz de strings
	char matriz_de_nomes[N][N][30];

	printf("Digite agora as %d strings que comporão a matriz %d x %d: \n", N*N, N, N);
	//preenchendo a matriz de strings
	for (i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			scanf("%s", matriz_de_nomes[i][j]);
		}

	//elemento da diagonal principal deve ter tamanho igual a posição do seu sucessor
	//ex: a[0][0]: tamanho 1; a[1][1]: tamanho 3; etc
	
	for(i=0;i<N;i++)
	{
		if(strlen(matriz_de_nomes[i][i]) != i+i+1)
		{
			diagonal = 0;
		}
		for(j=0;j<strlen(matriz_de_nomes[i][i]);j++)
		{
			if(matriz_de_nomes[i][i][j] != 97 && matriz_de_nomes[i][i][j] != 101 && matriz_de_nomes[i][i][j] != 105 && matriz_de_nomes[i][i][j] != 111 && matriz_de_nomes[i][i][j] != 117)//só vogais minúsculas
			{
				diagonal = 0;
			}
		}
	}

	//printf("propriedade satisfeita? %d\n", diagonal);
	//se satisfizer, tem que gerar a senha do usuário:
	if(diagonal==1)
	{
		printf("Sua senha é ");
		for (i=0;i<N;i++)
			for(j=0;j<N;j++)
			{
				if(i==j)//elemento diagonal
					printf("%s",matriz_de_nomes[i][j]);//mostra na tela o próprio elemento

				else if(i != j)//elemento fora da diagonal
				{
					//reinicia a soma
					soma = 0;
					//soma cada char da string fora da diagonal e armazena em soma
					for(k=0;k<strlen(matriz_de_nomes[i][j]);k++)
					{
						soma += matriz_de_nomes[i][j][k];
					}

					//transforma soma em uma string e mostra na tela
					sprintf(pedaco_de_senha, "%d", soma);
					printf("%s", pedaco_de_senha);
				}
				
			}
			printf("\n");
	}
	else
	{
		printf("Matriz não satisfaz a propriedade!\n");
	}

	
	return 0;
}