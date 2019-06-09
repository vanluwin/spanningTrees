from matplotlib import pyplot as plt
import networkx as nx
import argparse

def parse_args():
    parser = argparse.ArgumentParser(
        description='Plota um grafo a partir de um arquivo de instancia.'
    )

    parser.add_argument(
        'grafo', type=str,
        help='Caminho para o arquivo .in do grafo.'
    )

    return parser.parse_args()

if __name__ == '__main__':
    args = parse_args()

    # Instancia um grafo
    graph = nx.Graph()

    # Lê as arestas contidas no arquivo
    with open(args.grafo, 'r') as file:
        next(file)
        for line in file:
            line = line.split(" ")
            graph.add_edge(line[0], line[1], weight=int(line[2]))
    
    # Posiciona os vertices
    pos = nx.spring_layout(graph)

    nx.draw(graph, pos)

    labels = nx.get_edge_attributes(graph, 'weight')
    nx.draw_networkx_edge_labels(graph, pos, edge_labels=labels)

    nx.draw_networkx_labels(
        graph, pos, 
        font_size=10, font_family='sans-serif'
    )

    plt.axis('off')
    plt.show()