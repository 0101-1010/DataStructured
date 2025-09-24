#include <stdio.h>   // Biblioteca para entrada/saída (printf)

/* Grafo simples com matriz de adjacência 3x3 */

int main() {
    // Matriz de adjacência 3x3
    // mat[i][j] = 1 se existir aresta de i para j, 0 caso contrário
    int mat[3][3] = { {0,1,1},  // Vértice 0 tem arestas para 1 e 2
                       {0,0,1},  // Vértice 1 tem aresta para 2
                       {0,0,0}   // Vértice 2 não tem arestas
                     };

    // Percorre cada linha da matriz (vértice de origem)
    for (int i=0; i<3; i++) {
        // Percorre cada coluna da linha (vértice de destino)
        for (int j=0; j<3; j++) 
            printf("%d ", mat[i][j]);  // Imprime 0 ou 1 indicando existência de aresta
        printf("\n");                   // Quebra de linha após cada linha da matriz
    }

    return 0;  // Programa terminou com sucesso
}
