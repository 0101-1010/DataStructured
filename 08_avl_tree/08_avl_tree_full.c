#include <stdio.h>
#include <stdlib.h>

/*
Árvore AVL (balanceada) - implementação com rotações, inserção e cálculo de altura/balance.
Comentários em português explicando cada etapa.
*/

typedef struct Node {
    int val;
    struct Node *l, *r;
    int height;
} Node;

int height(Node *n) { return n ? n->height : 0; }

Node* new_node(int v) {
    Node *n = malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(1); }
    n->val = v; n->l = n->r = NULL; n->height = 1; return n;
}

int max(int a,int b){ return a>b?a:b; }

Node* right_rotate(Node *y) {
    Node *x = y->l;
    Node *T2 = x->r;
    x->r = y; y->l = T2;
    y->height = max(height(y->l), height(y->r)) + 1;
    x->height = max(height(x->l), height(x->r)) + 1;
    return x;
}

Node* left_rotate(Node *x) {
    Node *y = x->r;
    Node *T2 = y->l;
    y->l = x; x->r = T2;
    x->height = max(height(x->l), height(x->r)) + 1;
    y->height = max(height(y->l), height(y->r)) + 1;
    return y;
}

int get_balance(Node *n) {
    if (!n) return 0;
    return height(n->l) - height(n->r);
}

Node* insert(Node *node, int key) {
    if (!node) return new_node(key);
    if (key < node->val) node->l = insert(node->l, key);
    else if (key > node->val) node->r = insert(node->r, key);
    else return node;
    node->height = 1 + max(height(node->l), height(node->r));
    int balance = get_balance(node);
    // Left Left
    if (balance > 1 && key < node->l->val) return right_rotate(node);
    // Right Right
    if (balance < -1 && key > node->r->val) return left_rotate(node);
    // Left Right
    if (balance > 1 && key > node->l->val) {
        node->l = left_rotate(node->l);
        return right_rotate(node);
    }
    // Right Left
    if (balance < -1 && key < node->r->val) {
        node->r = right_rotate(node->r);
        return left_rotate(node);
    }
    return node;
}

void inorder(Node *n) { if (!n) return; inorder(n->l); printf("%d ", n->val); inorder(n->r); }

void free_tree(Node *n) { if (!n) return; free_tree(n->l); free_tree(n->r); free(n); }

int main() {
    int vals[] = {10,20,30,40,50,25};
    Node *root = NULL;
    for (int i=0;i<6;i++) root = insert(root, vals[i]);
    inorder(root); printf("\n");
    free_tree(root);
    return 0;
}
