#include <stdio.h>    // Biblioteca padrão de entrada/saída (printf)
#include <stdlib.h>   // Biblioteca para alocação dinâmica (malloc, free)
#include <limits.h>   // Para constante INT_MIN

/*
Fila de prioridade implementada como heap mínimo
- Operações principais: push (inserir), pop_min (remover elemento de menor prioridade)
- Heap mínimo: elemento com menor valor de prioridade está sempre no topo
*/

// Estrutura da fila de prioridade
typedef struct {
    int *vals;      // Array de valores
    int *prio;      // Array de prioridades correspondentes
    int capacity;   // Capacidade máxima
    int size;       // Número de elementos atualmente na fila
} PQueue;

/* Criação da fila prioritária */
PQueue* create(int cap) {
    PQueue *q = malloc(sizeof(PQueue));         // Aloca memória para a estrutura
    q->vals = malloc(sizeof(int) * cap);        // Aloca array de valores
    q->prio = malloc(sizeof(int) * cap);        // Aloca array de prioridades
    q->capacity = cap;                          // Define capacidade
    q->size = 0;                                // Inicialmente vazia
    return q;                                   // Retorna ponteiro para fila
}

/* Função de troca de elementos pela prioridade */
void swap(PQueue *q, int i, int j) {
    int tv = q->vals[i]; q->vals[i] = q->vals[j]; q->vals[j] = tv;  // Troca valores
    int tp = q->prio[i]; q->prio[i] = q->prio[j]; q->prio[j] = tp;  // Troca prioridades
}

/* Função de empilhar (inserir) */
void push(PQueue *q, int v, int p) {
    if (q->size == q->capacity) return;         // Se fila cheia, ignora
    int i = q->size++;                          // Índice do novo nó e incrementa tamanho
    q->vals[i] = v; q->prio[i] = p;            // Armazena valor e prioridade

    // Sift-up: garante propriedade de heap mínimo
    while (i > 0) {
        int parent = (i-1)/2;                   // Índice do nó pai
        if (q->prio[parent] <= q->prio[i]) break; // Se pai menor ou igual, heap OK
        swap(q, parent, i);                     // Caso contrário, troca com o pai
        i = parent;                              // Continua subindo
    }
}

/* Função de remover o elemento de menor prioridade */
int pop_min(PQueue *q) {
    if (q->size == 0) return INT_MIN;          // Se fila vazia, retorna valor inválido
    int res = q->vals[0];                      // Valor do topo (menor prioridade)
    q->size--;                                 // Reduz tamanho
    q->vals[0] = q->vals[q->size];             // Move último elemento para o topo
    q->prio[0] = q->prio[q->size];             // Move prioridade correspondente

    // Sift-down: reordena heap para manter propriedade de heap mínimo
    int i = 0;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, smallest = i; // Filhos esquerdo e direito
        if (l < q->size && q->prio[l] < q->prio[smallest]) smallest = l;
        if (r < q->size && q->prio[r] < q->prio[smallest]) smallest = r;
        if (smallest == i) break;               // Heap ok
        swap(q, i, smallest);                   // Troca com menor filho
        i = smallest;                            // Continua descendo
    }
    return res;                                  // Retorna valor removido
}

int main() {
    PQueue *q = create(10);      // Cria fila com capacidade 10
    push(q, 5, 2);               // Insere valor 5 com prioridade 2
    push(q, 7, 1);               // Insere valor 7 com prioridade 1 (mais prioridade)
    push(q, 3, 4);               // Insere valor 3 com prioridade 4 (menos prioridade)

    printf("%d\n", pop_min(q));  // Remove e imprime valor com menor prioridade (7)
    printf("%d\n", pop_min(q));  // Remove e imprime próximo (5)
    printf("%d\n", pop_min(q));  // Remove e imprime próximo (3)

    return 0;                     // Programa terminou com sucesso
}
