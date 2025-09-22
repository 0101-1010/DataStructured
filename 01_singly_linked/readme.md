# O que é uma lista encadeada simples

Uma lista encadeada simples (ou singly linked list) é uma estrutura de dados linear que armazena elementos (chamados de nós) em sequência, onde cada nó sabe apenas quem vem depois dele.

Cada nó contém dois componentes principais:

Dado: a informação que você quer guardar (por exemplo, um número, uma letra ou um objeto).

Ponteiro para o próximo nó: um endereço de memória que aponta para o próximo nó na lista.

O último nó da lista aponta para NULL (ou nullptr em C++), indicando que não há mais elementos.

Visualmente, uma lista encadeada simples com 3 elementos ficaria assim:

[10 | *] -> [20 | *] -> [30 | NULL]


[10 | *] → nó com dado 10 e ponteiro para o próximo nó

[20 | *] → nó com dado 20 e ponteiro para o próximo nó

[30 | NULL] → último nó, aponta para NULL

# Diferença para um vetor/array

Array: os elementos ficam em posições contíguas na memória. Acesso é rápido (índice direto), mas inserir ou remover elementos no meio exige deslocar tudo.

Lista encadeada: os elementos podem ficar em qualquer lugar na memória. Inserir e remover é rápido, porque você só muda os ponteiros. Mas o acesso é sequencial — para chegar ao 5º elemento, precisa passar pelos 4 primeiros.

# Principais operações
a) Inserção

No início:

Cria um novo nó.

Faz o ponteiro do novo nó apontar para o nó que atualmente é o primeiro.

Atualiza o ponteiro da lista para o novo nó.

Novo nó -> Primeiro nó atual -> ...

<img width="380" height="244" alt="image" src="https://github.com/user-attachments/assets/fbc972c1-209f-4876-bdf9-153083e08ae4" />

No fim:

Cria um novo nó com ponteiro NULL.

Percorre a lista até o último nó.

Faz o ponteiro do último nó atual apontar para o novo nó.

Head -> [20 | *] -> [10 | *] -> [30 | NULL]

b) Remoção

No início:

Salva referência para o primeiro nó.

Atualiza o ponteiro da lista para o segundo nó.

Libera a memória do nó removido.

No meio/fim:

Percorre a lista até encontrar o nó anterior ao que será removido.

Faz o ponteiro desse nó apontar para o próximo do nó que será removido.

Libera a memória do nó removido.

c) Busca

Começa no primeiro nó e percorre a lista um por um, comparando o dado de cada nó com o valor procurado.

Retorna o nó ou NULL se não encontrar.

# Vantagens da lista encadeada simples

Inserção e remoção em qualquer posição sem mover elementos, só ajustando ponteiros.

Tamanho da lista dinâmico, não precisa definir tamanho fixo como array.

Útil quando não se sabe de antemão quantos elementos terá a lista.

# Desvantagens

Acesso sequencial é mais lento que array.

Ocupa mais memória (cada nó precisa de um ponteiro além do dado).

Mais suscetível a erros de ponteiro (como esquecer de atualizar ou liberar memória).

<img width="409" height="584" alt="image" src="https://github.com/user-attachments/assets/3c78e4be-1d2f-4cca-bf3d-b932fdb5e2e9" />

