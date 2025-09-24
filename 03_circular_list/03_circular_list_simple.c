#include <stdio.h>   // Biblioteca padrão de entrada/saída (printf)
#include <stdlib.h>  // Biblioteca para alocação dinâmica de memória (malloc, free)

/* Lista circular simples:
   - Cria 3 nós
   - Cada nó aponta para o próximo, e o último aponta para o primeiro (circular)
   - Percorre 6 passos (duas voltas completas na lista)
*/

// Definição do nó da lista
typedef struct Node {
    int val;             // Valor armazenado no nó
    struct Node *next;   // Ponteiro para o próximo nó
} Node;

int main() {
    // Aloca dinamicamente 3 nós
    Node *a = malloc(sizeof(Node));
    Node *b = malloc(sizeof(Node));
    Node *c = malloc(sizeof(Node));

    // Inicializa os valores dos nós
    a->val = 1; 
    b->val = 2; 
    c->val = 3;

    // Cria o encadeamento circular
    a->next = b;   // 'a' aponta para 'b'
    b->next = c;   // 'b' aponta para 'c'
    c->next = a;   // 'c' aponta para 'a', fechando o ciclo

    // Ponteiro auxiliar para percorrer a lista
    Node *cur = a;

    // Percorre 6 passos (duas voltas na lista de 3 nós)
    for (int i = 0; i < 6; i++) {
        printf("%d ", cur->val); // Imprime o valor do nó atual
        cur = cur->next;         // Avança para o próximo nó (circular)
    }
    printf("\n");                // Quebra de linha ao final

    // Libera a memória alocada para evitar vazamentos
    free(a); 
    free(b); 
    free(c);

    return 0;  // Indica que o programa terminou com sucesso
}
