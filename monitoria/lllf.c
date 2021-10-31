#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("Digite a dimensão da matriz: ");
	int tamanho, i, j, k; scanf("%i", &tamanho);
	char matriz[tamanho][tamanho][31];
	printf("Digite agora as %i strings que comporão a matriz %i x %i:\n", tamanho*tamanho, tamanho, tamanho);

	for (i = 0; i < tamanho; i++)
	{
		for (j = 0; j < tamanho; j++)
		{
			char elemento[31]; scanf(" %s", &elemento);
			strcpy(matriz[i][j], elemento);
		}
	}

	int valido = 1;
	for (i = 0; i < tamanho; i++)  // verificando se a matriz é válida :)
	{
		for (j = 0; j < tamanho; j++)
		{	
			if (i == j)
			{
				if (strlen(matriz[i][j]) != (i + j + 1))
				{
					valido = 0;
				}

				for (k = 0; k < strlen(matriz[i][j]); k++)
				{
					char caractere = matriz[i][j][k];
					if (caractere < 97 || caractere > 122)
					{
						valido = 0;
					}
				}
			}

			else
			{
				for (k = 0; k < strlen(matriz[i][j]); k++)
				{
					char caractere = matriz[i][j][k];
					if (caractere < 65 || caractere > 90)
					{
						valido = 0;
					}
				}
			}	
		}
	}

	if (!valido)
	{
		printf("matriz invalida :(, %i", valido);
		return 0;
	}
	
	char senha[50]; // me livrando de garbage values :)

	for (i = 0; i < 50; i++)
	{
		senha[i] = NULL;
	}

	for (i = 0; i < tamanho; i++)
	{
		for (j = 0; j < tamanho; j++)
		{
			if (i == j)
			{
				strcat(senha, matriz[i][j]);
			}

			else
			{
				int soma_ascii = 0;
				char string[100];

				for (k = 0; k < strlen(matriz[i][j]); k++)
				{
					soma_ascii += (int) matriz[i][j][k];
				}

				sprintf(string, "%d", soma_ascii);
				strcat(senha, string);
			}
		}
	}

	printf("%s", senha);
	return 0;
}