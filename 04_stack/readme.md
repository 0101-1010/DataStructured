# O que é uma Pilha?

A pilha funciona no modelo LIFO (Last In, First Out) → o último elemento a entrar é o primeiro a sair.

Pense em uma pilha de pratos: você coloca um prato em cima (push) e tira o prato de cima (pop).

# Estado inicial da Pilha

Pilha vazia:

Topo -> NULL

Não há elementos.

# Operação PUSH (empilhar)

Inserir 10 na pilha:

Criamos um nó [10].

Ele aponta para o antigo topo (NULL).

Atualizamos Topo para [10].

Visual:

Topo -> [10]
Inserir 20:

Criamos [20].

Ele aponta para [10].

Atualizamos Topo para [20].

Visual:

Topo -> [20]
          ↓
        [10]


Inserir 30:

Topo -> [30]
          ↓
        [20]
          ↓
        [10]

# Operação POP (desempilhar)

Remover o elemento do topo:

O topo atual é [30].

Atualizamos Topo para o próximo ([20]).

Liberamos [30].

Visual após POP:

Topo -> [20]
          ↓
        [10]

# Operação PEEK / TOP

Apenas consulta o elemento do topo sem removê-lo.

Se chamarmos peek() aqui, ele retorna 20

# Pilha vazia

Se fizermos POP até esvaziar:

Topo -> NULL

Tentativa de POP em uma pilha vazia → underflow (erro).

# Segue ilustração abaixo exemplo do funcionamento de uma lista com 3 elementos inseridos:

<img width="385" height="243" alt="image" src="https://github.com/user-attachments/assets/276f46ff-a921-44a1-b860-d40f98f1ba95" />
