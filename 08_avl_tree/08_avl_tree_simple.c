#include <stdio.h>
#include <stdlib.h>

/* Versão simples: constrói uma árvore balanceada manualmente e imprime in-order. */

typedef struct Node {
    int val;
    struct Node *l, *r;
} Node;

void inorder(Node *n) {
    if (!n) return;
    inorder(n->l); printf("%d ", n->val); inorder(n->r);
}

int main() {
    Node *root = malloc(sizeof(Node));
    Node *l = malloc(sizeof(Node));
    Node *r = malloc(sizeof(Node));
    root->val=2; root->l=l; root->r=r;
    l->val=1; l->l=l->r=NULL;
    r->val=3; r->l=r->r=NULL;
    inorder(root); printf("\n");
    free(root); free(l); free(r);
    return 0;
}
