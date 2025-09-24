#include <stdio.h>   // Biblioteca padrão de entrada/saída (printf, fprintf)
#include <stdlib.h>  // Biblioteca para alocação dinâmica de memória (malloc, free, exit)

/*
Fila encadeada (dinâmica):
- Operações implementadas: enqueue (inserir), dequeue (remover), front (implementar facilmente)
- A fila armazena inteiros
- Implementada com ponteiros para head (início) e tail (fim)
*/

// Definição do nó da fila
typedef struct Node {
    int val;            // Valor armazenado no nó
    struct Node *next;  // Ponteiro para o próximo nó
} Node;

// Definição da estrutura da fila
typedef struct Queue {
    Node *head;         // Ponteiro para o primeiro elemento da fila
    Node *tail;         // Ponteiro para o último elemento da fila
} Queue;

// Inicializa a fila (vazia)
void init(Queue *q) {
    q->head = q->tail = NULL;  // Head e tail começam apontando para NULL
}

// ENQUEUE: adiciona um elemento no final da fila
void enqueue(Queue *q, int v) {
    Node *n = malloc(sizeof(Node));    // Aloca memória para um novo nó
    if (!n) {                          // Se malloc falhar
        perror("malloc");              // Imprime mensagem de erro
        exit(1);                       // Encerra o programa
    }
    n->val = v;    // Define o valor do nó
    n->next = NULL; // Próximo será NULL (último da fila)
    if (!q->tail)   // Se a fila estava vazia
        q->head = q->tail = n;  // Head e tail apontam para o novo nó
    else {                     // Caso contrário
        q->tail->next = n;     // Último nó atual aponta para o novo nó
        q->tail = n;           // Atualiza tail para o novo nó
    }
}

// DEQUEUE: remove elemento do início da fila
int dequeue(Queue *q) {
    if (!q->head) {                     // Se a fila estiver vazia
        fprintf(stderr, "Fila vazia\n"); // Imprime erro
        return -1;                      // Retorna valor inválido
    }
    Node *t = q->head;       // Guarda nó do início
    int v = t->val;          // Salva valor a ser retornado
    q->head = t->next;       // Atualiza head para o próximo nó
    if (!q->head) q->tail = NULL; // Se a fila ficou vazia, tail também NULL
    free(t);                 // Libera memória do nó removido
    return v;                // Retorna valor removido
}

int main() {
    Queue q; init(&q);        // Declara fila e inicializa vazia

    enqueue(&q, 7);           // Adiciona 7
    enqueue(&q, 8);           // Adiciona 8
    enqueue(&q, 9);           // Adiciona 9

    printf("%d\n", dequeue(&q));  // Remove e imprime 7
    printf("%d\n", dequeue(&q));  // Remove e imprime 8
    printf("%d\n", dequeue(&q));  // Remove e imprime 9

    return 0;                     // Programa terminou com sucesso
}
