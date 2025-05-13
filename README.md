# Lista de Exercícios de um Juiz Online

**Número da Lista**: 2<br>
**Conteúdo da Disciplina**: Grafos 2<br>

## Alunos
|Matrícula | Aluno |
| -- | -- |
| 21/1031584  |  Ana Letícia Melo Pereira |
| 20/0073184 |  Mateus Fidelis Marinho Maia |

## Sobre 
Para desenvolver o conteúdo abordado no tópico de Grafos 2, a dupla selecionou três exercícios em um juiz online - o LeetCode -, sendo eles, dois de nível difícil e um de nível médio. Para obter mais informações sobre os enunciados propostos, basta clicar no link que aparece no título de cada um.

### 🔗 [1584: Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/description/)
 Resumo:
- Dado um conjunto de pontos em um plano 2D, conecte todos os pontos com o **menor custo possível**, onde:

- O custo de conectar dois pontos \((x1, y1)\) e \((x2, y2)\) é a **distância de Manhattan**:  
  \[
  |x1 - x2| + |y1 - y2|
  \]

Você **pode conectar qualquer par de pontos**, e deseja que **todos os pontos fiquem conectados direta ou indiretamente**.

- Nível de dificuldade: Médio.

### 🧠 Algoritmo utilizado:
Esse é um problema clássico de **Árvore Geradora Mínima (Minimum Spanning Tree)**, que pode ser resolvido usando:

- **Kruskal** com Union-Find, ou
- **Prim** com Heap (mais eficiente nesse caso, pois o número de arestas possíveis é grande).
  
Nós resolvemos resolver das duas formas e chegamos a conclusão que o algoritmo de Prim se comportou melhor.

---

### 🔗 [1568: Minimum Number of Days to Disconnect Island](https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/)

### Resumo:
- Dada uma grade 2D de valores binários (0 = água, 1 = terra), determine o **número mínimo de dias** necessários para **desconectar** a ilha (deixar de haver uma única massa de terra conectada ortogonalmente).
- Em cada dia, é possível remover uma única célula de terra, transformando-a em água.
- Uma ilha está desconectada se houver **mais de um componente conexo de terra** ou **nenhum**.

- Nível de dificuldade: Médio.


### 🧠 Algoritmo utilizado:
- **DFS (Depth-First Search)** para contar o número de componentes conexos de terra (`1`s).
- A cada iteração, simula a remoção de uma célula e verifica se a ilha se desconecta.
- Estratégia:
  1. Verificar se a ilha **já está desconectada** no início.
  2. Testar a remoção de **cada célula individualmente**.
  3. Se nenhuma célula for suficiente, a resposta é `2`.



### ⚙️ Estrutura principal:
- `countIslands(grid, gridSize, gridColSize)`:
  - Conta quantas componentes conexas existem na grade usando DFS.
  - Marca os nós visitados para não repetir visitas.
- `minDays(grid, gridSize, gridColSize)`:
  - Primeiramente, verifica se a ilha já está desconectada.
  - Depois, para cada célula `1`, a remove temporariamente, verifica se há mais de um componente e restaura.
  - Se nenhuma célula individual causa a desconexão, retorna `2`.

---

### 🔗 [743: Network Delay Time](https://leetcode.com/problems/network-delay-time/)

### Resumo:
- Dado um grafo **dirigido e ponderado**, com `n` nós numerados de `1` a `n`, e uma lista de arestas no formato `[u, v, w]`, que indica um tempo `w` para o sinal ir de `u` para `v`.
- Um sinal é enviado a partir de um nó inicial `k`.
- O objetivo é calcular o **tempo mínimo necessário** para que **todos os nós recebam o sinal**.
- Se **algum nó não for alcançável**, retorne `-1`.

- Nível de dificuldade: Médio.

- Esse é um problema clássico de **caminhos mínimos a partir de uma origem** que pode ser resolvido com **Dijkstra usando min-heap**.

### 🧠 Algoritmo utilizado:
- **Dijkstra com Min-Heap (Priority Queue)** para otimizar a escolha do próximo nó com menor custo acumulado.
- Estrutura usada:
  - **Matriz de adjacência** para armazenar pesos das arestas.
  - **Heap mínima** personalizada para priorizar nós com menor tempo acumulado.
- A estratégia é:
  1. Inicializar distâncias com infinito, exceto o nó inicial.
  2. Usar a heap para visitar o nó com menor distância atual.
  3. Relaxar as arestas para os vizinhos e atualizar a heap.
  4. Após o término, retornar a maior distância encontrada, se todos os nós forem alcançados.

### ⚙️ Estrutura principal:
- `networkDelayTime(times, timesSize, timesColSize, n, k)`:
  - Recebe a lista de arestas, o número de nós `n` e o nó inicial `k`.
  - Retorna o tempo total para o sinal alcançar todos os nós, ou `-1` se algum nó for inalcançável.
- Heap mínima personalizada:
  - Suporte a inserção (`push`), remoção do menor (`pop`) e reorganização (`heapify`).
  - Guarda pares `(nó, tempo acumulado)`.



## Screenshots
- Problema 1584 com Kruskal
<img width="734" alt="1584 Kruskal" src="img\kruskal.png">

- Problema 1584 com Prim 
<img width="734" alt="1585 Prim" src="img\prim.png">

- Problema 1568 com SCC 
<img width="734" alt="1568 SCC" src="img\scc.png">

- Problema 743 com Dijkstra 
<img width="734" alt="743 Dijkstra" src="img\743.png">

## Instalação 

Linguagens: C e Python
Pré-requisitos: Compilador GCC, Python 3.4 

## 1. Clone o repositório 

```bash
git clone https://github.com/projeto-de-algoritmos-2025/Grafos1-OnlineJudge.git
```

### 2. Compile o programa

Em C:
```bash
gcc -o nome_do_arquivo.c nome_do_executável  
./nome_do_executável
```

Em Python:
```bash
python arquivo.py
```

## Uso 
Para aplicar os casos de teste (in e out), basta acessar o link referente ao exercício no LeetCode e inserí-los no prompt de comando, também é possível gerar novos casos de teste, desde que cumpram os requisitos do exercício em questão.

## Outros 
A apresentação da entrega pode ser visualizada [aqui](https://unbbr.sharepoint.com/:v:/s/TrabalhodePA412/EVgmfkB4aedGkgaTxFZ7EF8BKOrTLEemtGuu_3aB3jCH8Q?e=KfhUwM&nav=eyJyZWZlcnJhbEluZm8iOnsicmVmZXJyYWxBcHAiOiJTdHJlYW1XZWJBcHAiLCJyZWZlcnJhbFZpZXciOiJTaGFyZURpYWxvZy1MaW5rIiwicmVmZXJyYWxBcHBQbGF0Zm9ybSI6IldlYiIsInJlZmVycmFsTW9kZSI6InZpZXcifX0%3D). 
