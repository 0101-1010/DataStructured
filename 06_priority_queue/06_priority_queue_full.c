#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
Fila de prioridade implementada como heap mínimo.
Operações: push, pop_min.
Comentários em português explicando sift-up / sift-down.
*/

typedef struct {
    int *vals;
    int *prio;
    int capacity;
    int size;
} PQueue;

PQueue* create(int cap) {
    PQueue *q = malloc(sizeof(PQueue));
    q->vals = malloc(sizeof(int)*cap);
    q->prio = malloc(sizeof(int)*cap);
    q->capacity = cap; q->size = 0;
    return q;
}

void swap(PQueue *q, int i, int j) {
    int tv = q->vals[i]; q->vals[i]=q->vals[j]; q->vals[j]=tv;
    int tp = q->prio[i]; q->prio[i]=q->prio[j]; q->prio[j]=tp;
}

void push(PQueue *q, int v, int p) {
    if (q->size == q->capacity) return;
    int i = q->size++;
    q->vals[i] = v; q->prio[i] = p;
    // sift-up
    while (i>0) {
        int parent = (i-1)/2;
        if (q->prio[parent] <= q->prio[i]) break;
        swap(q, parent, i);
        i = parent;
    }
}

int pop_min(PQueue *q) {
    if (q->size==0) return INT_MIN;
    int res = q->vals[0];
    q->size--;
    q->vals[0] = q->vals[q->size];
    q->prio[0] = q->prio[q->size];
    // sift-down
    int i=0;
    while (1) {
        int l=2*i+1, r=2*i+2, smallest=i;
        if (l<q->size && q->prio[l]<q->prio[smallest]) smallest=l;
        if (r<q->size && q->prio[r]<q->prio[smallest]) smallest=r;
        if (smallest==i) break;
        swap(q, i, smallest);
        i = smallest;
    }
    return res;
}

int main() {
    PQueue *q = create(10);
    push(q, 5, 2);
    push(q, 7, 1);
    push(q, 3, 4);
    printf("%d\n", pop_min(q));
    printf("%d\n", pop_min(q));
    printf("%d\n", pop_min(q));
    return 0;
}
