#include <iostream>

using namespace std;

struct Node {
    int val;
    struct Node *next = NULL;
};

    Node* init(void) {
        return NULL;
    }

    Node* insert(Node *cur, int y) {
        Node *N;
        N = (Node *) malloc(sizeof(Node));
        (*N).val = y;
        N->next = cur->next;
        cur->next = N;
        return cur;
    }

    Node* acess(Node *head, int pos) {
        Node *cur;

        for (int i = 0; i < pos && cur->next != NULL; i++) {
            cur = cur->next;
        }
        
        return cur;
    };

    Node* list_delete(Node *cur) {
        Node *p = NULL;
        p = cur->next;
        cur = p->next;
        int v = p->val;
        free(p); //Desalocar;
        return cur;
    }

    Node* procurar(Node *head, int x) {
        Node *cur = head;
        while (cur->next != NULL && cur->next->val != x) {
            cur = cur->next;
        }
        return cur;
    }

int main() {
    Node *lista;
    lista = init();
    lista = insert(lista, 3);
    // lista = insert(lista, 7);
    // lista = insert(lista, 11);

    cout << "Chorou";

}