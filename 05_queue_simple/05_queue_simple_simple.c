#include <stdio.h>
#include <stdlib.h>

/* Fila simples circular usando array */

int main() {
    int q[5];
    int head = 0, tail = 0, size = 0;
    // enqueue
    q[tail] = 10; tail = (tail+1)%5; size++;
    q[tail] = 20; tail = (tail+1)%5; size++;
    q[tail] = 30; tail = (tail+1)%5; size++;
    // dequeue
    while (size>0) {
        printf("%d ", q[head]);
        head = (head+1)%5;
        size--;
    }
    printf("\n");
    return 0;
}
