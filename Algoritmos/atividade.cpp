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
        Node *atual = NULL;
    public:
        Fila (){
            tail = (Node *) malloc(sizeof(Node));
            if (tail == NULL) {
                printf("Erro na cauda\n");
                return NULL;
            }
            head = (Node *) malloc(sizeof(Node));
            if (head == NULL) {
                printf("Erro na cabeca\n");
                return NULL;
            }
            atual = (Node *) malloc(sizeof(Node));

            tail->next = NULL; tail->id = 2021;
            head->next = tail; head->id = 2021;
            atual->next = head;
        }
        Fila insert(Node *N);
        bool processor(int T);
        Node* Scheduler();
};

class Pilha {
    private:
        Node *top = NULL;
    public:
        Pilha (){
            top = (Node *) malloc(sizeof(Node));
            if (top == NULL) {
                printf("Erro no topo\n");
                return NULL;
            }
            top->next = NULL; top->id = 2021;
        }
        void Unloader();
        Node* insert(Node *top, int y);
};

Node* Load(int x, int y);

int main() {
    int K, X, T;
    bool verif = false;
    string process;
    Fila *input = new Fila();
    Fila *work = new Fila();
    Pilha *output = new Pilha();
    Node *novoNo = NULL;
    
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
            input->Scheduler();
            verif = work->processor(T);
            if (verif == true) {
                work->Scheduler();
            }
        }
    }
}

Node* Load(int x, int y) {
    Node *N;
    N = (Node *) malloc(sizeof(Node));
    if (N == NULL) {
        cout << "Error";
        return NULL;
    }
    N->id = x;
    N->val = y;
    return N;
}

Fila* Fila::insert(Node *N) {
    Node *tail = fila->tail;

    N->next = tail->next == NULL ? tail : tail->next;
    tail->next = N;
    //Dá uma olhada no que vai retornar!
    return tail;
}

void Fila::Scheduler() {
    Node *p = NULL;
    
    p = head->next;
    if (head->next->next != NULL) {
        while (p->next != NULL) {
            p = p->next;
            head = head->next;
        }
        head->next = NULL;
        int v = p->val;
        cout << endl << "Saiu " << v << endl;
    }
}

bool Fila::processor(int T) {
    bool id = false, saida = false;
    
    while (id == false) {
        if (atual->next->id != 2021) {
            atual->next->val -= T;
            if (atual->val < 0) {
                saida = true;
            }
        }
        atual = atual->next;
    }

    return saida;
}

void Pilha::Unloader() {
    Node *p = NULL;
    if (top->next != NULL) {
        p = top->next;
        top->next = p->next;
        int v = p->val;
        printf("Saiu %d\n", v);
        free(p); 
    }
}

Node* Pilha::insert(Node *top, int y) {
    Node *N;
    N = (Node *) malloc(sizeof(Node));
    if (N == NULL) {
        cout << "Error";
        return NULL;
    }
    N->val = y;
    N->next = top->next;
    top->next = N;
    return top;
}
