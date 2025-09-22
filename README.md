# Repositório: Estruturas de Dados e Algoritmos em C

Conteúdo:
Cada item possui duas versões em C:
- `*_simple.c` — versão mínima, curta e comentada em português, pensada para ser copiada e rodar em https://pythontutor.com/c.html.
- `*_full.c` — versão completa, extensivamente documentada em português com funções úteis e exemplos.

Lista de programas (12):
1. 01_singly_linked_{simple,full}.c — Lista Encadeada Simples
2. 02_doubly_linked_{simple,full}.c — Lista Duplamente Encadeada
3. 03_circular_list_{simple,full}.c — Lista Circular
4. 04_stack_{simple,full}.c — Pilha
5. 05_queue_simple_{simple,full}.c — Fila Simples (circular buffer)
6. 06_priority_queue_{simple,full}.c — Fila de Prioridade (vetor) / Heap na versão full
7. 07_binary_tree_{simple,full}.c — Árvore Binária (inserção e travessias)
8. 08_avl_tree_{simple,full}.c — Árvore Balanceada (AVL)
9. 09_graph_adjlist_{simple,full}.c — Grafo com lista de adjacência
10. 10_graph_matrix_{simple,full}.c — Grafo com matriz de adjacência
11. 11_bfs_{simple,full}.c — Busca em Largura (BFS)
12. 12_dfs_{simple,full}.c — Busca em Profundidade (DFS)

Como usar:
- Para executar localmente: compile com `gcc arquivo.c -o programa && ./programa`.
- Para testar as versões simples no Python Tutor: abra https://pythontutor.com/c.html, cole o conteúdo do arquivo `*_simple.c` e execute (não use includes não suportados pelo visualizador).
- Os arquivos `*_full.c` incluem comentários extensos em português explicando cada função e algoritmos.
