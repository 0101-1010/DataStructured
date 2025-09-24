#include <stdio.h>   // Biblioteca para entrada/saída (printf)
#include <stdlib.h>  // Biblioteca para alocação dinâmica de memória (malloc, calloc, free)

/*
DFS recursivo e iterativo (pilha) em grafo com lista de adjacência.
Mostra ordem de visita e explica recursão/retorno.
*/

// Estrutura de uma aresta para lista de adjacência
typedef struct Edge { 
    int to;             // Vértice de destino da aresta
    struct Edge* next;  // Próxima aresta da lista
} Edge;

/* Função para criar uma nova aresta */
Edge* new_edge(int to) { 
    Edge *e = malloc(sizeof(Edge)); // Aloca memória para a aresta
    e->to = to;                     // Define o vértice de destino
    e->next = NULL;                 // Inicializa o próximo como NULL
    return e;                       // Retorna a aresta criada
}

/* Adiciona aresta ao grafo (lista de adjacência) */
void add_edge(Edge **adj, int u, int v) { 
    Edge *e = new_edge(v);          // Cria nova aresta para v
    e->next = adj[u];               // Insere no início da lista de u
    adj[u] = e;                     // Atualiza o ponteiro da lista de u
}

/* DFS Recursivo */
void dfs_rec(Edge **adj, int u, int *vis) {
    vis[u] = 1;                     // Marca o vértice como visitado
    printf("%d ", u);               // Processa vértice (imprime)
    // Percorre todos os vizinhos
    for (Edge *e = adj[u]; e; e = e->next) 
        if (!vis[e->to])            // Se não visitado
            dfs_rec(adj, e->to, vis); // Chamada recursiva
}

/* DFS Iterativo usando pilha */
void dfs_iter(Edge **adj, int n, int s) {
    int *vis = calloc(n, sizeof(int));    // Vetor de visitados inicializado com 0
    int *stack = malloc(sizeof(int)*n);   // Pilha para DFS iterativo
    int top = -1;                          // Índice do topo da pilha
    stack[++top] = s;                      // Empilha vértice inicial

    while (top >= 0) {                     // Enquanto a pilha não estiver vazia
        int u = stack[top--];              // Desempilha o topo
        if (vis[u]) continue;              // Se já visitado, pula
        vis[u] = 1;                        // Marca como visitado
        printf("%d ", u);                  // Processa vértice (imprime)

        // Empilha vizinhos não visitados
        for (Edge *e = adj[u]; e; e = e->next) {
            if (!vis[e->to]) stack[++top] = e->to;
        }
    }

    free(vis); free(stack);                 // Libera memória
}

/* Liberação de memória do grafo */
void free_graph(Edge **adj, int n) {
    for (int i = 0; i < n; i++) {          // Para cada lista de adjacência
        Edge *e = adj[i];
        while (e) {                        // Percorre e libera cada aresta
            Edge *t = e->next;
            free(e);
            e = t;
        }
    }
}

int main() {
    int n = 4;                             // Número de vértices
    Edge **adj = calloc(n, sizeof(Edge*)); // Inicializa listas de adjacência

    // Adiciona arestas
    add_edge(adj,0,1); add_edge(adj,0,2);
    add_edge(adj,1,3); add_edge(adj,2,3);

    int *vis = calloc(n, sizeof(int));     // Vetor de visitados para DFS recursivo
    dfs_rec(adj, 0, vis);                  // Executa DFS recursivo a partir do vértice 0

    printf("\niterativo:\n");              // Separador
    dfs_iter(adj, n, 0);                   // Executa DFS iterativo a partir do vértice 0
    printf("\n");                           // Quebra de linha

    // Libera memória
    free(vis); 
    free_graph(adj, n); 
    free(adj);
    return 0;                               // Programa terminado com sucesso
}
