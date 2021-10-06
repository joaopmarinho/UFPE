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
            head = (Node *) malloc(sizeof(Node));

            tail->next = NULL; tail->id = 2021;
            head->next = tail; head->id = 2021;
            atual = head;
        }

        void insert(Node *N);
        bool processor(int T, Node *N);
        void Scheduler(Node *N, Node *H, Node *T, bool type);
        Node* setTail() {return tail;};
        Node* setHead() {return head;};
};
class Pilha {
    private:
        Node *top = NULL;
    public:
        Pilha (){
            top = (Node *) malloc(sizeof(Node));
            top->next = NULL; top->id = 2021;
        }
        void Unloader();
        Node* insert(Node *top, int y);
        Node* setTop() {return top;};
};

Node* Load(int x, int y);

int main() {
    int K, X, T;
    bool verif = false;
    string process;
    Fila *input = new Fila();
    Fila *work = new Fila();
    Pilha *output = new Pilha();
    Node *novoNo = NULL, *head, *top;
    
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
            //ESCALONADOR ELSE VEM PRIMEIRO!
            verif = work->processor(T, novoNo);

            if (verif == true) {
                head = work->setHead();
                top = output->setTop();
                work->Scheduler(novoNo, head, top, verif);

            } else {
                head = input->setHead();
                top = work->setTail();
                input->Scheduler(novoNo, head, top, verif);

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

void Fila::insert(Node *N) {
    N->next = tail->next == NULL ? tail : tail->next;
    tail->next = N;
}

void Fila::Scheduler(Node *N, Node *H, Node *T, bool type) {
    Node *p = NULL;
    if (type == false) {
        p = H->next;
        while (p->next != NULL) {
            p = p->next;
            H = H->next;
        }
        H->next = NULL;
        p->next = T->next == NULL ? tail : tail->next;
        T->next = p;
    
    } else {
        p = N->next;
        N->next = N->next->next;

        p->next = T->next == NULL ? tail : tail->next;
        T->next = p;
    }  
}

bool Fila::processor(int T, Node *N) {
    bool id = false, saida = false;
    
    for (int i = 0; i < 3 && id == false; i++) {
        if (atual->next->id != 2021) {
            if (atual->next->val < 0) {
                saida = true;
                N = atual;
            } else {
                atual->next->val -= T;
                int tempo = atual->next->val >= 0 ? atual->next->val : 0;
                printf("PROC %d %d\n", atual->next->id,tempo);
            }
            id = true;
        }
        atual = atual->next;
    }  
    if (id != true) printf("PROC -1 -1\n");

    return saida;
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
