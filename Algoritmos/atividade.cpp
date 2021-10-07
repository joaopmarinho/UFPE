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
        }

        void insert(Node *N);
        void processor(int T, Node *head);
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
    Node *novoNo = NULL, *head, *top, *process, *escalonador, *tail;
    
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
            process = work->setHead();
            escalonador = work->setTail();
            top = output->setTop();
            head = input->setHead();
            tail = input->setTail();
            Scheduler(process, escalonador, top, head, tail);
            work->processor(T, process);
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

    Node *p = N;
    for (int i = 0; i < 20 && p->id != 2021; i++) {
        printf("%d ", p->id);
        p = p->next;
    }
    printf("\n");
}

void Scheduler(Node *head, Node *tail, Node *T, Node *h, Node *t) {
    Node *p = tail.next;
    
    if (tail->next == NULL) printf("Vazio\n");
    else {
        if (p->val <= 0) {
            printf("Acabou o tempo\n");
            tail = head->next; //Scheduler aponta pra nó Processor
            head->next->next = p->next; //Nó processor para próximo
            //Colocou nó zerado na pilha
            p->next = T->next == NULL ? tail : tail->next;
            T->next = p;
        } else {
            printf("Faz nada\n");
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

            aux->next = tail->next == NULL ? tail : tail->next;
            tail->next = aux;
            //Colocando o ponteiro do head circular
            p->next = t;

        } else {
            printf("Fila vazia\n");
        }
    }
}

void Fila::processor(int T, Node *head, Node *tail) {
    Node *p = head.next;
    if (tail->next == NULL) printf("Vazio\n");
    else {
        p->val -= T;
        head = p->next;
        tail = tail->next;
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
