#include <iostream>
#include <string>

using namespace std;
struct Node {
    int id;
    int val;
    struct Node *next = nullptr;
};
class Fila {
    private:
        Node *tail = nullptr;
        Node *head = nullptr;

    public:
        Fila (){
            head = tail; 
        }

        void insert(Node *N);
        void processor(int T, Node *head, Node *tail);
        Node* setTail() {return tail;};
        Node* setHead() {return head;};
};
class Pilha {
    private:
        Node *top = nullptr;
    public:
        Pilha (){
            top = (Node *) malloc(sizeof(Node));
            top->next = nullptr;
        }
        void Unloader();
        Node* setTop() {return top;};
        ~Pilha () {
            free(top);
        }
};

Node* Load(int x, int y);
void Scheduler(Node *head, Node *tail, Node *T, Node *h, Node *t);

int main() {
    int K, X, T;
    string process;
    Fila *input = new Fila();
    Fila *work = new Fila();
    Pilha *output = new Pilha();
    Node *novoNo = nullptr, *head, *top, *proc, *escl, *tail;
    
    cin >> K;
    while (process != "END") {
        cin >> process;
        if (process == "LOAD") {
            cin >> X >> T;
            novoNo = Load(X, T);
            input->insert(novoNo);

        } else if (process == "UNLD") {
            output->Unloader();

        } else if (process == "PROC") {
            proc = work->setHead();
            escl = work->setTail();
            top = output->setTop();
            head = input->setHead();
            tail = input->setTail();

            Scheduler(proc, escl, top, head, tail);
            work->processor(K, proc, escl);
        }
    }
}

Node* Load(int x, int y) {
    Node *N;
    N = (Node *) malloc(sizeof(Node));
    if (N == nullptr) {
        printf("Error na criacao do no\n");
        return nullptr;
    }
    N->id = x; //ID
    N->val = y; //Tempo
    return N;
}

void Fila::insert(Node *N) {
    if (head == tail) head = N;
    else head->next = N;
    
    N->next = tail;
    tail = N;
}

void Scheduler(Node *head, Node *tail, Node *T, Node *h, Node *t) {
    Node *p = tail;
    if (p != nullptr && p->val <= 0) {
        Node *n = head;
        //Cauda anda para cabeça se não for o mesmo nó
        if (n == tail) {
            //Inicia como 0
            tail = nullptr;
            head = tail;
        } else {
            //Cauda volta
            tail = tail->next; 
        }
        //Nó da cabeça for igual ao que vai retirar
        if (n->next == p || n->next == nullptr) {
            //Tira sua ligação
            n->next = tail;
        } else {
            //Cabeça volta:
            // head = n->next;

            //Ligar o ciclo:
            while (n->next != p) {
            //Procurar quem apontava pra
            //Node que vai sair
                n = n->next;
            }
            n->next = tail;
        }
        //Ligar ele a pilha:
        p->next = T->next == nullptr ? nullptr : tail;
        T->next = p;
    }

    if (h->next != t) {
        p = t->next;
        while (p->next != h->next) {
            p = p->next;
        }
        h->next = p;
        //Tratando de tirar o nó.
        Node *aux = p->next;

        if (head == tail) head = aux;
        else head->next = aux;

        aux->next = (tail) == nullptr ? nullptr : tail;
        tail = aux;
        //Colocando o ponteiro do head circular
        p->next = t;
    } 
}

void Fila::processor(int T, Node *head, Node *tail) {
    Node *p = head;

    if (tail != nullptr) {
        p->val = (p->val - T) < 0 ? 0 : p->val - T;
        printf("PROC %d %d\n", p->id, p->val);
        printf("%d\n", p->next->id);
        head = (p->next) == nullptr ? head : p->next;
        tail = (tail->next) == nullptr ? tail : tail->next;
    } else {
        printf("PROC -1 -1\n");
    }
}

void Pilha::Unloader() {
    Node *p = nullptr;
    if (top->next != nullptr) {
        p = top->next;
        top->next = p->next;
        printf("UNLD %d\n", p->id);
        free(p); 
    }
}
