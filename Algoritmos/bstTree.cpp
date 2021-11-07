#include <iostream>

using namespace std;

struct Node {
    Node *left = NULL;
    int value = 0;
    Node *right = NULL;
};

void visit(Node *root) {
    printf("%d", root->value);
}

void posOrder(Node *root) {
    if (root != NULL) {
        posOrder(root->left);
        posOrder(root->right);
        visit(root)
    }
}

int height(Node *root) {
    int HL = 0, HR = 0;
    if (root != NULL) {
        HL = height(root->left);
        HR = height(root->right);
        return 1+max(HL, HR);
    }
}

Node *insert(Node *root, int v) {
    Node *N = NULL;
    if (root == NULL) {
        N = new Node[1];
        N->value = v;
        return N;
    }
    if (v < root->value) {
        root->left = insert(root->left, v);
        return root;

    } else {
        root->right = insert(root->right, v);
        return root;
    }
} 

Node *left(Node *root) {
    Node *R, *RL;
    R = root->right;
    RL = R->left;
    R->left = root;
    root->right = RL;
    return R;
}

Node *right(Node *root) {
    Node *R, *RR;
    R = root->left;
    RR = R->right;
    R->right = root;
    root->left = RR;
    return R;
}

int main() {
    Node *source, *target;
    int N = 0, x = 0, L = 0, R = 0;
    bool verif;
    
    while (1) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> x;
        }

        for (int i = 0; i < N; i++) {
            cin >> x; 
        }
    }
}