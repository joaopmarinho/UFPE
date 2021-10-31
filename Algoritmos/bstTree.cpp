#include <iostream>

using namespace std;

struct Node {
    Node *left;
    int value;
    Node *right;
};

class BST {
    public:
        Node *source;
        Node *target;
        BST() {
            source = NULL;
            target = NULL;
        }
        Node* bstInsert(Node *tree, int x) {
            
        }
};

int main() {
    BST *tree = new BST();
    int N = 0, x = 0, L = 0, R = 0;
    bool verif;
    
    while (1) {
        cin >> N;
        tree->source = (Node*) calloc(N, sizeof(Node));
        tree->target = (Node*) calloc(N, sizeof(Node));

        for (int i = 0; i < N; i++) {
            cin >> x;
            tree->bstInsert(tree->source, x);
        }

        for (int i = 0; i < N; i++) {
            cin >> x; 
            tree->bstInsert(tree->target, x);
        }
    }
}