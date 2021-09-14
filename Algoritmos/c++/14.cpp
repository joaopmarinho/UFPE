#include <iostream>

using namespace std; 

struct Funcao{
    int num;
    string nome;
    void inserir(int numero, string word) {
        num = numero;
        nome = word;
    }

    void mostrar() {
        cout << "Nome: " << nome << "\n";
        cout << "Numero: " << num << "\n";
    }
};

int main() {
    Funcao teste;
    teste.inserir(10, "Arrocha");
    teste.mostrar();
    return 0;
}