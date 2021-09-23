#include <iostream>

using namespace std; 

struct Funcao {
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

struct Node {
    int value;
    //Ponteiro para próximo:
    Node *prev = NULL;
    //Constructor da struct:
    Node (int inicio, Node *anterior): value(inicio), prev(anterior){};
    Node (int inicio): value(inicio){};
    //Estrutura:
};

int main() {
    //Struct padrão

    Funcao teste;
    teste.inserir(10, "Arrocha");
    teste.mostrar();

    //Alocando Struct normal:
    Node *no = NULL;
    no = (Node *) malloc(sizeof(Node));
    free(no);

    //new dá um malloc por debaixo dos panos
    Node *node1 = new Node(1);
    Node *node2 = new Node(2, node1);

    cout << node1->prev << endl;
    cout << node1->value << endl << "___" << endl;

    cout << (node2->prev)->value << endl;
    cout << node2->value << endl;

    free(node1);
    free(node2);
    //Quando se usa objetos não precisa criar ponteiros!
    return 0;
}