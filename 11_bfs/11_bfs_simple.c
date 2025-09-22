#include <stdio.h>
#include <stdlib.h>

/* BFS simples em grafo pequeno representado por lista de adjacência (estático). */

int main() {
    int n = 4;
    int adj[4][4] = {
        {0,1,1,0},
        {1,0,1,0},
        {1,1,0,1},
        {0,0,1,0}
    };
    int q[10], head=0, tail=0;
    int vis[4] = {0};
    q[tail++]=0; vis[0]=1;
    while (head<tail) {
        int u = q[head++];
        printf("%d ", u);
        for (int v=0; v<n; v++) if (adj[u][v] && !vis[v]) {
            vis[v]=1; q[tail++]=v;
        }
    }
    printf("\n");
    return 0;
}
