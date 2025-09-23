#include <stdio.h>
#include <stdlib.h>

/*
BFS usando lista de adjacência dinâmica.
Retorna ordem de visita a partir de fuente s.
*/

typedef struct Edge { int to; struct Edge* next; } Edge;
/* Criar uma nova aresta */
Edge* new_edge(int to) { Edge *e = malloc(sizeof(Edge)); e->to=to; e->next=NULL; return e; }

/* Adicionar aresta */
void add_edge(Edge **adj, int u, int v) { Edge *e = new_edge(v); e->next = adj[u]; adj[u] = e; }

/* BFS – Busca em Largura */
void bfs(Edge **adj, int n, int s) {
    int *vis = calloc(n, sizeof(int));
    int *q = malloc(sizeof(int)*n);
    int head=0, tail=0;
    q[tail++] = s; vis[s]=1;
    while (head<tail) {
        int u = q[head++]; printf("%d ", u);
        for (Edge *e = adj[u]; e; e = e->next) {
            if (!vis[e->to]) { vis[e->to]=1; q[tail++]=e->to; }
        }
    }
    printf("\n");
    free(vis); free(q);
}

/* Liberar memória do grafo */
void free_graph(Edge **adj, int n) {
    for (int i=0;i<n;i++) { Edge *e = adj[i]; while (e){ Edge *t=e->next; free(e); e=t;} }
}

int main() {
    int n = 5;
    Edge **adj = calloc(n, sizeof(Edge*));
    add_edge(adj,0,1); add_edge(adj,0,2);
    add_edge(adj,1,3); add_edge(adj,2,4);
    bfs(adj, n, 0);
    free_graph(adj, n); free(adj);
    return 0;
}
