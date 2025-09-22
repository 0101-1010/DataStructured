#include <stdio.h>
#include <stdlib.h>

/* Árvore binária simples: criar 3 nós e imprimir em-ordem (esq, raiz, dir) */

typedef struct Node {
    int val;
    struct Node *l, *r;
} Node;

void inorder(Node *n) {
    if (!n) return;
    inorder(n->l);
    printf("%d ", n->val);
    inorder(n->r);
}

int main() {
    Node *root = malloc(sizeof(Node));
    Node *left = malloc(sizeof(Node));
    Node *right = malloc(sizeof(Node));
    root->val=2; root->l=left; root->r=right;
    left->val=1; left->l=left->r=NULL;
    right->val=3; right->l=right->r=NULL;
    inorder(root);
    printf("\n");
    free(root); free(left); free(right);
    return 0;
}
