#include <stdio.h>
#include <stdlib.h>

/*
Fila encadeada (dinâmica): operações enqueue, dequeue, front.
A fila armazenará inteiros; implementada com ponteiros para head/tail.
*/

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head, *tail;
} Queue;

void init(Queue *q) { q->head = q->tail = NULL; }

void enqueue(Queue *q, int v) {
    Node *n = malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(1); }
    n->val = v; n->next = NULL;
    if (!q->tail) q->head = q->tail = n;
    else { q->tail->next = n; q->tail = n; }
}

int dequeue(Queue *q) {
    if (!q->head) { fprintf(stderr, "Fila vazia\n"); return -1; }
    Node *t = q->head;
    int v = t->val;
    q->head = t->next;
    if (!q->head) q->tail = NULL;
    free(t);
    return v;
}

int main() {
    Queue q; init(&q);
    enqueue(&q, 7); enqueue(&q, 8); enqueue(&q, 9);
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    return 0;
}
