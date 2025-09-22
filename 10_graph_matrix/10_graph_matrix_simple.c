#include <stdio.h>
/* Grafo simples com matriz de adjacência 3x3 */
int main() {
    int mat[3][3] = { {0,1,1}, {0,0,1}, {0,0,0} };
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) printf("%d ", mat[i][j]);
        printf("\n");
    }
    return 0;
}
