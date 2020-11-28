flyod warshall.cpp

			m
subproblem:d 	weight of shortest path u->v using <=m edges
			(uv) 

guessing: whats the last edge (x,v)
			  m        m-1
recurrence : d  = min(d   	+w(x,v))for all x in v
			(uv)		ux

for(0 edge m =0 )
			base duv = inf 
			pr duv = 0; if(u = v);


for m from 1 to n 
	for u in v 
		for v in v 
				for each x in v 

			  m        m-1
			d  = min(d   	+w(x,v))
			(uv)		ux



time o(v^4) space(v^3)



cheating :


	for m from 1 to n 
	for u in v 
		for v in v 
				for each x in v 

			         
			d  = min(d   	+d   )
			(uv)		ux    xv


time o(v^4) space(v^2)



dp(ii)--flyod warshall
vertives from 1 to n
			k
subproblem: c    weight of shortest path u-v whose intermediate of 1 to k;
			uv

guessing: use k in the path at all from u to v
			k 	  k-1     k-1
recurrence: c  = c    +  c                 	
			u-v   uk      kv

 0
c         = w(uv)
 uv 




 for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
  


for (k = 0; k < V; k++)  
    {  
        // Pick all vertices as source one by one  
        for (i = 0; i < V; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source  
            for (j = 0; j < V; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    } 


To find all vertice shortest cycle going through them.

Traditionally, you start path[i][i] = 0 for each i. But you can instead start from path[i][i] = INFINITY. It won't affect algorithm itself, as those zeroes weren't used in computation anyway (since path path[i][j] will never change for k == i or k == j).

In the end, path[i][i] is the length the shortest cycle going through i. Consequently, you need to find min(path[i][i]) for all i. And if you want cycle itself (not only its length), you can do it just like it's usually done with normal paths: by memorizing k during execution of algorithm