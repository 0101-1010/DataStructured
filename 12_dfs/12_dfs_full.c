#include <stdio.h>
#include <stdlib.h>

/*
DFS recursivo e iterativo (pilha) em grafo com lista de adjacência.
Mostra ordem de visita e explica recursão/retorno.
*/

typedef struct Edge { int to; struct Edge* next; } Edge;

/* Criar e adicionar arestas */
Edge* new_edge(int to) { Edge *e = malloc(sizeof(Edge)); e->to=to; e->next=NULL; return e; }
void add_edge(Edge **adj, int u, int v) { Edge *e = new_edge(v); e->next = adj[u]; adj[u] = e; }

/* DFS Recursivo */
void dfs_rec(Edge **adj, int u, int *vis) {
    vis[u]=1; printf("%d ", u);
    for (Edge *e = adj[u]; e; e = e->next) if (!vis[e->to]) dfs_rec(adj, e->to, vis);
}

/* DFS Iterativo (usando pilha) */
void dfs_iter(Edge **adj, int n, int s) {
    int *vis = calloc(n, sizeof(int));
    int *stack = malloc(sizeof(int)*n);
    int top = -1;
    stack[++top] = s;
    while (top >= 0) {
        int u = stack[top--];
        if (vis[u]) continue;
        vis[u]=1; printf("%d ", u);
        for (Edge *e = adj[u]; e; e = e->next) {
            if (!vis[e->to]) stack[++top] = e->to;
        }
    }
    free(vis); free(stack);
}

/* Liberação de memória */
void free_graph(Edge **adj, int n) {
    for (int i=0;i<n;i++) { Edge *e = adj[i]; while (e){ Edge *t=e->next; free(e); e=t;} }
}

int main() {
    int n = 4;
    Edge **adj = calloc(n, sizeof(Edge*));
    add_edge(adj,0,1); add_edge(adj,0,2);
    add_edge(adj,1,3); add_edge(adj,2,3);
    int *vis = calloc(n, sizeof(int));
    dfs_rec(adj, 0, vis);
    printf("\niterativo:\n");
    dfs_iter(adj, n, 0);
    printf("\n");
    free(vis); free_graph(adj, n); free(adj);
    return 0;
}
