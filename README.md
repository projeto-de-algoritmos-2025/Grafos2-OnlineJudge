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

🧠 Esse é um problema clássico de **Árvore Geradora Mínima (Minimum Spanning Tree)**, que pode ser resolvido usando:

- **Kruskal** com Union-Find, ou
- **Prim** com Heap (mais eficiente nesse caso, pois o número de arestas possíveis é grande).
  
Nós resolvemos resolver das duas formas e chegamos a conclusão que o algoritmo de Prim se comportou melhor.

## Screenshots
- Problema 1584 com Kruskal
<img width="734" alt="1584 Kruskal" src="img\kruskal.png">

- Problema 1584 com Prim 
<img width="734" alt="1585 Prim" src="img\prim.png">


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
A apresentação da entrega pode ser visualizada [aqui](). 
