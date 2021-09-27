#include <iostream>

using namespace std;

int main() {
    auto a = 10;
    //Auto pode ser qualquer variável, contanto que inicialize de início
    register int count;
    //Pedido que armazene no registrador
    //Caso não funcione, torna normal
    //Para variáveis que são usadas demais ou de modo rápido
    static int ficou;
    //Torna a variável global

    //extern
    //Dá a possibilidade de usar a variável de outro arquivo
    //Sem precisar de header

    int x[5]{10, 20, 30, 40, 50};
    //For-range-declaration
    for (int i:x) {
        cout << i << endl;
    }
}