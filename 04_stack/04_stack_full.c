#include <stdio.h>   // Biblioteca padrão de entrada/saída (printf, fprintf)
#include <stdlib.h>  // Biblioteca para alocação dinâmica de memória (malloc, free, exit)

/*
Pilha usando lista ligada (dinâmica) - operações implementadas:
- push (empilhar)
- pop (desempilhar)
- topo (implícito)
- verificar se está vazia
*/

// Definição do nó da pilha
typedef struct Node {
    int val;            // Valor armazenado no nó
    struct Node *next;  // Ponteiro para o próximo nó (o próximo elemento na pilha)
} Node;

/* Operação PUSH (empilhar) */
void push(Node **top, int v) {
    Node *n = malloc(sizeof(Node));   // Aloca memória para um novo nó
    if (!n) {                         // Se malloc falhar
        perror("malloc");             // Imprime mensagem de erro
        exit(1);                      // Encerra o programa
    }
    n->val = v;       // Define o valor do novo nó
    n->next = *top;   // Novo nó aponta para o topo atual da pilha
    *top = n;         // Atualiza o topo para o novo nó
}

/* Operação POP (desempilhar) */
int pop(Node **top) {
    if (!*top) {                        // Se a pilha estiver vazia
        fprintf(stderr, "Pilha vazia\n"); // Imprime mensagem de erro
        return -1;                       // Retorna valor inválido
    }
    Node *t = *top;       // Guarda o nó do topo
    int v = t->val;       // Salva o valor a ser retornado
    *top = t->next;       // Atualiza o topo para o próximo nó
    free(t);              // Libera memória do nó removido
    return v;             // Retorna o valor do nó desempilhado
}

int main() {
    Node *top = NULL;       // Inicializa a pilha vazia (topo NULL)

    push(&top, 1);          // Empilha o valor 1
    push(&top, 2);          // Empilha o valor 2
    push(&top, 3);          // Empilha o valor 3

    printf("%d\n", pop(&top));  // Desempilha e imprime 3
    printf("%d\n", pop(&top));  // Desempilha e imprime 2
    printf("%d\n", pop(&top));  // Desempilha e imprime 1

    return 0;                  // Programa terminou com sucesso
}
