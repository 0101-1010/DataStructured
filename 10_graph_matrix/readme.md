# O que é um Grafo?

Um grafo é uma estrutura de dados usada para representar relacionamentos entre objetos:

Vértices (nós) → representam objetos ou entidades.

Arestas (edges) → representam conexões entre vértices.

Exemplo: cidades conectadas por estradas, redes sociais, mapas de rotas.

🔹 Representação de Grafo

Existem duas formas comuns de representar grafos:

Lista de adjacência → cada vértice mantém uma lista de vértices conectados (útil para grafos esparsos).

Matriz de adjacência → usamos uma matriz 2D, onde:

matriz[i][j] = 1 → existe aresta de i para j
matriz[i][j] = 0 → não existe aresta


Fácil de verificar se existe uma aresta entre dois vértices.

Ocupa memória O(V²) → menos eficiente para grafos esparsos.

# Estrutura de Matriz de Adjacência

Para um grafo com 4 vértices (0 a 3):

    0  1  2  3
0 [ 0, 1, 1, 0 ]
1 [ 0, 0, 1, 0 ]
2 [ 0, 0, 0, 1 ]
3 [ 0, 0, 0, 0 ]


A linha i representa origem do vértice i.

A coluna j representa destino do vértice j.

Exemplo: matriz[0][1] = 1 → existe aresta de 0 para 1.

# Inserção de Aresta

Para adicionar uma aresta (u, v):

matriz[u][v] = 1;


Para grafo não-direcionado, também fazemos:

matriz[v][u] = 1;


Inserção é O(1), muito rápida.

# Verificação de Aresta

Para verificar se existe aresta entre i e j:

if (matriz[i][j] == 1) { /* existe */ }


Também é O(1).

# Percorrer os vizinhos de um vértice

Para percorrer todos os vizinhos de v:

for (int i = 0; i < n; i++) {
    if (matriz[v][i]) {
        printf("%d ", i);
    }
}

Diferença com lista de adjacência: percorremos toda a linha da matriz, mesmo que a maioria seja 0.

# Vantagens da matriz de adjacência

Consulta rápida: existe aresta entre u e v? → O(1)

Simples de implementar.

Útil para grafos densos (muitas arestas).

# Desvantagens

Usa muito espaço (O(V²)) para grafos grandes e esparsos.

Inserir/remover aresta é fácil, mas percorrer vizinhos pode ser menos eficiente se houver poucos vizinhos.

# Segue ilustração abaixo exemplo do funcionamento de um Grafo implementado com matriz com 9 elementos inseridos:

<img width="300" height="317" alt="image" src="https://github.com/user-attachments/assets/047ccd13-0fd6-47c6-a3eb-e7d712a294ca" />
