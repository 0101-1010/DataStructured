# O que é uma Fila de Prioridade?

Diferente da fila simples (FIFO), aqui os elementos não são atendidos pela ordem de chegada.

Cada elemento tem uma prioridade (um valor).

Sempre o elemento de maior prioridade (ou menor, dependendo da regra) é removido primeiro.

📌 Exemplo real:

Um pronto-socorro: pacientes graves são atendidos antes, mesmo que tenham chegado depois.

# Implementação com Vetor Simples

Na versão básica, a fila é apenas um array, onde cada posição guarda um par:

[ valor | prioridade ]

🔸 Inserção (enqueue)

Basta adicionar no fim do vetor.

Complexidade: O(1).

Exemplo:

Fila: [(A, 2), (B, 1), (C, 3)]


Aqui:

A tem prioridade 2

B prioridade 1

C prioridade 3

🔸 Remoção (dequeue)

Para remover o mais prioritário, percorremos o vetor e achamos o maior valor de prioridade.

Removemos esse elemento.

Complexidade: O(n).

No exemplo acima, removemos (C, 3) pois é o de maior prioridade.

🔸 Problema do vetor

Inserir é rápido.

Remover é lento, pois precisamos percorrer todo o vetor.

👉 Para resolver isso usamos Heap.

# Implementação com Heap Binário

Um heap é uma árvore binária quase completa (preenchida da esquerda para a direita), representada em vetor.

Max-Heap → o pai é sempre maior que os filhos (usado para prioridade “maior primeiro”).

Min-Heap → o pai é sempre menor que os filhos (usado para prioridade “menor primeiro”).

## 2.1 Estrutura no vetor

Um Heap binário é armazenado num array com as regras:

Índice do pai: i

Filho esquerdo: 2*i

Filho direito: 2*i + 1

Exemplo (Max-Heap):

Array: [50, 30, 20, 15, 10, 8, 16]

Árvore:

          50
       /      \
     30        20
    /  \      /  \
  15   10   8   16

## 2.2 Inserção (enqueue)

Insere o novo elemento no fim do array.

Faz o processo chamado heapify-up (ou “subir o nó”):

Se o elemento for maior que o pai, troca de posição.

Repete até a propriedade do heap ser mantida.

Exemplo: Inserir 60:

Array inicial: [50, 30, 20, 15, 10, 8, 16]
Inserir 60 → [50, 30, 20, 15, 10, 8, 16, 60]

Heapify-up:
60 > 15 → troca
60 > 30 → troca
60 > 50 → troca


Resultado:

[60, 50, 20, 30, 10, 8, 16, 15]

          60
       /      \
     50        20
    /  \      /  \
  30   10   8   16
 /
15


Complexidade: O(log n).

## 2.3 Remoção (dequeue)

O maior elemento está sempre na raiz (array[0]).

Para removê-lo:

Substituímos a raiz pelo último elemento.

Aplicamos heapify-down (descer o nó):

Compara com os filhos.

Troca com o maior deles se for menor.

Repete até restaurar a propriedade do heap.

Exemplo: Remover 60:

Array antes: [60, 50, 20, 30, 10, 8, 16, 15]
Troca raiz por último: [15, 50, 20, 30, 10, 8, 16]

Heapify-down:
15 < 50 → troca
15 < 30 → troca


Resultado:

[50, 30, 20, 15, 10, 8, 16]

          50
       /      \
     30        20
    /  \      /  \
  15   10   8   16


Complexidade: O(log n).

# Comparação: Vetor x Heap

| Implementação  | Inserção | Remoção (maior prioridade) |
| ------------- | ------------- | ------------- |
| Vetor  | O(1)  | O(n) |
| Heap  | O(log n) | O(n) |

# Segue ilustração abaixo exemplo do funcionamento de uma lista com 3 elementos inseridos:

<img width="773" height="431" alt="image" src="https://github.com/user-attachments/assets/b9829867-4ff5-4525-b0bf-73d5eb01cc39" />
