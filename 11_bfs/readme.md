# O que é BFS?

BFS é um algoritmo de busca em grafos que percorre o grafo nível por nível.

Ele começa em um vértice inicial e visita todos os vértices vizinhos antes de passar para os vizinhos dos vizinhos.

BFS é garantido encontrar o caminho mais curto em um grafo não ponderado.

# Estruturas usadas

Para implementar BFS, precisamos de:

Fila (queue) → mantém os vértices a serem visitados na ordem correta (FIFO).

Vetor de visitados (visited) → evita visitar o mesmo vértice várias vezes.

# Passo a passo do algoritmo

Marque todos os vértices como não visitados.

Coloque o vértice inicial na fila e marque como visitado.

Enquanto a fila não estiver vazia:

Remova o vértice do início da fila (u).

Para cada vizinho v de u:

Se v não foi visitado:

Marque v como visitado.

Coloque v na fila.

Repita até que todos os vértices alcançáveis sejam visitados.

# Exemplo visual

Suponha um grafo:

0 → 1 → 3
|    |
v    v
2 → 4


BFS começando do vértice 0:

Fila: [0] → visita 0 → vizinhos: 1, 2 → Fila: [1,2]

Fila: [1,2] → visita 1 → vizinhos: 3, 4 → 3 e 4 não visitados → Fila: [2,3,4]

Fila: [2,3,4] → visita 2 → vizinhos: 4 (já visitado) → Fila: [3,4]

Fila: [3,4] → visita 3 → vizinhos: nenhum novo → Fila: [4]

Fila: [4] → visita 4 → vizinhos: nenhum novo → Fila vazia → BFS termina

Ordem de visita: 0,1,2,3,4

# Propriedades importantes do BFS

Complexidade de tempo: O(V + E) → percorre todos os vértices e arestas.

Complexidade de espaço: O(V) → fila + vetor de visitados.

Garantia de caminho mais curto: para grafos não ponderados.

# Segue ilustração abaixo exemplo do funcionamento de uma algoritmo BFS com 4 elementos inseridos:

<img width="296" height="538" alt="image" src="https://github.com/user-attachments/assets/fccd08b5-4aee-49ab-ba6d-a2ec0d978d8e" />
