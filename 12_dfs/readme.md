# O que é DFS?

DFS é um algoritmo de busca em grafos que percorre o grafo indo fundo em cada caminho antes de voltar.

Começa em um vértice inicial e explora profundamente cada vizinho antes de explorar os próximos vizinhos do vértice inicial.

DFS pode ser implementado recursivamente ou usando uma pilha.

# Estruturas usadas

Para implementar DFS, precisamos de:

Vetor de visitados (visited) → para marcar vértices já explorados.

Recursão ou pilha → para controlar a profundidade do percurso.

# Passo a passo do algoritmo

Marque todos os vértices como não visitados.

Escolha um vértice inicial v.

Visite v:

Marque como visitado.

Para cada vizinho u de v:

Se u não foi visitado, faça DFS recursivamente em u.

A ideia principal: explorar profundamente cada caminho antes de voltar.

🔹 Exemplo visual

Suponha um grafo:

0 → 1 → 3
|    |
v    v
2 → 4


DFS começando do vértice 0 (recursivo):

Visita 0 → vizinhos: 1, 2 → vai para 1

Visita 1 → vizinhos: 3, 4 → vai para 3

Visita 3 → vizinhos: nenhum novo → volta para 1

Próximo vizinho de 1 → 4 → visita 4

Volta para 0 → próximo vizinho → 2 → visita 2

Ordem de visita possível: 0,1,3,4,2

DFS não garante visitar os vértices na menor distância, apenas percorre profundidade primeiro.

# Propriedades importantes do DFS

Complexidade de tempo: O(V + E) → percorre todos os vértices e arestas.

Complexidade de espaço: O(V) → vetor de visitados + pilha de recursão.

Aplicações:

Verificar conectividade do grafo

Detectar ciclos

Ordenação topológica (em DAGs)

Resolver labirintos e puzzles

# Segue ilustração abaixo exemplo do funcionamento de um algoritmo DFS com 4 elementos inseridos:

<img width="309" height="399" alt="image" src="https://github.com/user-attachments/assets/5686bb9d-f886-4768-9931-cb4f330997be" />
