#include <stdio.h>
#include <stdlib.h>

/*
Grafo com matriz de adjacência dinâmica.
Funções: criar, adicionar aresta, imprimir e liberar.
*/

typedef struct {
    int n;
    int **mat;
} Graph;

Graph* create_graph(int n) {
    Graph *g = malloc(sizeof(Graph));
    g->n = n;
    g->mat = malloc(sizeof(int*)*n);
    for (int i=0;i<n;i++) {
        g->mat[i] = calloc(n, sizeof(int));
    }
    return g;
}

void add_edge(Graph *g, int u, int v) {
    if (u<0||v<0||u>=g->n||v>=g->n) return;
    g->mat[u][v] = 1;
}

void print_graph(Graph *g) {
    for (int i=0;i<g->n;i++) {
        for (int j=0;j<g->n;j++) printf("%d ", g->mat[i][j]);
        printf("\n");
    }
}

void free_graph(Graph *g) {
    for (int i=0;i<g->n;i++) free(g->mat[i]);
    free(g->mat); free(g);
}

int main() {
    Graph *g = create_graph(4);
    add_edge(g,0,1); add_edge(g,0,2); add_edge(g,1,2); add_edge(g,2,3);
    print_graph(g);
    free_graph(g);
    return 0;
}
