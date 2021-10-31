/* Nome do aluno: Lucas Medjad da Costa Nascimento 
Turma: 2021-1 1º periodo CIN 'EC' 
turno: Manhã
Materia: IP 
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

int main (void)
{
  int matriz[30][30],i, j;
  
  printf ("\nDigite valor para os elementos da matriz\n\n");
  
  for ( i=0; i<30; i++ )
    for ( j=0; j<30; j++ )
    {
      printf ("\nElemento[%d][%d] = ", i, j);
      scanf ("%d", &matriz[ i ][ j ]);
    }
  
  printf("\n\n******************* Saida de Dados ********************* \n\n");
  
  for ( i=0; i<30; i++ )
    for ( j=0; j<30; j++ )
    {
      printf ("\nElemento[%d][%d] = %d\n", i, j,matriz[ i ][ j ]);
    }
  
  getch();
  return(0);
}