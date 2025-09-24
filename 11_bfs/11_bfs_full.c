#include <stdio.h>   // Biblioteca para entrada/saída (printf)
#include <stdlib.h>  // Biblioteca para alocação dinâmica (malloc, calloc, free)

/*
BFS usando lista de adjacência dinâmica.
Retorna ordem de visita a partir do vértice fonte s.
*/

// Estrutura para representar uma aresta na lista encadeada
typedef struct Edge { 
    int to;            // Vértice destino da aresta
    struct Edge* next; // Próxima aresta na lista
} Edge;

/* Cria uma nova aresta apontando para 'to' */
Edge* new_edge(int to) { 
    Edge *e = malloc(sizeof(Edge)); // Aloca memória
    e->to = to;                     // Define vértice destino
    e->next = NULL;                 // Inicialmente sem próxima aresta
    return e;                       // Retorna ponteiro para a aresta
}

/* Adiciona uma aresta do vértice u para v na lista de adjacência */
void add_edge(Edge **adj, int u, int v) { 
    Edge *e = new_edge(v);   // Cria a aresta
    e->next = adj[u];        // Aponta para a primeira aresta atual do vértice u
    adj[u] = e;              // Atualiza cabeça da lista do vértice u
}

/* BFS – Busca em Largura */
void bfs(Edge **adj, int n, int s) {
    int *vis = calloc(n, sizeof(int));     // Vetor de visitados, inicializa com 0
    int *q = malloc(sizeof(int)*n);        // Fila para BFS
    int head = 0, tail = 0;                // Índices de início e fim da fila

    q[tail++] = s;   // Enfileira vértice fonte
    vis[s] = 1;      // Marca como visitado

    while (head < tail) {                   // Enquanto a fila não estiver vazia
        int u = q[head++];                  // Desenfileira o próximo vértice
        printf("%d ", u);                   // Processa vértice (imprime)

        for (Edge *e = adj[u]; e; e = e->next) { // Percorre todos os vizinhos
            if (!vis[e->to]) {                  // Se vizinho ainda não visitado
                vis[e->to] = 1;                 // Marca como visitado
                q[tail++] = e->to;              // Enfileira vizinho
            }
        }
    }
    printf("\n");           // Quebra de linha após imprimir todos vértices
    free(vis); free(q);     // Libera memória da fila e do vetor de visitados
}

/* Libera toda memória do grafo */
void free_graph(Edge **adj, int n) {
    for (int i=0; i<n; i++) {            // Para cada vértice
        Edge *e = adj[i];
        while (e) {                       // Percorre lista de adjacência
            Edge *t = e->next;            // Salva próximo
            free(e);                      // Libera aresta atual
            e = t;                        // Avança para próximo
        }
    }
}

int main() {
    int n = 5;                             // Número de vértices do grafo
    Edge **adj = calloc(n, sizeof(Edge*)); // Cria lista de adjacência

    // Adiciona algumas arestas
    add_edge(adj, 0, 1); 
    add_edge(adj, 0, 2);
    add_edge(adj, 1, 3); 
    add_edge(adj, 2, 4);

    bfs(adj, n, 0);                        // Executa BFS a partir do vértice 0

    free_graph(adj, n);                     // Libera memória do grafo
    free(adj);                              // Libera array de ponteiros
    return 0;                               // Programa terminou com sucesso
}
