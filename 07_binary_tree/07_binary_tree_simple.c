#include <stdio.h>   // Biblioteca padrão de entrada/saída (printf)
#include <stdlib.h>  // Biblioteca para alocação dinâmica (malloc, free)

/* Árvore binária simples:
   - Criar 3 nós
   - Imprimir em-ordem (inorder: esquerda, raiz, direita)
*/

// Estrutura de um nó da árvore binária
typedef struct Node {
    int val;            // Valor armazenado no nó
    struct Node *l;     // Ponteiro para filho esquerdo
    struct Node *r;     // Ponteiro para filho direito
} Node;

// Função para percorrer e imprimir a árvore em-ordem
void inorder(Node *n) {
    if (!n) return;         // Se nó NULL, retorna (fim de ramo)
    inorder(n->l);          // Percorre subárvore esquerda
    printf("%d ", n->val);  // Imprime valor do nó atual (raiz)
    inorder(n->r);          // Percorre subárvore direita
}

int main() {
    Node *root = malloc(sizeof(Node));   // Cria nó raiz
    Node *left = malloc(sizeof(Node));   // Cria nó filho esquerdo
    Node *right = malloc(sizeof(Node));  // Cria nó filho direito

    root->val = 2; root->l = left; root->r = right;  // Define valor e filhos da raiz
    left->val = 1; left->l = left->r = NULL;        // Nó esquerdo sem filhos
    right->val = 3; right->l = right->r = NULL;    // Nó direito sem filhos

    inorder(root);  // Imprime a árvore em-ordem: saída será 1 2 3
    printf("\n");   // Quebra de linha

    // Libera memória
    free(root);
    free(left);
    free(right);

    return 0;       // Programa terminou com sucesso
}
