#include <iostream>

#include <stack>

using namespace std;

int main() {
    //Enum: trata de valores inteiros; 
    enum variavel {v1, v2, v3}; 
    //Como se fosse uma estrutura, onde o valor padrão é +1 do elemento anterior [0,1,2] 
    variavel A = v2; //v2 == 1 
    
    enum var {v1 = 5, v2, v3}; // v2 == 6 ^ v3 == 7

    //Pilha/Stack: Precisa do #include <stack> 
    stack <string> nome;
    //Pilha tem tamanho dinâmico e funciona como uma orientação a objetos 
    nome.push("Daniel"); 
    nome.push("Danilo"); 
    //Para retirar um elemento do topo 
    nome.pop(); 
    //mostrar 
    nome.top();
    //Verificar se pilha está vazia
    if (nome.size() == 0) {
        if (nome.empty()) {
            //Retorna true ou false
        }
    }
    //Algoritmo para esvaziar pilha:
    if (!nome.empty()) {
        nome.pop();
    }
    //Também tem emplace e swap
    return 0;
}
