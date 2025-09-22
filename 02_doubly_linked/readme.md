# O que é uma lista duplamente encadeada

Uma lista duplamente encadeada (doubly linked list) é uma estrutura de dados linear, semelhante à lista encadeada simples, mas com uma diferença importante:

Cada nó possui dois ponteiros:

next → aponta para o próximo nó da lista.

prev → aponta para o nó anterior da lista.

O primeiro nó aponta para NULL no campo prev.

O último nó aponta para NULL no campo next.

Visualmente, uma lista com 3 elementos ficaria assim:

NULL <- [10 | * | *] <-> [20 | * | *] <-> [30 | * | *] -> NULL


[10 | * | *] → dado 10, ponteiro prev = NULL, ponteiro next para [20].

[20 | * | *] → dado 20, prev para [10], next para [30].

[30 | * | *] → dado 30, prev para [20], next = NULL.

# Diferença para lista simples

| Lista Simples| Lista Duplamente Encadeada |
| ------------- | ------------- |
| Cada nó aponta só para o próximo  | Cada nó aponta para o próximo e o anterior |
| Percurso só pode ser do início ao fim.  | Permite percorrer para frente e para trás.  |
| Inserção/removação requer percorrer até o nó anterior, se necessário | Inserção/removação mais fácil em qualquer posição, pois temos prev |

# Principais operações
## a) Inserção

No início:

Cria um novo nó.

next do novo nó aponta para o nó atual head.

prev do nó atual head aponta para o novo nó.

Atualiza head para o novo nó.

NULL <- [novo | * | NULL] <-> [antigo | * | *] -> ...


No fim:

Cria o nó com next = NULL.

Percorre a lista até o último nó.

Atualiza o next do último nó para apontar para o novo.

Atualiza prev do novo nó para apontar para o último nó.

No meio:

Localiza o nó após o qual quer inserir.

Ajusta os ponteiros next e prev dos nós vizinhos e do novo nó.

## b) Remoção

De qualquer posição:

Localiza o nó que deseja remover.

Faz next do nó anterior apontar para o próximo nó.

Faz prev do próximo nó apontar para o nó anterior.

Libera a memória do nó removido.

Visual da remoção do nó 20:

Antes:  [10] <-> [20] <-> [30]
Depois: [10] <-> [30]

## c) Busca

Pode percorrer do início ao fim ou do fim ao início.

Verifica cada nó comparando o dado com o valor procurado.

Retorna o nó encontrado ou NULL se não existir.

# Vantagens da lista duplamente encadeada

Percurso bidirecional.

Inserção e remoção mais flexível, mesmo no meio da lista.

Útil quando precisamos mover-se para frente e para trás.

# Desvantagens

Cada nó ocupa mais memória (dois ponteiros em vez de um).

Mais suscetível a erros de ponteiro, pois é preciso atualizar prev e next corretamente.

Acesso sequencial ainda é necessário (não dá acesso direto por índice).

# Segue ilustração abaixo exemplo do funcionamento de uma lista com 3 elementos inseridos:
## Print forward
<img width="428" height="604" alt="image" src="https://github.com/user-attachments/assets/0f9de5b5-33e7-4db6-9524-20e7aef19a14" />

## Print backward
<img width="428" height="606" alt="image" src="https://github.com/user-attachments/assets/9ad89894-78a5-4109-990e-12b0b3020e82" />

