import io
import networkx as nx
import matplotlib.pyplot as plt
#input file
filename=("S1.txt")

f = io.open(filename, mode="r")
lines = f.read()
lines=lines.rstrip()
lines = lines.replace("	"," ")
lines = lines.split("\n",1)[1];
lines = lines.replace("\n"," ")

edges = []
edges = [int(i) for i in lines.split() if i.isdigit()] 

G = nx.DiGraph()

for i in range(0, int(len(edges)/2)):
    #print(str(edges[i*2]) + " " + str(edges[i*2+1]))
    G.add_edge(edges[i*2],edges[i*2+1])

nx.draw_shell(G, with_labels = True) 
plt.savefig("Graph.png")
plt.clf()

#output file
output_filename=("Q1_S1O.txt")

output_f = io.open(output_filename, mode="r")
lines = output_f.read()
lines=lines.rstrip()
lines = lines.replace("	"," ")
lines = lines.split("\n",1)[1];
lines = lines.splitlines();

for i in range (0, len(lines)) :
    lines[i] = [int(i) for i in lines[i].split() if i.isdigit()]
print("qwe")
for i in range (0, len(lines)) :
    subgraph = nx.DiGraph()
    for j in range(0, int(len(edges)/2)):
        subgraph.add_edge(edges[j*2],edges[j*2+1])
    subgraph = subgraph.subgraph(lines[i])
    nx.draw_shell(subgraph, with_labels = True)
    plt.savefig(str(i) + ".png")
    plt.clf()