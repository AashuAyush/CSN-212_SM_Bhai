from collections import defaultdict
import timeit

class Graph:

    def __init__(self,vertices):
        self.V= vertices 
        self.graph = [] 
        
    def addEdge(self,v1,v2,w):
        self.graph.append([v1, v2, w])
         
    def printArr(self, minDistance):
        print("Vertex     Minimum Distance from Origin")
        for i in range(self.V):
            print("%d \t\t %d" % (i, minDistance[i]))

    def BellF(self, source):
        
        minDistance = [float("Inf")] * self.V
        minDistance[source] = 0
  
        for i in range(self.V - 1):        
            for v1, v2, w in self.graph:
                if minDistance[v1] != float("Inf") and minDistance[v1] + w < minDistance[v2]:
                        minDistance[v2] = minDistance[v1] + w

        for v1, v2, w in self.graph:
                if minDistance[v1] != float("Inf") and minDistance[v1] + w < minDistance[v2]:
                        print "Graph contains negative weight cycle"
                        return
                         
        self.printArr(minDistance)

v = input("Number of vertices:")
e = input("Number of edges:")
g = Graph(v)
for i in range (e):
    new_edge = raw_input()
    new_edge = new_edge.split()
    source=int(new_edge[0])
    destination=int(new_edge[1])
    cost=int(new_edge[2])
    g.addEdge(source,destination,cost)
    
start = timeit.default_timer() #start the time
g.BellF(0)
stop = timeit.default_timer() #stop the time
print stop - start
