#include <stdio.h>
#include <stdlib.h>

/* Lista circular simples: cria 3 nós e percorre 6 passos (duas voltas). */

typedef struct Node {
    int val;
    struct Node *next;
} Node;

int main() {
    Node *a = malloc(sizeof(Node));
    Node *b = malloc(sizeof(Node));
    Node *c = malloc(sizeof(Node));
    a->val=1; b->val=2; c->val=3;
    a->next=b; b->next=c; c->next=a; // circular

    Node *cur = a;
    for (int i=0;i<6;i++) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
    free(a); free(b); free(c);
    return 0;
}
