a Hamiltonian path (or traceable path) is a path in an undirected or directed graph that visits each vertex exactly once(unless specified not a cycle)

walk and path not same
walk and Hamiltonian path same
a walk is a path only which goes thorugh each vertex 

all questions about path can be solved for cycle by iterating  ?

A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian path that is a cycle

a simple path is a path in a graph which does not have repeating vertices. 





A Hamiltonian path visits every node (or vertex) exactly once, and a Eulerian path traverses every edge exactly once. 

An Euler path , in a graph or multigraph, is a walk through the graph which uses every edge exactly once. An Euler circuit is an Euler path which starts and stops at the same vertex.

//https://codeforces.com/blog/entry/337?
//to read simple cycles 
//to code existence of hamiltonaina cycle effecient version 	

A graph G=(V(G),E(G)) is considered Eulerian if the graph is both connected and has a closed trail (a walk with no repeated edges) containing all edges of the graph

Theorem 3.1 (Euler) nessecary and sufficient condition
A connected graph G is an Euler graph if and only if all vertices of
G are of even degree.


nessecity profff:Each  time  the  path  passes  through  a  vertex  it  contributes  two  to  the  vertex's  degree,
except the starting and ending vertices. If the path terminates where it started, it will contrib-
ute two to that degree as well

idea :
cosider complete graph of 5 vertices that means it has two Eulerian paths  1 2 3 4 5 1 using outer loop and one 1 3 5 2 4 1 using inner edges ... every eularian graph is made up of multiple 
	eularian circuit ..each circuit add an two to the number of degree to each vertice and hence each vertice will have two degree

sufficiency proof:
	?
		


Definition: A graph G=(V(G),E(G)) is considered Semi-Eulerian if it is connected and there exists an open trail containing every edge of the graph (exactly once as per the definition of a trail). You do not need to return to the start vertex.
Definition: A Semi-Eulerian trail is a trail containing every edge in a graph exactly once. A graph with a semi-Eulerian trail is considered semi-Eulerian.

A graph is semi-Eulerian if and only if there is one pair of vertices with odd degree


from proof of eularian circuit having all even degre vertices,the removal of a edge will make the it semi eularian and itnroduce two  odd degree vertices.



A cycle passing through all the vertices of a graph is called a
Hamiltonian cycle.A graphcontaining a Hamiltonian cycle is called a
Hamiltonian graph
.A path passing through all the vertices of a graph is called a
Hamiltonian path and a graph containing a Hamiltonian
path is said to be traceable.
