#include <stdio.h>   // Biblioteca para entrada/saída (printf)
#include <stdlib.h>  // Biblioteca para alocação dinâmica (malloc, calloc, free)

/*
Grafo com lista de adjacência dinâmica:
- Permite adicionar arestas
- Imprimir o grafo
- Liberar memória alocada
*/

// Estrutura que representa uma aresta em lista encadeada
typedef struct Edge {
    int to;              // Vértice de destino
    struct Edge *next;   // Próximo nó na lista de adjacência
} Edge;

/* Cria uma nova aresta */
Edge* new_edge(int to) {
    Edge *e = malloc(sizeof(Edge));        // Aloca memória
    if (!e) { perror("malloc"); exit(1); } // Verifica falha de alocação
    e->to = to;                             // Define destino da aresta
    e->next = NULL;                         // Inicializa próximo como NULL
    return e;                               // Retorna ponteiro para aresta
}

/* Adiciona uma aresta do vértice u para v */
void add_edge(Edge **adj, int u, int v) {
    Edge *e = new_edge(v);   // Cria nova aresta
    e->next = adj[u];        // Encadeia na lista existente do vértice u
    adj[u] = e;              // Atualiza início da lista do vértice u
}

/* Imprime todas as listas de adjacência do grafo */
void print_graph(Edge **adj, int n) {
    for (int i=0;i<n;i++) {              // Para cada vértice
        printf("%d: ", i);               // Imprime índice do vértice
        for (Edge *e = adj[i]; e; e = e->next) // Percorre lista de adjacência
            printf("%d ", e->to);        // Imprime vértice de destino
        printf("\n");                     // Quebra de linha após cada vértice
    }
}

/* Libera toda memória alocada para o grafo */
void free_graph(Edge **adj, int n) {
    for (int i=0;i<n;i++) {             // Para cada lista de adjacência
        Edge *e = adj[i];
        while (e) {                      // Percorre lista
            Edge *t = e->next;           // Guarda próximo
            free(e);                     // Libera aresta atual
            e = t;                       // Vai para próximo
        }
    }
}

int main() {
    int n = 4;                           // Número de vértices
    Edge **adj = calloc(n, sizeof(Edge*)); // Array de ponteiros inicializados com NULL

    // Adiciona algumas arestas
    add_edge(adj, 0, 1); 
    add_edge(adj, 0, 2);
    add_edge(adj, 1, 2); 
    add_edge(adj, 2, 3);

    print_graph(adj, n);                 // Imprime grafo

    free_graph(adj, n);                  // Libera memória das listas
    free(adj);                           // Libera array de ponteiros

    return 0;                             // Programa terminou com sucesso
}
