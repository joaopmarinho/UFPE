#include <stdio.h>
#include <string.h>
#define TAM_CODE 15
#define N_REG 32

typedef struct{
	int num_instrucao[6];
	char instr_nome[4];
	int destino, origem; //onde fica os indices
}estrutura;

int main(){
	char N_LINHA; // Char?
	int TAM_CODE; // Ele cria o TAM_CODE aqui e o define?
	int valor;
	char codigo[N_LINHA][TAM_CODE]; // Ele usa o lixo de memória aqui
	int reg[32]; // Não utilizou os registradores
	int i;
	
	estrutura estrutura;
	scanf("%d", &N_LINHA); // N_LINHA != número

	for(i=0; i<N_LINHA; i++){
		fflush(stdin);
		// instr_nome[i] não existe no escopo da main
		fgets(instr_nome[i] , 4 , stdin);  //ldv  fgets(string, tamanho, stdin) 
		fflush(stdin);
		// valor = lixo de memória?
		strcpy(estrutura.destino, valor); 
		// strcpy em inteiros? Novidade

		// ????????????????????????????????
		fgest(instr_nome[i], 4, stdin); //swp fGEST!
		strcpy(estrutura.origem[i], estrutura.destino[i]);
		fgets(instr_nome[i], 4, stdin); //mov
		strcpy(estrutura.destino[i], estrutura.origem[i]);
		fgets(instr_nome[i], 4, stdin); //add
		destino=estrutura.destino[i]+estrutura.origem[i];
		destino=estrutura.destino;
		fgets(instr_nome[i], 4, stdin); //sub
		estrutura.destino[i] - estrutura.origem[i];
		fgets(instr_nome[i], 4, stdin); //mul
		estrutura.destino*estrutura.origem;
		
		// ????????????????????????????
	}if(estrutura.origem > N_Reg && estrutura.destino > N_REG){ 
		printf("erro\n") }
		} else{ printf("Valores nos registradores: ");
		printf("register[] = \n");
		printf("register[] = \n");
		}
	
	return 0;
}

// Competência Struct - Falhou
// Competência String - Falhou
// Competência Vetores - Não demonstrado