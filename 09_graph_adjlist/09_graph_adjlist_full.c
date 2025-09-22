#include <stdio.h>
#include <stdlib.h>

/*
Grafo com lista de adjacência dinâmico.
Operações: adicionar aresta, imprimir, liberar.
*/

typedef struct Edge {
    int to;
    struct Edge *next;
} Edge;

Edge* new_edge(int to) {
    Edge *e = malloc(sizeof(Edge));
    if (!e) { perror("malloc"); exit(1); }
    e->to = to; e->next = NULL; return e;
}

void add_edge(Edge **adj, int u, int v) {
    Edge *e = new_edge(v);
    e->next = adj[u]; adj[u] = e;
}

void print_graph(Edge **adj, int n) {
    for (int i=0;i<n;i++) {
        printf("%d: ", i);
        for (Edge *e = adj[i]; e; e = e->next) printf("%d ", e->to);
        printf("\n");
    }
}

void free_graph(Edge **adj, int n) {
    for (int i=0;i<n;i++) {
        Edge *e = adj[i];
        while (e) { Edge *t = e->next; free(e); e = t; }
    }
}

int main() {
    int n = 4;
    Edge **adj = calloc(n, sizeof(Edge*));
    add_edge(adj, 0, 1); add_edge(adj, 0, 2);
    add_edge(adj, 1, 2); add_edge(adj, 2, 3);
    print_graph(adj, n);
    free_graph(adj, n); free(adj);
    return 0;
}
