#include <stdio.h>
#include <stdlib.h>

/* Grafo simples com lista de adjacência: 3 vértices e algumas arestas. */

typedef struct Edge {
    int to;
    struct Edge *next;
} Edge;

Edge* make_edge(int to, Edge *next) {
    Edge *e = malloc(sizeof(Edge));
    e->to = to; e->next = next; return e;
}

int main() {
    // grafo com 3 nós: 0,1,2
    Edge *adj[3] = {NULL,NULL,NULL};
    adj[0] = make_edge(1, adj[0]);
    adj[0] = make_edge(2, adj[0]);
    adj[1] = make_edge(2, adj[1]);
    // imprimir
    for (int i=0;i<3;i++) {
        printf("%d: ", i);
        for (Edge *e=adj[i]; e; e=e->next) printf("%d ", e->to);
        printf("\n");
    }
    return 0;
}
