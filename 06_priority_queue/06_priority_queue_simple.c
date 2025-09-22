#include <stdio.h>
#include <stdlib.h>

/* Fila de prioridade simples: menor valor tem maior prioridade.
   Implementação: vetor de pares (val, prioridade) com remoção por busca linear. */

typedef struct Item {
    int val;
    int prio;
} Item;

int main() {
    Item a[10];
    int n = 0;
    // inserir (val, prio)
    a[n++] = (Item){5, 2};
    a[n++] = (Item){7, 1};
    a[n++] = (Item){3, 4};
    // remover o de menor prio (menor prio numérico -> mais prioridade)
    while (n>0) {
        int best = 0;
        for (int i=1;i<n;i++) if (a[i].prio < a[best].prio) best = i;
        printf("val=%d prio=%d\n", a[best].val, a[best].prio);
        // shift
        for (int i=best;i<n-1;i++) a[i]=a[i+1];
        n--;
    }
    return 0;
}
