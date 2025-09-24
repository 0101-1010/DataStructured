#include <stdio.h>   // Biblioteca padrão de entrada/saída (printf)
#include <stdlib.h>  // Biblioteca padrão, incluída por hábito (não é usada aqui)

/* Pilha simples usando array estático */

int main() {
    int stack[10];    // Declara um array de tamanho 10 que representa a pilha
    int top = -1;     // Índice do topo da pilha; -1 indica que a pilha está vazia

    // PUSH (inserir elementos na pilha)
    stack[++top] = 5;  // Incrementa top (0) e coloca 5 no topo
    stack[++top] = 10; // Incrementa top (1) e coloca 10 no topo
    stack[++top] = 3;  // Incrementa top (2) e coloca 3 no topo

    // POP (remover elementos da pilha e imprimir)
    while (top >= 0) {           // Enquanto houver elementos na pilha
        printf("%d ", stack[top--]); // Imprime o elemento do topo e decrementa top
    }
    printf("\n");                 // Quebra de linha ao final

    return 0;                      // Programa terminou com sucesso
}
