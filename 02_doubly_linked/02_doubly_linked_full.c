#include <stdio.h>   // Biblioteca padrão de entrada/saída (printf)
#include <stdlib.h>  // Biblioteca para alocação dinâmica (malloc, free, exit)

/*
Lista duplamente encadeada - versão completa
Funções implementadas:
- criar nó
- inserir no início e no final
- remover nó
- imprimir para frente e para trás
- liberar memória
*/

// Definição do nó da lista duplamente encadeada
typedef struct DNode {
    int val;              // Valor armazenado no nó
    struct DNode *prev;   // Ponteiro para o nó anterior
    struct DNode *next;   // Ponteiro para o próximo nó
} DNode;

/* Cria um novo nó com valor v */
DNode* new_dnode(int v) {
    DNode *n = malloc(sizeof(DNode));   // Aloca memória para o nó
    if (!n) {                           // Verifica se a alocação falhou
        perror("malloc");               // Imprime mensagem de erro
        exit(1);                        // Encerra o programa
    }
    n->val = v;          // Define o valor do nó
    n->prev = n->next = NULL; // Inicializa ponteiros para NULL
    return n;            // Retorna o ponteiro para o novo nó
}

/* Inserir no final da lista */
void push_back(DNode **head, int v) {
    DNode *n = new_dnode(v);           // Cria um novo nó
    if (!*head) {                       // Se a lista estiver vazia
        *head = n;                      // Novo nó é o primeiro
        return;
    }
    DNode *cur = *head;                 // Ponteiro auxiliar começa no início
    while (cur->next)                   // Avança até o último nó
        cur = cur->next;
    cur->next = n;                       // Último nó aponta para o novo nó
    n->prev = cur;                       // Novo nó aponta para o anterior
}

/* Inserir no início da lista */
void push_front(DNode **head, int v) {
    DNode *n = new_dnode(v);           // Cria um novo nó
    if (*head) {                        // Se a lista não estiver vazia
        n->next = *head;                // Novo nó aponta para o antigo primeiro
        (*head)->prev = n;              // Antigo primeiro nó aponta para novo nó
    }
    *head = n;                          // Atualiza head para o novo nó
}

/* Remover um nó específico da lista */
void remove_node(DNode **head, DNode *node) {
    if (!node) return;                  // Se o nó for NULL, nada a fazer
    if (node->prev)                     // Se não for o primeiro nó
        node->prev->next = node->next;  // Anterior aponta para o próximo
    else
        *head = node->next;             // Se for o primeiro, atualiza head
    if (node->next)                     // Se não for o último nó
        node->next->prev = node->prev;  // Próximo aponta para o anterior
    free(node);                         // Libera a memória do nó removido
}

/* Imprimir lista do início ao fim */
void print_forward(DNode *head) {
    DNode *cur = head;                  // Começa no primeiro nó
    while (cur) {                        // Enquanto não chegar em NULL
        printf("%d ", cur->val);         // Imprime valor do nó
        cur = cur->next;                 // Avança para o próximo
    }
    printf("\n");                        // Quebra de linha no final
}

/* Imprimir lista do fim ao início */
void print_backward(DNode *head) {
    DNode *cur = head;                   // Começa no primeiro nó
    if (!cur) return;                    // Se lista vazia, sai
    while (cur->next)                    // Avança até o último nó
        cur = cur->next;
    while (cur) {                        // Enquanto não chegar em NULL
        printf("%d ", cur->val);         // Imprime valor do nó
        cur = cur->prev;                 // Volta para o nó anterior
    }
    printf("\n");                        // Quebra de linha no final
}

/* Liberar toda a memória da lista */
void free_all(DNode *head) {
    DNode *cur = head;                   // Começa no início
    while (cur) {                        // Enquanto houver nós
        DNode *t = cur->next;            // Guarda próximo nó
        free(cur);                        // Libera nó atual
        cur = t;                          // Avança para o próximo
    }
}

int main() {
    DNode *head = NULL;                   // Lista inicialmente vazia

    push_back(&head, 1);                  // Lista: 1
    push_back(&head, 2);                  // Lista: 1 -> 2
    push_back(&head, 3);                  // Lista: 1 -> 2 -> 3

    print_forward(head);                  // Imprime: 1 2 3
    print_backward(head);                 // Imprime: 3 2 1

    remove_node(&head, head->next);       // Remove o nó com valor 2
    print_forward(head);                  // Imprime: 1 3

    free_all(head);                       // Libera toda a memória da lista
    return 0;                             // Programa terminou com sucesso
}
