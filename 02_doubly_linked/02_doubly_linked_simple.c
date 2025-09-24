#include <stdio.h>   // Biblioteca padrão de entrada e saída (printf, etc.)
#include <stdlib.h>  // Biblioteca para alocação dinâmica de memória (malloc, free)

/* Lista duplamente encadeada - versão simples:
   - Cria 3 nós (1, 2 e 3)
   - Percorre a lista para frente (do primeiro ao último)
   - Depois percorre para trás (do último ao primeiro)
*/

// Definição do nó da lista duplamente encadeada
typedef struct DNode {
    int val;              // Valor armazenado no nó
    struct DNode *prev;   // Ponteiro para o nó anterior
    struct DNode *next;   // Ponteiro para o próximo nó
} DNode;

int main() {
    // Aloca dinamicamente 3 nós: a, b e c
    DNode *a = malloc(sizeof(DNode));
    DNode *b = malloc(sizeof(DNode));
    DNode *c = malloc(sizeof(DNode));

    // Preenche os campos do nó A
    a->val = 1;       // Nó 'a' guarda o valor 1
    a->prev = NULL;   // 'a' não tem anterior (é o primeiro da lista)
    a->next = b;      // 'a' aponta para 'b'

    // Preenche os campos do nó B
    b->val = 2;       // Nó 'b' guarda o valor 2
    b->prev = a;      // Nó anterior de 'b' é 'a'
    b->next = c;      // Nó seguinte de 'b' é 'c'

    // Preenche os campos do nó C
    c->val = 3;       // Nó 'c' guarda o valor 3
    c->prev = b;      // Nó anterior de 'c' é 'b'
    c->next = NULL;   // 'c' não tem próximo (é o último da lista)

    // Percorrer para frente (do início até o fim)
    DNode *cur = a;                   // Ponteiro começa no primeiro nó
    while (cur) {                     // Enquanto não chegar em NULL
        printf("%d ", cur->val);      // Imprime o valor do nó atual
        cur = cur->next;              // Avança para o próximo nó
    }
    printf("\n");                     // Quebra de linha ao final

    // Percorrer para trás (do fim até o início)
    cur = c;                          // Ponteiro começa no último nó
    while (cur) {                     // Enquanto não chegar em NULL
        printf("%d ", cur->val);      // Imprime o valor do nó atual
        cur = cur->prev;              // Volta para o nó anterior
    }
    printf("\n");                     // Quebra de linha ao final

    // Libera a memória alocada para evitar vazamentos
    free(a);
    free(b);
    free(c);

    return 0; // Indica que o programa terminou com sucesso
}
