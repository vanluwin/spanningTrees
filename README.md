# Uma implementação do algoritmo de Sorensen and Janssens

Implementações realizadas durante a disciplina DCA0214 - Estrutura de dados no semestre 2019.1

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
user@computer:~/sapanningTrees/scripts $ python3 grafo
```

## Árvores geradoras

Primeiramente se faz necessário compilar os arquivos fontes que serão utilizados para encontrar as árvores geradoras, o que pode ser conseguido fazendo:

```console
user@computer:~/sapanningTrees $ cd src
user@computer:~/sapanningTrees/src $ make
```

Para obter as melhores árvores geradoras de um grafo execute o comando a seguir substituindo **graph** pelo caminho de uma instância de grafo:

```console
user@computer:~/sapanningTrees/src $ ./spanningTrees.out graph
```
