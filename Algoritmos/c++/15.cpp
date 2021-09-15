//Classe vector
//Um vetor mais moderno

#include <iostream>
#include <vector>
#include <stdlib.h> // System

using namespace std;

int main () {
    vector <int> num; //É alocado dinâmicamente
    //push_back padrão
    for (int i; i < 10; i++) num.push_back(i);
    num.push_back(10);
    //size() para tamanho
    for (int i; i < num.size(); i++) cout << num[i] << " ";
    //Para mostrar pode usar como vetor, levando em conta os espaços
    //swap(vector) Troca os elementos de dois vetores
    cout << "\n" << "Primeiro elemento: " << num.front() << endl;
    cout << "Ultimo elemento: " << num.back() << endl;
    cout << "Elemento do meio: " << num.at(num.size()/2) << endl;
    //Inserir e tirar sem usar o iterator:
    num.insert(num.begin()+2, 7);
    num.erase(num.end() - 7);
    //Também tem o empty, pop_back() tira elemento do final, clear()

    //System mexe como o Prompt de comando
    //system("dir"); Mostra o directório 
    system("cls"); // Limpa
    //system("color 47"); Fundo vermelho, texto branco
    system("pause"); // Espera comando

    return 0;
}