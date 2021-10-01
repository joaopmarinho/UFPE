#include <iostream>

using namespace std;

typedef struct Node{
    int val;
    struct Node *next;

    Node* insert(Node *tail, int y) {
        Node *N;
        N = (Node *) malloc(sizeof(Node));
        if (N == NULL) {
            cout << "Error";
            return NULL;
        }
        N->val = y;
        N->next = tail->next;
        tail->next = N;

        return tail;
    }

    Node* list_delete(Node *head) {
        Node *p = NULL;
        if (head->next != NULL) {
            p = head->next;
            while (p->next != NULL) {
                head->next = p;
                p = p->next;
            }
            int v = p->val;
            cout << endl << "Saiu " << v << endl;
            free(p); 
        }
        return head;
    }

};

int main() {
    Node *tail = NULL, *cabeca = NULL;
    
    cabeca = (Node *) malloc(sizeof(Node));
    if (cabeca == NULL) printf("Chorou1");

    tail = (Node *) malloc(sizeof(Node));
    if (tail == NULL) printf("Chorou2");

    cabeca->next = tail;
    tail->next = NULL;

    int escolha, valor;

    do {
    printf("\n0. Sair\n1. Enfileirar\n2. Desenfileirar\n");
        scanf("%d", &escolha);
        if (escolha == 1) {
            printf("Digite o valor: \n");
            scanf("%d", &valor);
            tail->insert(tail, valor);

        } else if (escolha == 2) {
            cabeca->list_delete(cabeca);
            
        } else {
            if (escolha == 0) {
                printf("Saindo\n");
            } else {
                printf("Escolha invalida");
                scanf("%d", &escolha);
            }
        }
    } while (escolha != 0);
    
    free(cabeca);
    free(tail);
}