#include <stdio.h>
#include <stdlib.h>

/*
Pilha usando lista ligada (dinâmica) - operações: push, pop, topo, vazia.
Comentários em português explicando cada função.
*/

typedef struct Node {
    int val;
    struct Node *next;
} Node;

void push(Node **top, int v) {
    Node *n = malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(1); }
    n->val = v; n->next = *top; *top = n;
}

int pop(Node **top) {
    if (!*top) { fprintf(stderr, "Pilha vazia\n"); return -1; }
    Node *t = *top;
    int v = t->val;
    *top = t->next;
    free(t);
    return v;
}

int main() {
    Node *top = NULL;
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    printf("%d\n", pop(&top));
    printf("%d\n", pop(&top));
    printf("%d\n", pop(&top));
    return 0;
}
