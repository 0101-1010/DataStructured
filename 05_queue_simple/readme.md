# O que é uma Fila?

A fila segue o modelo FIFO (First In, First Out) → o primeiro que entra é o primeiro que sai.

Pense numa fila de banco ou supermercado: quem entrou primeiro será atendido antes.

👉 Diferente da pilha (LIFO), aqui os elementos entram por um lado (fim) e saem pelo outro (início).

# Estado inicial da fila

Fila vazia:

Frente -> NULL <- Fim

# Operação ENQUEUE (enfileirar)

Inserir 10:

Criamos [10].

Como a fila está vazia, Frente e Fim apontam para ele.

Frente -> [10] <- Fim

Operação ENQUEUE (enfileirar)

Inserir 10:

Criamos [10].

Como a fila está vazia, Frente e Fim apontam para ele.

Frente -> [10] <- Fim

Inserir 30:

Frente -> [10] -> [20] -> [30] <- Fim

# Operação DEQUEUE (desenfileirar)

Remover da frente:

O primeiro da fila é [10].

Atualizamos Frente para [20].

Liberamos [10].

Frente -> [20] -> [30] <- Fim

Outro DEQUEUE:

Frente -> [30] <- Fim

Mais um DEQUEUE:

Frente -> NULL <- Fim


Fila agora está vazia.

Se tentarmos DEQUEUE em uma fila vazia → underflow (erro).

# Operação PEEK (espiar frente)

Apenas consulta o valor que está no início da fila (sem remover).

Exemplo: na fila [20] -> [30], o peek() retorna 20.

# Segue ilustração abaixo exemplo do funcionamento de uma lista com 3 elementos inseridos:

<img width="378" height="444" alt="image" src="https://github.com/user-attachments/assets/6f834cdf-c9a3-43d9-97fc-420ba773dfc2" />
