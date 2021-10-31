// MINI TESTE1- IP
// Lucas Augusto Silveira Costa
// lasc@cin.ufpe.br
#include <stdio.h>
#include <string.h>
int main()
{
 char entradas[100][100][30];
 char senha[1000]="";
 char buffer[50];
 char c='\0';
 int err=0;
 int n=0;
 int temp=0;
 
 printf("Digite a dimensao da matriz: ");
 scanf("%i", &n);
 
 printf("Digite agora as %i strings que comporao a matriz %i x %i:\n", n*n, n, n);
 for(int i=0; i<n; i++){
 for(int j=0; j<n; j++){
 scanf("%s", entradas[i][j]);
 }
 }
 for(int i=0; i<n; i++){
 for(int j=0; j<n; j++){
 if(i==j){
 for(int k=0; k < strlen(entradas[i][j]); k++){
 c = entradas[i][j][k];
 if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'){
 printf("Incoveniente diagonal: %c\n", c);
 err=1;
 }
 }
 strcat(senha, entradas[i][j]);
 }
 else{
 temp=0;
 for(int k=0; k<30; k++){
 c = entradas[i][j][k];
 if(c == '\0') break;
 if(c >'Z' || c < 'B' || c =='E' || c =='I' || c =='O' || c =='U'){
 printf("Incoveniente: %c\n", c);
 err=1;
 }
 else temp += c;
 
 }
 sprintf(buffer, "%i", temp);
 strcat(senha, buffer); 
 }
 }
 }
 if(1-err) printf("Sua senha eh %s", senha);
 return 0;
}