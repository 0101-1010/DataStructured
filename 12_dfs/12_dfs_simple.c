#include <stdio.h>   // Biblioteca para entrada/saída (printf)
#include <stdlib.h>  // Biblioteca padrão (não usada diretamente aqui)

/* DFS recursivo simples em grafo representado por matriz 4x4 */

// Matriz de adjacência do grafo
int adj[4][4] = {
    {0,1,1,0},  // Vértice 0 conectado a 1 e 2
    {1,0,0,1},  // Vértice 1 conectado a 0 e 3
    {1,0,0,1},  // Vértice 2 conectado a 0 e 3
    {0,1,1,0}   // Vértice 3 conectado a 1 e 2
};

int vis[4]; // Vetor de visitados: 0 = não visitado, 1 = visitado

/* Função DFS recursiva */
void dfs(int u) {
    vis[u] = 1;          // Marca o vértice atual como visitado
    printf("%d ", u);    // Processa vértice (imprime)

    // Percorre todos os vértices vizinhos
    for (int v = 0; v < 4; v++) 
        if (adj[u][v] && !vis[v])  // Se existe aresta e não visitado
            dfs(v);                // Chamada recursiva
}

int main() {
    for (int i = 0; i < 4; i++) vis[i] = 0; // Inicializa todos os vértices como não visitados
    dfs(0);        // Executa DFS a partir do vértice 0
    printf("\n");  // Quebra de linha após impressão
    return 0;      // Programa terminou com sucesso
}
