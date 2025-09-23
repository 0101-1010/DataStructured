#include <stdio.h>
#include <stdlib.h>

/*
Árvore binária de busca (BST) - versão completa: inserir, buscar, travessias pré/in/pos-ordem.
*/

typedef struct Node {
    int val;
    struct Node *l, *r;
} Node;

/* Criação de novo node */
Node* new_node(int v) {
    Node *n = malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(1); }
    n->val = v; n->l = n->r = NULL; return n;
}

/* Inserção dos elementos nos nós */
Node* insert(Node *root, int v) {
    if (!root) return new_node(v);
    if (v < root->val) root->l = insert(root->l, v);
    else root->r = insert(root->r, v);
    return root;
}

/* Função que realiza varredura nos nós */
Node* find(Node *root, int v) {
    if (!root) return NULL;
    if (root->val == v) return root;
    if (v < root->val) return find(root->l, v);
    return find(root->r, v);
}

/* Travessia em ordem esquerda → raiz → direita (gera ordem crescente) */
void inorder(Node *n) {
    if (!n) return;
    inorder(n->l); printf("%d ", n->val); inorder(n->r);
}

/* Libera os nós da árvore */
void free_tree(Node *n) {
    if (!n) return;
    free_tree(n->l); free_tree(n->r); free(n);
}

int main() {
    Node *root = NULL;
    int arr[] = {5,3,7,2,4,6,8};
    for (int i=0;i<7;i++) root = insert(root, arr[i]);
    inorder(root); printf("\n");
    Node *f = find(root, 4);
    if (f) printf("Encontrado: %d\n", f->val);
    free_tree(root);
    return 0;
}
