#include <stdio.h>   // Biblioteca para entrada/saída (printf)
#include <stdlib.h>  // Biblioteca padrão (não usada diretamente aqui, mas boa prática)

/* BFS simples em grafo pequeno representado por matriz de adjacência */

int main() {
    int n = 4;  // Número de vértices do grafo

    // Matriz de adjacência do grafo
    // adj[i][j] = 1 se existe aresta entre i e j, 0 caso contrário
    int adj[4][4] = {
        {0,1,1,0},  // Vértice 0 ligado a 1 e 2
        {1,0,1,0},  // Vértice 1 ligado a 0 e 2
        {1,1,0,1},  // Vértice 2 ligado a 0, 1 e 3
        {0,0,1,0}   // Vértice 3 ligado a 2
    };

    int q[10], head=0, tail=0; // Fila para BFS: head = índice do primeiro, tail = próximo livre
    int vis[4] = {0};          // Vetor de visitados: 0 = não visitado, 1 = visitado

    q[tail++] = 0;  // Enfileira vértice inicial (0)
    vis[0] = 1;     // Marca vértice 0 como visitado

    while (head < tail) {          // Enquanto a fila não estiver vazia
        int u = q[head++];         // Desenfileira o próximo vértice
        printf("%d ", u);          // Processa vértice (imprime)

        // Percorre todos os vizinhos do vértice u
        for (int v=0; v<n; v++) 
            if (adj[u][v] && !vis[v]) {  // Se existe aresta e não foi visitado
                vis[v] = 1;              // Marca como visitado
                q[tail++] = v;           // Enfileira o vértice
            }
    }

    printf("\n");  // Quebra de linha ao final da BFS
    return 0;      // Programa terminou com sucesso
}
