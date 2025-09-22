#include <stdio.h>
#include <stdlib.h>

/*
Lista simplesmente encadeada - versão completa.
Funções: criar nó, inserir no início, inserir no final, buscar, remover, imprimir.
*/

typedef struct Node {
    int val;
    struct Node *next;
} Node;

/* Cria um novo nó com valor v */
Node* new_node(int v) {
    Node *n = malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(1); }
    n->val = v; n->next = NULL;
    return n;
}

/* Inserir no início */
void push_front(Node **head, int v) {
    Node *n = new_node(v);
    n->next = *head;
    *head = n;
}

/* Inserir no final */
void push_back(Node **head, int v) {
    Node *n = new_node(v);
    if (!*head) { *head = n; return; }
    Node *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

/* Buscar primeiro nó com valor v */
Node* find(Node *head, int v) {
    Node *cur = head;
    while (cur) {
        if (cur->val == v) return cur;
        cur = cur->next;
    }
    return NULL;
}

/* Remover primeiro nó com valor v */
void remove_value(Node **head, int v) {
    Node *cur = *head, *prev = NULL;
    while (cur) {
        if (cur->val == v) {
            if (prev) prev->next = cur->next;
            else *head = cur->next;
            free(cur);
            return;
        }
        prev = cur; cur = cur->next;
    }
}

/* Imprimir lista */
void print_list(Node *head) {
    Node *cur = head;
    while (cur) { printf("%d ", cur->val); cur = cur->next; }
    printf("\n");
}

/* Liberar memória */
void free_list(Node *head) {
    Node *cur = head;
    while (cur) {
        Node *t = cur->next;
        free(cur);
        cur = t;
    }
}

int main() {
    Node *head = NULL;
    push_back(&head, 10);
    push_back(&head, 20);
    push_front(&head, 5); // 5 10 20
    print_list(head);
    Node *f = find(head, 10);
    if (f) printf("Encontrado: %d\n", f->val);
    remove_value(&head, 10);
    print_list(head);
    free_list(head);
    return 0;
}
