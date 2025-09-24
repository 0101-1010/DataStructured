#include <stdio.h>   // Biblioteca padrão de entrada/saída (printf, etc.)
#include <stdlib.h>  // Biblioteca para alocação de memória dinâmica (malloc, free, exit)

/*
Lista simplesmente encadeada - versão completa.
Funções implementadas:
- criar nó
- inserir no início
- inserir no final
- buscar elemento
- remover elemento
- imprimir lista
- liberar memória
*/

// Definição do nó da lista
typedef struct Node {
    int val;           // Valor armazenado no nó
    struct Node *next; // Ponteiro para o próximo nó
} Node;

/* Cria um novo nó com valor v */
Node* new_node(int v) {
    Node *n = malloc(sizeof(Node));   // Aloca memória para um nó
    if (!n) {                         // Se malloc falhar (sem memória)
        perror("malloc");             // Imprime erro
        exit(1);                      // Encerra o programa
    }
    n->val = v;       // Define o valor do nó
    n->next = NULL;   // Inicialmente não aponta para ninguém
    return n;         // Retorna o ponteiro para o nó criado
}

/* Inserir no início da lista */
void push_front(Node **head, int v) {
    Node *n = new_node(v); // Cria um novo nó
    n->next = *head;       // Aponta o novo nó para o antigo primeiro nó
    *head = n;             // Atualiza o ponteiro head para o novo nó
}

/* Inserir no final da lista */
void push_back(Node **head, int v) {
    Node *n = new_node(v); // Cria um novo nó
    if (!*head) {          // Se a lista estiver vazia
        *head = n;         // Novo nó vira o primeiro
        return;
    }
    Node *cur = *head;     // Ponteiro auxiliar começa no início
    while (cur->next)      // Avança até o último nó (que aponta para NULL)
        cur = cur->next;
    cur->next = n;         // Liga o último nó ao novo nó
}

/* Buscar o primeiro nó com valor v */
Node* find(Node *head, int v) {
    Node *cur = head;           // Começa no primeiro nó
    while (cur) {               // Percorre até chegar em NULL
        if (cur->val == v)      // Se achou o valor
            return cur;         // Retorna o ponteiro para o nó encontrado
        cur = cur->next;        // Avança para o próximo
    }
    return NULL;                // Se não achou, retorna NULL
}

/* Remover o primeiro nó com valor v */
void remove_value(Node **head, int v) {
    Node *cur = *head, *prev = NULL; // Ponteiros: atual e anterior
    while (cur) {                    // Percorre a lista
        if (cur->val == v) {         // Se achou o valor
            if (prev)                // Se não é o primeiro nó
                prev->next = cur->next; // Liga anterior ao próximo
            else
                *head = cur->next;   // Se era o primeiro, atualiza head
            free(cur);               // Libera o nó removido
            return;                  // Sai da função (remove apenas o 1º encontrado)
        }
        prev = cur;                  // Atualiza "anterior"
        cur = cur->next;             // Avança
    }
}

/* Imprimir todos os valores da lista */
void print_list(Node *head) {
    Node *cur = head;           // Começa no início
    while (cur) {               // Enquanto não chegar em NULL
        printf("%d ", cur->val);// Imprime valor do nó
        cur = cur->next;        // Avança para o próximo
    }
    printf("\n");               // Quebra de linha ao final
}

/* Liberar toda a memória da lista */
void free_list(Node *head) {
    Node *cur = head;           // Começa no início
    while (cur) {               // Enquanto houver nós
        Node *t = cur->next;    // Guarda referência para o próximo
        free(cur);              // Libera o nó atual
        cur = t;                // Avança
    }
}

int main() {
    Node *head = NULL;            // Começa com lista vazia

    push_back(&head, 10);         // Lista: 10
    push_back(&head, 20);         // Lista: 10 -> 20
    push_front(&head, 5);         // Lista: 5 -> 10 -> 20

    print_list(head);             // Imprime: 5 10 20

    Node *f = find(head, 10);     // Busca pelo valor 10
    if (f)                        // Se encontrado
        printf("Encontrado: %d\n", f->val); // Imprime valor encontrado

    remove_value(&head, 10);      // Remove o nó com valor 10 (primeira ocorrência)

    print_list(head);             // Imprime: 5 20

    free_list(head);              // Libera toda a memória da lista

    return 0; // Programa terminou com sucesso
}
