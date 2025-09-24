#include <stdio.h>   // Biblioteca padrão de entrada/saída (printf)
#include <stdlib.h>  // Biblioteca padrão (não usada aqui, incluída por hábito)

/* Fila simples circular usando array */

int main() {
    int q[5];        // Declara um array de tamanho 5 para armazenar a fila
    int head = 0;    // Índice do início da fila (primeiro elemento)
    int tail = 0;    // Índice da próxima posição livre para inserção
    int size = 0;    // Número de elementos atualmente na fila

    // ENQUEUE (inserir elementos na fila)
    q[tail] = 10;              // Coloca 10 na posição tail (0)
    tail = (tail + 1) % 5;     // Avança tail de forma circular (mod 5)
    size++;                     // Incrementa o tamanho da fila

    q[tail] = 20;              // Coloca 20 na posição tail (1)
    tail = (tail + 1) % 5;     // Avança tail de forma circular
    size++;                     // Incrementa o tamanho

    q[tail] = 30;              // Coloca 30 na posição tail (2)
    tail = (tail + 1) % 5;     // Avança tail de forma circular
    size++;                     // Incrementa o tamanho

    // DEQUEUE (remover elementos da fila e imprimir)
    while (size > 0) {           // Enquanto houver elementos
        printf("%d ", q[head]);  // Imprime o elemento na posição head
        head = (head + 1) % 5;   // Avança head de forma circular
        size--;                   // Decrementa o tamanho da fila
    }
    printf("\n");                 // Quebra de linha ao final

    return 0;                     // Programa terminou com sucesso
}
