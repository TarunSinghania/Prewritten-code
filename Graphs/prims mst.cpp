Kruskal is faster when you have sparse graphs (graphs with a low number of edges), 
and Prim's will be faster in dense graphs (lots of edges).

 However notice, you will only get the full potential for Prim's alg, 
 if you use a Fibonacci heap. Using it you will have a runtime of O(E + V logV).