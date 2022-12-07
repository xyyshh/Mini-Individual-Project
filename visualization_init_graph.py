import networkx as nx
import matplotlib.pyplot as plt

file = input("please enter the number of the file to visualize (001 to 200): ")
file = 'exact/exact' + file + '.gr'
f = open(file, 'r')

line = f.readline()
line = line.split(' ')
n = eval(line[2])
m = eval(line[3])
nodes = []
edges = []

for i in range(1, n+1):
    nodes.append(str(i))

for i in range(m):
    line = f.readline()
    line = line.split(' ')
    line[1] = line[1].split('\n')
    edges.append((line[0], line[1][0]))

G=nx.Graph()

for node in nodes:
    G.add_node(node)

G.add_edges_from(edges)

nx.draw(G, with_labels=True,node_color='y')
plt.show()
