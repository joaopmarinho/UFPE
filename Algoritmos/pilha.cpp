#include <iostream>

using namespace std;

typedef struct {
    int val;
    struct Node *next;

    Node* insert(Node *cur, int y) {
        Node *N;
        N = (Node *) malloc(sizeof(Node));
        if (N == NULL) {
            cout << "Error";
            return NULL;
        }
        N->val = y;
        N->next = cur->next;
        cur->next = N;
        return cur;
    }

    Node* list_delete(Node *cur) {
        Node *p = NULL;
        if (cur->next != NULL) {
            p = cur->next;
            cur->next = p->next;
            int v = p->val;
            cout << "Saiu " << v << endl;
            free(p); 
        }
        return cur;
    }
} Node;

int main() {
    Node *top = NULL;

    top = (Node *) malloc(sizeof(Node));
    if (top == NULL) printf("Chorou2");

    top->next = NULL;

    int escolha, valor;

    do {
    printf("\n0. Sair\n1. Inserir\n2. Retirar\n");
    scanf("%d", &escolha);

        if (escolha == 1) {
            printf("Digite o valor: \n");
            scanf("%d", &valor);
            top->insert(top, valor);

        } else if (escolha == 2) {
            top->list_delete(top);

        } else {
            if (escolha == 0) {
                printf("Saindo\n");
            } else {
                printf("Escolha invalida");
                scanf("%d", &escolha);
            }
        }
    } while (escolha != 0);
    
    free(top);
}