#include <stdio.h>
#include <stdlib.h>

/* DFS recursivo simples em grafo representado por matriz 4x4 */

int adj[4][4] = {
    {0,1,1,0},
    {1,0,0,1},
    {1,0,0,1},
    {0,1,1,0}
};
int vis[4];

void dfs(int u) {
    vis[u]=1; printf("%d ", u);
    for (int v=0; v<4; v++) if (adj[u][v] && !vis[v]) dfs(v);
}

int main() {
    for (int i=0;i<4;i++) vis[i]=0;
    dfs(0);
    printf("\n");
    return 0;
}
