#include <stdio.h>   // Biblioteca para entrada/saída (printf)
#include <stdlib.h>  // Biblioteca para alocação dinâmica (malloc, calloc, free)

/*
Grafo com matriz de adjacência dinâmica:
- Permite criar grafos de tamanho variável
- Adicionar arestas
- Imprimir a matriz
- Liberar memória
*/

// Estrutura do grafo
typedef struct {
    int n;      // Número de vértices
    int **mat;  // Ponteiro para matriz de adjacência
} Graph;

/* Cria um grafo com n vértices */
Graph* create_graph(int n) {
    Graph *g = malloc(sizeof(Graph));          // Aloca memória para a estrutura do grafo
    g->n = n;                                  // Define o número de vértices
    g->mat = malloc(sizeof(int*) * n);         // Aloca array de ponteiros (linhas da matriz)
    for (int i=0; i<n; i++) {
        g->mat[i] = calloc(n, sizeof(int));   // Aloca cada linha da matriz e inicializa com 0
    }
    return g;                                  // Retorna ponteiro para o grafo
}

/* Adiciona uma aresta de u para v */
void add_edge(Graph *g, int u, int v) {
    if (u<0 || v<0 || u>=g->n || v>=g->n) return; // Verifica se índices são válidos
    g->mat[u][v] = 1;                              // Marca presença da aresta
}

/* Imprime a matriz de adjacência */
void print_graph(Graph *g) {
    for (int i=0; i<g->n; i++) {                   // Para cada linha (vértice de origem)
        for (int j=0; j<g->n; j++)                 // Para cada coluna (vértice de destino)
            printf("%d ", g->mat[i][j]);          // Imprime 0 ou 1
        printf("\n");                              // Quebra de linha após cada linha
    }
}

/* Libera toda memória alocada para o grafo */
void free_graph(Graph *g) {
    for (int i=0; i<g->n; i++) free(g->mat[i]);   // Libera cada linha da matriz
    free(g->mat);                                  // Libera array de ponteiros
    free(g);                                       // Libera estrutura do grafo
}

int main() {
    Graph *g = create_graph(4);                    // Cria grafo com 4 vértices

    // Adiciona algumas arestas
    add_edge(g, 0, 1); 
    add_edge(g, 0, 2);
    add_edge(g, 1, 2); 
    add_edge(g, 2, 3);

    print_graph(g);                                // Imprime grafo

    free_graph(g);                                 // Libera memória
    return 0;                                      // Programa terminou com sucesso
}
