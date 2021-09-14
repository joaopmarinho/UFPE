#include <iostream>
//Biblioteca de fila:
#include <queue>
//Biblioteca de Listas:
#include <list>
using namespace std;

int main() {
    //Fila
    queue <string> cartas;
    //Igualmente a pilha:
    cartas.push("Copas");
    cartas.push("Espadas");
    cartas.push("Ouros");
    cartas.push("Paus");
    //front() é primeira posição (copas) e back() a última (Paus)
    while (!cartas.empty())
    {
        cout << "Retirei " << cartas.front() << "\n";
        cartas.pop();
    }

    //Lista
    list <int> lista;
    //Iterator para colocar um elemento no meio
    list <int> :: iterator it;
    it = lista.begin();

    for (int i = 0; i < 10; i++) {
        //inserir elementos é push também, push_back e push_front
        lista.push_back(i);
    }

    advance(it, 5); //Local que vai entrar
    lista.insert(it, 25);
    //lista.sort() para Ordenar lista
    //reverse() inverte a lista
    //lista.merge(ColocaOutraListaAqui) 
    //erase() retira o elemento, precisa do iterator
    lista.erase(--it); //Ao inserir it deu advance
    //clear() remove elementos da lista

    int tamanho = lista.size();
    for (int i = 0; i < tamanho; i++) {
        cout << lista.front() << "\n";
        //Retirar é pop_front() ou pop_back();
        lista.pop_front();
    }

}