#include <stdio.h>   // Biblioteca padrão de entrada/saída (printf)
#include <stdlib.h>  // Biblioteca para alocação dinâmica (malloc, free)

/*
Árvore binária de busca (BST) - versão completa:
- Inserir elementos
- Buscar elementos
- Travessias pré-ordem, in-ordem, pós-ordem (aqui usamos in-ordem)
*/

// Estrutura de um nó da árvore
typedef struct Node {
    int val;            // Valor armazenado no nó
    struct Node *l;     // Ponteiro para filho esquerdo
    struct Node *r;     // Ponteiro para filho direito
} Node;

/* Criação de um novo nó com valor v */
Node* new_node(int v) {
    Node *n = malloc(sizeof(Node));        // Aloca memória para o nó
    if (!n) { perror("malloc"); exit(1); } // Se falhar, imprime erro e encerra
    n->val = v; n->l = n->r = NULL;       // Inicializa valor e filhos como NULL
    return n;                              // Retorna ponteiro para o nó
}

/* Inserção de valor na BST */
Node* insert(Node *root, int v) {
    if (!root) return new_node(v);         // Se árvore vazia, cria novo nó
    if (v < root->val)                     // Se valor menor, vai para subárvore esquerda
        root->l = insert(root->l, v);
    else                                   // Caso contrário, subárvore direita
        root->r = insert(root->r, v);
    return root;                           // Retorna raiz (atualizada)
}

/* Buscar um valor na BST */
Node* find(Node *root, int v) {
    if (!root) return NULL;                // Se nó NULL, não encontrado
    if (root->val == v) return root;       // Encontrou
    if (v < root->val) return find(root->l, v); // Busca na esquerda
    return find(root->r, v);              // Busca na direita
}

/* Travessia in-ordem: esquerda → raiz → direita */
void inorder(Node *n) {
    if (!n) return;
    inorder(n->l);               // Visita subárvore esquerda
    printf("%d ", n->val);       // Imprime valor da raiz
    inorder(n->r);               // Visita subárvore direita
}

/* Liberar memória da árvore */
void free_tree(Node *n) {
    if (!n) return;             // Se nó NULL, retorna
    free_tree(n->l);            // Libera subárvore esquerda
    free_tree(n->r);            // Libera subárvore direita
    free(n);                    // Libera nó atual
}

int main() {
    Node *root = NULL;                     // Inicializa árvore vazia
    int arr[] = {5,3,7,2,4,6,8};           // Valores a inserir
    for (int i=0; i<7; i++)                // Insere todos os valores na BST
        root = insert(root, arr[i]);

    inorder(root); printf("\n");           // Imprime árvore em ordem crescente

    Node *f = find(root, 4);               // Busca valor 4
    if (f) printf("Encontrado: %d\n", f->val); // Se encontrado, imprime

    free_tree(root);                        // Libera memória da árvore
    return 0;                               // Programa terminou com sucesso
}
