#include <stdio.h>
#include <stdlib.h>

/* Lista duplamente encadeada - simples: cria 3 nós e percorre para frente e para trás. */

typedef struct DNode {
    int val;
    struct DNode *prev, *next;
} DNode;

int main() {
    DNode *a = malloc(sizeof(DNode));
    DNode *b = malloc(sizeof(DNode));
    DNode *c = malloc(sizeof(DNode));
    a->val=1; a->prev=NULL; a->next=b;
    b->val=2; b->prev=a; b->next=c;
    c->val=3; c->prev=b; c->next=NULL;

    DNode *cur = a;
    while (cur) { printf("%d ", cur->val); cur = cur->next; }
    printf("\n");
    // voltar
    cur = c;
    while (cur) { printf("%d ", cur->val); cur = cur->prev; }
    printf("\n");
    free(a); free(b); free(c);
    return 0;
}
