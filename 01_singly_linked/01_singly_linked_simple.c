#include <stdio.h>   // Biblioteca padrão de entrada e saída (printf, etc.)
#include <stdlib.h>  // Biblioteca para alocação dinâmica de memória (malloc, free)

/* Lista simplesmente encadeada - versão simples para Python Tutor.
   Este exemplo cria 3 nós ligados entre si e imprime os valores da lista. */

// Definição da estrutura Node (nó da lista)
typedef struct Node {
    int val;             // Valor armazenado no nó
    struct Node *next;   // Ponteiro para o próximo nó da lista
} Node;

int main() {
    // Aloca dinamicamente memória para 3 nós (a, b e c)
    Node *a = malloc(sizeof(Node));
    Node *b = malloc(sizeof(Node));
    Node *c = malloc(sizeof(Node));

    // Preenche os valores e faz os encadeamentos
    a->val = 1;        // Nó 'a' guarda o valor 1
    a->next = b;       // O próximo de 'a' aponta para 'b'

    b->val = 2;        // Nó 'b' guarda o valor 2
    b->next = c;       // O próximo de 'b' aponta para 'c'

    c->val = 3;        // Nó 'c' guarda o valor 3
    c->next = NULL;    // O último nó aponta para NULL (fim da lista)

    // Impressão da lista
    Node *cur = a;     // Ponteiro auxiliar que começa no início da lista
    while (cur) {      // Enquanto não chegar ao fim (NULL)...
        printf("%d ", cur->val); // Imprime o valor do nó atual
        cur = cur->next;         // Avança para o próximo nó
    }
    printf("\n");      // Quebra de linha após imprimir todos os nós

    // Libera a memória alocada (boa prática para evitar vazamentos)
    free(a);
    free(b);
    free(c);

    return 0; // Indica que o programa terminou com sucesso
}
