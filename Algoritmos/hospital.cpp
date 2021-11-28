#include <iostream>

using namespace std;

struct Hospital {
    int ID;
    int caso;
};

struct Sistema {
    int tamanho;
    int somaTotal;
    int IDseq;
    Hospital hospital[1000];
    Sistema() {
        tamanho = 0;
        somaTotal = 0;
        IDseq = 0;
    }
};

Hospital* heap(Hospital) {
    H[i].id = id;
    H[i].caso = caso;
    BubbleUp(H);
    return H;
}

int main() {
    string input;
    Sistema *sistema = new Sistema();
    int N, caso;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> caso;
        sistema->somaTotal += caso;
    }

    while (input != "END") {
        if (input == "NEW") {

        } else if (input == "DEL") {

        } else if (input == "IN") {

        } else if (input == "OUT") {
            
        } else if (input == "PAY") {

        }
    }
}