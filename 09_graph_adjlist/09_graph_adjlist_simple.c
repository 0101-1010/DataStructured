#include <stdio.h>   // Biblioteca para entrada/saída (printf)
#include <stdlib.h>  // Biblioteca para alocação dinâmica (malloc, free)

/* Grafo simples com lista de adjacência:
   - 3 vértices (0,1,2)
   - Algumas arestas direcionadas
*/

// Estrutura para representar aresta na lista de adjacência
typedef struct Edge {
    int to;              // Vértice de destino da aresta
    struct Edge *next;   // Próxima aresta da lista
} Edge;

// Função para criar uma nova aresta
Edge* make_edge(int to, Edge *next) {
    Edge *e = malloc(sizeof(Edge)); // Aloca memória para a aresta
    e->to = to;                     // Define destino da aresta
    e->next = next;                 // Aponta para próxima aresta (encadeamento)
    return e;                       // Retorna ponteiro da nova aresta
}

int main() {
    // Array de ponteiros para listas de adjacência de cada vértice
    Edge *adj[3] = {NULL, NULL, NULL}; 

    // Adiciona arestas
    adj[0] = make_edge(1, adj[0]);  // 0 → 1
    adj[0] = make_edge(2, adj[0]);  // 0 → 2
    adj[1] = make_edge(2, adj[1]);  // 1 → 2

    // Imprime grafo
    for (int i=0; i<3; i++) {       // Para cada vértice
        printf("%d: ", i);          // Imprime índice do vértice
        for (Edge *e = adj[i]; e; e = e->next) // Percorre lista de adjacência
            printf("%d ", e->to);   // Imprime vértice de destino
        printf("\n");               // Quebra de linha após cada vértice
    }

    return 0;                        // Programa terminou com sucesso
}
