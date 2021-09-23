#include <iostream>

using namespace std;

class veiculo {
    public:
        int vel = 0;
        void setTipo (string tp);
        void setMax (int vm);
        void mostra();
    private:
        int velMax;
        string tipo;
};

void veiculo::setTipo(string tp) {
    tipo = tp;
}

void veiculo::setMax(int vm) {
    velMax = vm;
}

void veiculo::mostra() {
    std::cout << "Tipo " << tipo << std::endl;
    std::cout << "velocidade Maxima " << velMax << std::endl;
    std::cout << "velocidade atual " << vel << std::endl;
}

class Carro:public veiculo {
    public:
     //Contructor
       Carro(string tp, int vm);
};

Carro::Carro(string tp, int vm) {
    std::cout << "Prototipo de Carro pronto" << std::endl;
    setTipo(tp);
    setMax(vm);
}

class Moto: public veiculo {
    public:
        Moto(string tp, int vm);
};

Moto::Moto (string tp, int vm) {
    std::cout << "Prototipo de Moto pronto" << std::endl;
    setTipo(tp);
    setMax(vm);
}

int main() {
    Carro *fusca = new Carro("Fusca", 80);
    Moto *Bis = new Moto("Bis", 120);

    fusca->mostra();
    Bis->mostra();
}
