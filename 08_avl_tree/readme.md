# O que é uma Árvore AVL?

Uma Árvore AVL é uma Árvore Binária de Busca (BST) com a propriedade adicional de balanceamento.

Cada nó possui um fator de balanceamento (FB):

FB=altura(subárvoreesquerda)−altura(subárvoredireita)

Regras:

FB = -1, 0 ou +1 → árvore balanceada.

Se |FB| > 1 → árvore desbalanceada → é necessário rotacionar.

🔹 Por que balancear?

Em uma BST comum, inserções desbalanceadas podem gerar uma lista degenerada, com complexidade de busca O(n).

AVL garante que a altura da árvore seja sempre O(log n), mantendo buscas, inserções e remoções rápidas.

# Inserção em Árvore AVL

Passo a passo:

Inserimos o novo valor como em uma BST normal (menor → esquerda, maior → direita).

Atualizamos a altura de cada nó.

Calculamos o fator de balanceamento.

Se algum nó estiver desbalanceado (|FB| > 1), aplicamos rotações.

# Tipos de Desbalanceamento e Rotações

Existem quatro casos principais:

## 2.1 Rotação Simples à Direita (Right Rotation – RR)

Ocorre em desbalanceamento à esquerda → esquerda (Left-Left)

Situação: inserimos na subárvore esquerda do filho esquerdo.

Antes:
        30
       /
     20
    /
  10


Rotação à direita:

        20
       /  \
     10    30

## 2.2 Rotação Simples à Esquerda (Left Rotation – LL)

Ocorre em desbalanceamento à direita → direita (Right-Right)

Situação: inserimos na subárvore direita do filho direito.

Antes:
    10
      \
       20
         \
         30


Rotação à esquerda:

       20
      /  \
    10    30

## 2.3 Rotação Dupla à Direita (Left-Right Rotation – LR)

Ocorre em desbalanceamento à esquerda → direita (Left-Right)

Situação: inserimos na subárvore direita do filho esquerdo.

Antes:
       30
      /
    10
      \
      20


Rotações:

Rotação à esquerda no filho esquerdo (10 → 20)

Rotação à direita no nó desbalanceado (30 → 20)

        20
       /  \
     10    30

## 2.4 Rotação Dupla à Esquerda (Right-Left Rotation – RL)

Ocorre em desbalanceamento à direita → esquerda (Right-Left)

Situação: inserimos na subárvore esquerda do filho direito.

Antes:
    10
      \
       30
      /
    20


Rotações:

Rotação à direita no filho direito (30 → 20)

Rotação à esquerda no nó desbalanceado (10 → 20)

       20
      /  \
    10    30

# Exemplo passo a passo

Inserindo na ordem: 10, 20, 30

Inserir 10 → raiz = 10 → balanceada

Inserir 20 → 20 à direita de 10 → balanceada

Inserir 30 → 30 à direita de 20 → desbalanceamento RR

Aplicar rotação à esquerda

Árvore final:
       20
      /  \
    10    30


Agora a árvore está balanceada com fator de balanceamento FB ∈ [-1,1].

# Travessias (mesmo que BST)

As travessias de AVL são as mesmas que em BST:

Pré-ordem (Root → Esquerda → Direita)

Em-ordem (Esquerda → Root → Direita) → retorna valores em ordem crescente

Pós-ordem (Esquerda → Direita → Root)

Nível a nível (BFS)

# Segue ilustração abaixo exemplo do funcionamento de uma lista com 3 elementos inseridos:

<img width="310" height="619" alt="image" src="https://github.com/user-attachments/assets/7ac91274-ddcb-40a2-bbd0-e0a435fcfc2e" />

