#include <iostream>
#include <string>

using namespace std;
struct Node {
    int id;
    int val;
    struct Node *next = NULL;
};
class Fila {
    private:
        Node *tail = NULL;
        Node *head = NULL;

    public:
        Fila (){
            tail = (Node *) malloc(sizeof(Node));
            head = (Node *) malloc(sizeof(Node));

            tail->next = NULL; 
            head->next = tail; 
            tail->id = 2021;
        }

        void insert(Node *N);
        void processor(int T, Node *head, Node *tail);
        Node* setTail() {return tail;};
        Node* setHead() {return head;};
};
class Pilha {
    private:
        Node *top = NULL;
    public:
        Pilha (){
            top = (Node *) malloc(sizeof(Node));
            top->next = NULL;
        }
        void Unloader();
        Node* setTop() {return top;};
};

Node* Load(int x, int y);
void Scheduler(Node *head, Node *tail, Node *T, Node *h, Node *t);

int main() {
    int K, X, T;
    string process;
    Fila *input = new Fila();
    Fila *work = new Fila();
    Pilha *output = new Pilha();
    Node *novoNo = NULL, *head, *top, *proc, *escl, *tail;
    
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
    if (N == NULL) {
        printf("Error na criacao do no\n");
        return NULL;
    }
    N->id = x; //ID
    N->val = y; //Tempo
    return N;
}

void Fila::insert(Node *N) {
    if (head->next == tail) head->next = N;
    else head->next->next = N;

    N->next = tail->next == NULL ? tail : tail->next;
    tail->next = N;

}

void Scheduler(Node *head, Node *tail, Node *T, Node *h, Node *t) {
    Node *p = tail->next;
    if (p != NULL && p->val <= 0) {
        cout << "Chegou aqui0" << endl;
        Node *n = head->next;
        //Cauda anda para cabeça se não for o mesmo nó
        if (n == tail->next) {
            //Inicia como 0
            tail->next = NULL;
            head->next = tail;
        } else {
            //Cauda volta
            tail->next = n; 
        }
        cout << "Chegou aqui1" << endl;
        //Nó da cabeça for igual ao que vai retirar
        if (n->next == p || n->next == NULL) {
            //Tira sua ligação
            n->next = NULL;
        } else {
            cout << "Chegou aqui2" << endl;
            //Cabeça volta:
            head->next = n->next;
            //Ligar o ciclo:
            cout << "Chegou aqui3" << endl;
            while (n->next != p) {
                n = n->next;
                cout << "Chegou aqui4" << endl;
            }
            n->next = tail->next;
            cout << "Chegou aqui5" << endl;
        }
        //Ligar ele a pilha:
        p->next = T->next == NULL ? NULL : tail->next;
        T->next = p;
        cout << "Retirou: " << p->id << endl;
        cout << T->next->id << endl;
    }

    if (h->next != t) {
        p = t->next;
        while (p->next != h->next) {
            p = p->next;
        }
        h->next = p;
        //Tratando de tirar o nó.
        Node *aux = p->next;

        if (head->next == tail) head->next = aux;
        else head->next->next = aux;

        aux->next = (tail->next) == NULL ? NULL : tail->next;
        tail->next = aux;
        //Colocando o ponteiro do head circular
        p->next = t;
    } 
}

void Fila::processor(int T, Node *head, Node *tail) {
    Node *p = head->next;
    if (tail->next != NULL) {
        p->val -= T;
        printf("Valor tirado: %d, %d <- %d\n", p->val, tail->next->id, head->next->id);

        head->next = (p->next) == NULL ? head->next : p->next;
        tail->next = (tail->next->next) == NULL ? tail->next : tail->next->next;

        printf("Valor tirado: %d, %d <- %d\n", p->val, tail->next->id, head->next->id);
    }
}

void Pilha::Unloader() {
    Node *p = NULL;
    if (top->next != NULL) {
        p = top->next;
        top->next = p->next;
        printf("UNLD X %d\n", p->id);
        free(p); 
    }
}
