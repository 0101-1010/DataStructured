# O que é uma Árvore Binária?

É uma estrutura hierárquica onde cada nó pode ter até dois filhos:

Esquerda (left)

Direita (right)

O primeiro nó é chamado de raiz (root).

Se um nó não tem filhos → é uma folha (leaf).

📌 Exemplo de árvore binária:

        (10)
       /    \
    (5)      (15)
 
# Inserção em Árvore Binária de Busca (BST)

A Árvore Binária de Busca tem uma regra importante:

Valores menores que o nó atual vão para a esquerda.

Valores maiores vão para a direita.

Passo a passo da inserção
Inserir 10 (primeiro elemento → raiz):
   (10)

Inserir 5:

5 < 10 → vai para a esquerda.

       (10)
      /
    (5)

Inserir 15:

15 > 10 → vai para a direita.

       (10)
      /    \
    (5)    (15)

Inserir 7:

7 < 10 → vai para a esquerda.

7 > 5 → vai para a direita de (5).

       (10)
      /    \
    (5)    (15)
      \
      (7)

Inserir 2:

2 < 10 → esquerda.

2 < 5 → esquerda de (5).

       (10)
      /    \
    (5)    (15)
   /  \
 (2)  (7)


👉 Agora temos uma BST bem formada.

# Travessias da Árvore

Uma travessia é o modo como visitamos os nós da árvore.
Existem 3 principais (em profundidade):

## 2.1 Pré-ordem (Pre-order: Nó → Esquerda → Direita)

Visita o nó atual.

Percorre a subárvore esquerda.

Percorre a subárvore direita.

Exemplo na árvore:

       (10)
      /    \
    (5)    (15)
   /  \
 (2)  (7)


Ordem: 10 → 5 → 2 → 7 → 15

## 2.2 Em-ordem (In-order: Esquerda → Nó → Direita)

Percorre a subárvore esquerda.

Visita o nó atual.

Percorre a subárvore direita.

Na mesma árvore:

Ordem: 2 → 5 → 7 → 10 → 15

📌 Observação: Em uma BST, a travessia em-ordem gera os valores em ordem crescente.

## 2.3 Pós-ordem (Post-order: Esquerda → Direita → Nó)

Percorre a subárvore esquerda.

Percorre a subárvore direita.

Visita o nó atual.

Ordem: 2 → 7 → 5 → 15 → 10

## 2.4 Nível a nível (Level-order ou BFS)

Percorre a árvore de cima para baixo, da esquerda para a direita, usando uma fila.

Ordem: 10 → 5 → 15 → 2 → 7

# Segue ilustração abaixo exemplo do funcionamento de uma lista com 3 elementos inseridos:

<img width="302" height="615" alt="image" src="https://github.com/user-attachments/assets/056d4203-ff56-450b-998b-2b403b48ce81" />
