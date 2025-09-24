#include <stdio.h>   // Biblioteca padrão de entrada/saída (printf)
#include <stdlib.h>  // Biblioteca padrão (não usada aqui, incluída por hábito)

/* 
Fila de prioridade simples:
- Menor valor de prio numérico tem maior prioridade
- Implementação: vetor de pares (val, prioridade)
- Remoção: busca linear para encontrar o elemento de maior prioridade
*/

// Estrutura de um item da fila de prioridade
typedef struct Item {
    int val;   // Valor do elemento
    int prio;  // Prioridade do elemento (quanto menor, maior a prioridade)
} Item;

int main() {
    Item a[10];    // Vetor que armazena até 10 itens
    int n = 0;     // Número de elementos atualmente na fila

    // Inserir elementos (val, prioridade)
    a[n++] = (Item){5, 2};  // Insere valor 5 com prioridade 2
    a[n++] = (Item){7, 1};  // Insere valor 7 com prioridade 1 (maior prioridade)
    a[n++] = (Item){3, 4};  // Insere valor 3 com prioridade 4 (menor prioridade)

    // Remover elementos na ordem de prioridade
    while (n > 0) {                     // Enquanto houver elementos na fila
        int best = 0;                    // Índice do item com maior prioridade
        for (int i = 1; i < n; i++)     // Percorre todos os itens
            if (a[i].prio < a[best].prio) // Menor valor de prio = maior prioridade
                best = i;                 // Atualiza índice do melhor
        printf("val=%d prio=%d\n", a[best].val, a[best].prio); // Mostra item removido

        // Remover item encontrado deslocando os demais elementos
        for (int i = best; i < n - 1; i++)
            a[i] = a[i + 1];             // Shift à esquerda
        n--;                             // Decrementa número de elementos
    }

    return 0;  // Programa terminou com sucesso
}
