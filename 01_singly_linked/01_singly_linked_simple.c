#include <stdio.h>
#include <stdlib.h>

/* Lista simplesmente encadeada - versão simples para Python Tutor.
   Cria 3 nós e imprime a lista. */
typedef struct Node {
    int val;
    struct Node *next;
} Node;

int main() {
    Node *a = malloc(sizeof(Node));
    Node *b = malloc(sizeof(Node));
    Node *c = malloc(sizeof(Node));
    a->val = 1; a->next = b;
    b->val = 2; b->next = c;
    c->val = 3; c->next = NULL;

    Node *cur = a;
    while (cur) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
    free(a); free(b); free(c);
    return 0;
}
