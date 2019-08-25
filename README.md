# Uma implementação do algoritmo de Sorensen e Janssens

Trabalho realizado durante a disciplina DCA0214 - Estrutura de dados no semestre 2019.1 com o objeto de implementar o algoritmo proposto no artigo de [SORENSEN, Kenneth  e  JANSSENS, Gerrit K](http://www.scielo.br/scielo.php?pid=S0101-74382005000200004&script=sci_abstract).

## Gerador de grafos

Para a utilização do gerador de grafos tanto completo quanto grid primeiramente se faz necessário compliar os arquivos fonte, o que pode ser conseguido fazendo:

```console
user@computer:~/sapanningTrees $ cd generators
user@computer:~/sapanningTrees/generators $ make
```

Os geradores terão como saída um arquivo com extensão *.in* , nomeados da seguinte forma: *6grid.in* significa uma instância com 6 vértices do tipo grafo grid; *5completo.in* significa uma instância com 5 vértices do tipo grafo completo. Um arquivo de instância tem o seguinte formato: a primeira linha contém o valor *n* da quantidade de vértices, seguido por uma linha para cada aresta, no formato: *i j p*, onde 1 <= *i* <= *n*  e 1 <= *j* <= *n* são os vértices terminais a referida aresta, e *p* é o seu peso.

### Gerando um grafo completo

Para gerar uma instância de grafo completo execute o comando a seguir substituindo **vertices** pelo número de vértices desejado:

```console
user@computer:~/sapanningTrees/generators $ ./completeGraph.out vertices
```

### Gerando um grafo grid

Para gerar uma instância de grafo grid execute o comando a seguir substituindo **rows** e **cols** pelo número de linhas e de colunas que o grafo deve possuir:

```console
user@computer:~/sapanningTrees/generators $ ./gridGraph.out rows cols
```

## Plotando um grafo

Em adicição ao gerador de grafos está disponivel também um programa escrito em python para plotar instâncias de grafos a partir de arquivos de instancia *.in*, para utilizar o script tenha instalado os seguintes módulos python: [networkx](https://networkx.github.io/documentation/stable/install.html) e [matplotlib](https://matplotlib.org/users/installing.html). O plot de um grafo pode ser feito com o seguinte comando a partir do diretórito srcipts deste repositório, substituindo **grafo** pelo caminho para uma instância de grafo:

```console
user@computer:~/sapanningTrees/scripts $ python3 plotGraph.py grafo
```

## Árvore geradora mínima

Primeiramente se faz necessário compilar os arquivos fontes que serão utilizados para encontrar a árvore geradora mínima, o que pode ser conseguido fazendo:

```console
user@computer:~/sapanningTrees $ cd src
user@computer:~/sapanningTrees/src $ make minimumSpanningTree
```

Para obter a árvore geradora mínima de um grafo execute o comando a seguir substituindo **graph** pelo caminho de uma instância de grafo:

```console
user@computer:~/sapanningTrees/src $ ./minimumSpanningTree.out graph
```

Será encaminhado para *stdout* um resultado similar à:

```text
Grafo
 2  3  11
 4  3  12
 1  2  13
 0  3  15
 1  3  19
 0  1  20
 0  2  22
 1  4  26
 0  4  28
 2  4  30

Arvore geradora minima
 2  3  11
 4  3  12
 1  2  13
 0  3  15

```

## Todas as árvores geradoras de um grafo

Primeiramente se faz necessário compilar os arquivos fontes que serão utilizados para encontrar as árvores geradoras, o que pode ser conseguido fazendo:

```console
user@computer:~/sapanningTrees $ cd src
user@computer:~/sapanningTrees/src $ make spanningTrees
```

Para obter as árvores geradoras de um grafo execute o comando a seguir substituindo **graph** pelo caminho de uma instância de grafo e **output** por *stdout* se desejar que o resultado seja emcaminhado para a saída padrão ou *arquivo* se desejar que a saída seja escrita em um arquivo:

```console
user@computer:~/sapanningTrees/src $ ./spanningTrees.out graph output
```

Caso escolha *stdout* será mostrado algo semelhante à:

```text
Obtendo todas as arvores geradoras para
 0  1  95
 0  2  86
 1  3  79
 2  3  75


c[s(P)] = 240
 2  3  75
 1  3  79
 0  2  86


c[s(P)] = 249
 2  3  75
 1  3  79
 0  1  95


c[s(P)] = 256
 2  3  75
 0  2  86
 0  1  95


c[s(P)] = 249
 2  3  75
 0  1  95
 1  3  79
```

Já caso escolha *arquivo* será mostrado algo semelhante à:

```text
Arvores geradoras serao salvas no arquivo allSpanningTrees

Obtendo todas as arvores geradoras para
 0  1  95
 0  2  86
 1  3  79
 2  3  75
```
