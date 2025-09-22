#include <stdio.h>
#include <stdlib.h>

/* Pilha simples usando array estático */

int main() {
    int stack[10];
    int top = -1;
    // push
    stack[++top] = 5;
    stack[++top] = 10;
    stack[++top] = 3;
    // pop e imprimir
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
    return 0;
}
