#include <iostream>

using namespace std;

struct Node {
    Node *left = NULL;
    int value = 0;
    Node *right = NULL;
};

void visit(Node *root) {
    printf("%d ", root->value);
}

void posOrder(Node *root) {
    if (root == NULL) {
        return ;
    }    
    posOrder(root->left);
    posOrder(root->right);
    visit(root);
}

int height(Node *root) {
    int HL = 0, HR = 0;
    if (root == NULL) {
        return -2;   
    }    
    HL = height(root->left);
    HR = height(root->right);
    return 1+max(HL, HR);
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

Node *etapa(Node *root, int *L) {
    if (root == NULL) {
        return root;
    } 

    if (root->right != NULL) {
        root = left(root);
        *L = *L + 1;
        root = etapa(root, L);
    } else {
        root->left = etapa(root->left, L);
    }
    return root;
}

Node *etapa1(Node *root, int *L, int *R) {
    if (root == NULL) {
        return root;
    }
    int x;
    cin >> x;
    if (root->right == NULL) {
        while (root->value != x) {
            root = right(root);
            *R = *R + 1;
        }
    } else {
        while (root->value != x) {
            root = left(root);
            *L = *L + 1;
        }
    }
    root->left = etapa1(root->left, L, R);
    root->right = etapa1(root->right, L, R);
    return root;
}

int main() {
    int N = 0, x = 0;
    
    while (scanf("%d", &N) != EOF) {
        Node *source = NULL;
        bool verif = true;
        int L = 0, R = 0;

        for (int i = 0; i < N; i++) {
            cin >> x;
            source = insert(source, x);
        }
    //Etapa 1
        source = etapa(source, &L);

    //Etapa 2
        source = etapa1(source, &L, &R);

        cout << L << " " << R << endl;
        posOrder(source);

        if (height(source) > 1 || height(source) < -1) {
            verif = false;
        }
        if (verif) {
            cout << endl << "true" << endl;
        } else {
            cout << endl << "false" << endl;
        }
    }
    return 0;
}