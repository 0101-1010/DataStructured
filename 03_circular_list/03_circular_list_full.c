#include <stdio.h>   // Biblioteca padrão de entrada/saída (printf)
#include <stdlib.h>  // Biblioteca para alocação dinâmica de memória (malloc, free)

/*
Lista circular com operações básicas:
- Inserir após um nó
- Remover nó seguinte
- Imprimir n elementos
- Liberar memória
Observação: em lista circular, o último nó não aponta para NULL; cuidado ao liberar memória.
*/

// Definição do nó da lista circular
typedef struct Node {
    int val;            // Valor armazenado no nó
    struct Node *next;  // Ponteiro para o próximo nó
} Node;

/* Cria um novo nó com valor v */
Node* new_node(int v) {
    Node *n = malloc(sizeof(Node));  // Aloca memória para o novo nó
    if (!n) {                        // Se malloc falhar
        perror("malloc");            // Imprime mensagem de erro
        exit(1);                     // Encerra o programa
    }
    n->val = v;          // Define o valor do nó
    n->next = n;         // Inicialmente aponta para si mesmo (lista circular com 1 nó)
    return n;            // Retorna o ponteiro para o novo nó
}

/* Inserir novo nó depois de 'after' */
void insert_after(Node *after, int v) {
    Node *n = new_node(v);    // Cria o novo nó
    n->next = after->next;    // Novo nó aponta para o próximo do nó 'after'
    after->next = n;          // Nó 'after' passa a apontar para o novo nó
}

/* Remover o nó seguinte a 'after' (se existir) */
void remove_after(Node *after) {
    Node *del = after->next;          // Nó a ser removido
    if (del == after) {               // Se único nó na lista
        free(del);                    // Libera o nó
        return;                       // Sai da função
    }
    after->next = del->next;          // Nó 'after' pula o nó removido
    free(del);                        // Libera memória do nó removido
}

/* Imprime n elementos a partir do nó 'start' */
void print_n(Node *start, int n) {
    Node *cur = start;                 // Ponteiro auxiliar
    for (int i = 0; i < n; i++) {     // Percorre exatamente n passos
        printf("%d ", cur->val);       // Imprime valor do nó atual
        cur = cur->next;               // Avança para o próximo nó
    }
    printf("\n");                       // Quebra de linha no final
}

/* Liberar toda a lista circular a partir de um nó */
void free_circle(Node *start) {
    if (!start) return;                // Se lista vazia, sai
    Node *cur = start->next;           // Começa pelo segundo nó
    while (cur != start) {             // Enquanto não voltar ao início
        Node *t = cur->next;           // Guarda próximo nó
        free(cur);                     // Libera nó atual
        cur = t;                       // Avança para o próximo
    }
    free(start);                       // Libera o nó inicial
}

int main() {
    Node *r = new_node(1);             // Cria nó inicial com valor 1

    insert_after(r, 2);                // Insere nó com valor 2 após 'r'
    insert_after(r->next, 3);          // Insere nó com valor 3 após nó 2
    // Lista circular: 1 -> 2 -> 3 -> 1

    print_n(r, 6);                     // Imprime 6 elementos (duas voltas)

    remove_after(r);                    // Remove nó seguinte a 'r' (remove 2)
    print_n(r, 4);                      // Imprime 4 elementos (uma volta e meia)

    free_circle(r);                     // Libera toda a memória da lista
    return 0;                           // Programa terminou com sucesso
}
