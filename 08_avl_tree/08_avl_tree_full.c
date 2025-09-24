#include <stdio.h>   // Biblioteca padrão de entrada/saída (printf)
#include <stdlib.h>  // Biblioteca para alocação dinâmica (malloc, free)

/*
Árvore AVL (balanceada):
- Implementação com rotações (left/right)
- Inserção mantendo balanceamento
- Cálculo de altura e fator de balanceamento
*/

// Estrutura de nó da árvore AVL
typedef struct Node {
    int val;            // Valor armazenado no nó
    struct Node *l;     // Ponteiro para filho esquerdo
    struct Node *r;     // Ponteiro para filho direito
    int height;         // Altura do nó (necessária para balanceamento)
} Node;

/* Função que retorna altura de um nó */
int height(Node *n) { 
    return n ? n->height : 0; // Se nó NULL, altura = 0
}

/* Criação de um novo nó AVL */
Node* new_node(int v) {
    Node *n = malloc(sizeof(Node));        // Aloca memória
    if (!n) { perror("malloc"); exit(1); } // Verifica falha de alocação
    n->val = v; n->l = n->r = NULL;       // Inicializa filhos
    n->height = 1;                         // Novo nó tem altura 1
    return n;
}

/* Função auxiliar: retorna o maior entre dois inteiros */
int max(int a,int b){ return a>b?a:b; }

/* Rotação à direita para balanceamento */
Node* right_rotate(Node *y) {
    Node *x = y->l;           // x = filho esquerdo
    Node *T2 = x->r;          // T2 = subárvore direita de x
    x->r = y;                 // y torna-se filho direito de x
    y->l = T2;                // T2 vira filho esquerdo de y
    y->height = max(height(y->l), height(y->r)) + 1; // Atualiza altura de y
    x->height = max(height(x->l), height(x->r)) + 1; // Atualiza altura de x
    return x;                 // Novo topo da subárvore
}

/* Rotação à esquerda para balanceamento */
Node* left_rotate(Node *x) {
    Node *y = x->r;           // y = filho direito
    Node *T2 = y->l;          // T2 = subárvore esquerda de y
    y->l = x;                 // x torna-se filho esquerdo de y
    x->r = T2;                // T2 vira filho direito de x
    x->height = max(height(x->l), height(x->r)) + 1; // Atualiza altura de x
    y->height = max(height(y->l), height(y->r)) + 1; // Atualiza altura de y
    return y;                 // Novo topo da subárvore
}

/* Calcula fator de balanceamento de um nó */
int get_balance(Node *n) {
    if (!n) return 0;
    return height(n->l) - height(n->r); // altura esquerda - altura direita
}

/* Inserção de um valor em AVL */
Node* insert(Node *node, int key) {
    if (!node) return new_node(key);           // Caso base: cria nó
    if (key < node->val) node->l = insert(node->l, key); // Subárvore esquerda
    else if (key > node->val) node->r = insert(node->r, key); // Subárvore direita
    else return node;                          // Valores iguais não inseridos

    // Atualiza altura do nó
    node->height = 1 + max(height(node->l), height(node->r));

    int balance = get_balance(node);           // Calcula fator de balanceamento

    // Casos de desbalanceamento:

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

    return node; // Retorna nó raiz da subárvore
}

/* Travessia in-order: esquerda → raiz → direita */
void inorder(Node *n) { 
    if (!n) return; 
    inorder(n->l); 
    printf("%d ", n->val); 
    inorder(n->r); 
}

/* Libera memória da árvore */
void free_tree(Node *n) { 
    if (!n) return; 
    free_tree(n->l); 
    free_tree(n->r); 
    free(n); 
}

int main() {
    int vals[] = {10,20,30,40,50,25}; // Valores a inserir
    Node *root = NULL;
    for (int i=0;i<6;i++) root = insert(root, vals[i]); // Inserção AVL
    inorder(root); printf("\n");        // Imprime árvore em ordem crescente
    free_tree(root);                    // Libera memória
    return 0;                           // Programa terminou com sucesso
}
