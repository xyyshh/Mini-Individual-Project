import networkx as nx
import matplotlib.pyplot as plt

file = input("please enter the number of the file to visualize (001 to 200): ")
file = 'result/' + file + '.txt'
f = open(file, 'r')

n = eval(f.readline())
nodes = []
edges = []

for i in range(n):
    nodes.append(str(i+1))

for i in range(n):
    g = f.readline()
    g = g.split(' ')
    for j in range(n):
        if g[j] == '1' and i != j:
            edges.append((str(i+1), str(j+1)))

G=nx.Graph()

for node in nodes:
    G.add_node(node)

G.add_edges_from(edges)

nx.draw(G, with_labels=True,node_color='y')
plt.show()
