#include <iostream>

using namespace std;
//Orientação a objetos
class Aviao {
    public:
        int vel = 0;
        int velMax;
        string tipo;
        void init(int tipo);
    private:

};

void Aviao::init(int tipo) {
    if (tipo == 1) {
        this->velMax = 800;
        this->tipo = "Jato";
    } 
    else if (tipo == 2) {
        this->velMax = 350;
        this->tipo = 'Carga';
    }
    else if (tipo == 3) {
        this->velMax = 180;
        this->tipo = 'Planador';
    }
}

int main() {
    Aviao *aviao = new Aviao();
    aviao->init(1);
    // aviao->init(2);
    // aviao->init(3);
    cout << aviao->vel << " " << aviao->velMax << " ";

    return 0;
}