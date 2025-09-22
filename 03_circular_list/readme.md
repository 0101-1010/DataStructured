# O que é uma Lista Circular?

Diferente da lista simples e da lista duplamente encadeada, na lista circular o último nó não aponta para NULL.

Ele aponta de volta para o primeiro nó (no caso da simples circular) ou conecta-se nos dois sentidos (no caso da duplamente circular).

👉 Isso forma um ciclo fechado, como se fosse um "anel" de nós.

# Estado inicial da lista

Lista vazia:

Head -> NULL

# Inserção do primeiro nó

Inserindo 10 em uma lista circular simples:

Criamos o nó [10].

O ponteiro next desse nó aponta para ele mesmo (porque é o único nó).

Head aponta para esse nó.

Visual:

Head
  ↓
 [10]
   ↓
  (volta para ele mesmo)

# Inserção no início

Inserindo 20 no início:

Criamos [20].

O next de [20] aponta para o Head atual ([10]).

O último nó da lista (que ainda é [10]) agora precisa apontar para [20].

Atualizamos Head para [20].

Visual:

Head -> [20] -> [10] -+
        ^-------------+

# Inserção no fim

Inserindo 30 no fim:

Criamos [30].

O next de [30] aponta para o Head ([20]).

O último nó atual ([10]) aponta para [30].

Atualizamos Tail (se quisermos manter referência para o fim).

Visual:

Head -> [20] -> [10] -> [30] -+
        ^---------------------+

# Busca de um elemento

Procurando 10:

Começa no Head → [20].

Vai para o próximo → [10] → ✅ encontrado.

Se não for encontrado, o laço para quando voltar ao Head.

Visual da busca:

[20] -> [10] -> [30] -+
        ^              |
        +--------------+

# Remoção de um elemento

Remover [10]:

Percorremos até encontrar [10].

Ajustamos o next de [20] para [30].

[30] continua apontando para [20], mantendo o ciclo.

Liberamos [10].

Visual:

Head -> [20] -> [30] -+
        ^--------------+

# Segue ilustração abaixo exemplo do funcionamento de uma lista com 6 elementos inseridos:

<img width="411" height="599" alt="image" src="https://github.com/user-attachments/assets/53350cf8-64ff-4f5a-b91f-c1d5f4c37c8e" />
