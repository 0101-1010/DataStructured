#include <stdio.h>
#include <stdlib.h>

/*
Lista circular com operações básicas: inserir após um nó, remover next e mostrar.
Em lista circular não existe NULL no 'next' do último nó; precisamos de cuidado ao liberar.
*/

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node* new_node(int v) {
    Node *n = malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(1); }
    n->val = v; n->next = n; // aponta para si mesmo inicialmente
    return n;
}

/* Inserir novo nó depois de 'after' */
void insert_after(Node *after, int v) {
    Node *n = new_node(v);
    n->next = after->next;
    after->next = n;
}

/* Remover o nó seguinte a 'after' (se existir) */
void remove_after(Node *after) {
    Node *del = after->next;
    if (del == after) { free(del); return; } // único nó
    after->next = del->next;
    free(del);
}

/* Imprime n elementos a partir de start */
void print_n(Node *start, int n) {
    Node *cur = start;
    for (int i=0;i<n;i++) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

/* Liberar lista circular a partir de um nó */
void free_circle(Node *start) {
    if (!start) return;
    Node *cur = start->next;
    while (cur != start) {
        Node *t = cur->next;
        free(cur);
        cur = t;
    }
    free(start);
}

int main() {
    Node *r = new_node(1);
    insert_after(r, 2);
    insert_after(r->next, 3); // cir: 1 -> 2 -> 3 -> 1
    print_n(r, 6);
    remove_after(r); // remove 2
    print_n(r, 4);
    free_circle(r);
    return 0;
}
