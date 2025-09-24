#include <stdio.h>   // Biblioteca padrão de entrada/saída (printf)
#include <stdlib.h>  // Biblioteca para alocação dinâmica (malloc, free)

/* 
Versão simples de árvore balanceada:
- Constrói manualmente uma árvore balanceada com 3 nós
- Imprime os valores em ordem (in-order: esquerda → raiz → direita)
*/

// Estrutura do nó da árvore
typedef struct Node {
    int val;            // Valor armazenado no nó
    struct Node *l;     // Ponteiro para filho esquerdo
    struct Node *r;     // Ponteiro para filho direito
} Node;

// Função para percorrer a árvore em ordem
void inorder(Node *n) {
    if (!n) return;                 // Se nó NULL, retorna
    inorder(n->l);                  // Percorre subárvore esquerda
    printf("%d ", n->val);          // Imprime valor do nó atual
    inorder(n->r);                  // Percorre subárvore direita
}

int main() {
    Node *root = malloc(sizeof(Node));  // Cria nó raiz
    Node *l = malloc(sizeof(Node));     // Cria nó filho esquerdo
    Node *r = malloc(sizeof(Node));     // Cria nó filho direito

    root->val = 2; root->l = l; root->r = r;  // Define raiz com filhos
    l->val = 1; l->l = l->r = NULL;           // Nó esquerdo sem filhos
    r->val = 3; r->l = r->r = NULL;           // Nó direito sem filhos

    inorder(root); printf("\n");              // Imprime árvore em ordem: saída 1 2 3

    // Libera memória
    free(root); 
    free(l); 
    free(r);

    return 0;                                 // Programa terminou com sucesso
}
