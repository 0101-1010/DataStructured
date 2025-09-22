#include <stdio.h>
#include <stdlib.h>

/*
Lista duplamente encadeada - versão completa com operações: inserir, remover, imprimir.
*/

typedef struct DNode {
    int val;
    struct DNode *prev, *next;
} DNode;

/* Cria um novo nó com valor v */
DNode* new_dnode(int v) {
    DNode *n = malloc(sizeof(DNode));
    if (!n) { perror("malloc"); exit(1); }
    n->val = v; n->prev = n->next = NULL; return n;
}

/* Inserir no início */
void push_back(DNode **head, int v) {
    DNode *n = new_dnode(v);
    if (!*head) { *head = n; return; }
    DNode *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = n; n->prev = cur;
}

/* Inserir no final */
void push_front(DNode **head, int v) {
    DNode *n = new_dnode(v);
    if (*head) { n->next = *head; (*head)->prev = n; }
    *head = n;
}

/* Remover primeiro nó com valor v */
void remove_node(DNode **head, DNode *node) {
    if (!node) return;
    if (node->prev) node->prev->next = node->next;
    else *head = node->next;
    if (node->next) node->next->prev = node->prev;
    free(node);
}

/* Imprimir lista para frente*/
void print_forward(DNode *head) {
    DNode *cur = head;
    while (cur) { printf("%d ", cur->val); cur = cur->next; }
    printf("\n");
}

/* Imprimir lista para trás*/
void print_backward(DNode *head) {
    DNode *cur = head;
    if (!cur) return;
    while (cur->next) cur = cur->next;
    while (cur) { printf("%d ", cur->val); cur = cur->prev; }
    printf("\n");
}

/* Liberar memória */
void free_all(DNode *head) {
    DNode *cur = head;
    while (cur) { DNode *t = cur->next; free(cur); cur = t; }
}

int main() {
    DNode *head = NULL;
    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);
    print_forward(head);
    print_backward(head);
    remove_node(&head, head->next); // remove '2'
    print_forward(head);
    free_all(head);
    return 0;
}
