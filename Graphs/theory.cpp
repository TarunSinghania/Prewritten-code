

Cycles 

unidirected 

can be used with self loops,
however if parallel edges exist will fail
use disjoint adjoint sets  (O(E)) 
 		can use with self loops too
 		if any self loop then cycle exist ....
 			self loop means 0---0 both have same root can be put 


 with selp loops,parallel edges 
 		execute dfs on graph
 		if thhere is a back edge,except parent then loop 


       
directed 
	
	dfs modified

































Shortest path

SITUation 		algo 	 	time

unwiegthed		BFS			O(v+e) use queue
(w=1)

no negative
edge wieghts   Djisktra		o(VLOGV +E) using fibonnaci heap other heap worse
							O((v+e) log E) USING PRIORITY QUEUE //DECREASE KEY LOGN
							O((v+e) log V) USING PRIORITY QUEUE //DECREASE KEY LOGN



Negative 
edge 			Bellman Ford  O(VE)


DAG				top sort + 1 round of bellmanford  O(V+E)


All pair shortest path 



SITUation 		algo 	 	time

unwiegthed		v*BFS			Ov*(v+e) = O(VE) =O(V^3)
(w=1)

no negative
edge wieghts    v*Djisktra		oV*(VLOGV +E) using fibonnaci heap other heap worse =O(V^3)

Negative 
edge 			v*Bellman Ford  Ov*(VE)  =O(v^4)




All pair shortest path 


unwiegthed		
(w=1)

no negative
edge wieghts    

Negative 
edge 			JOHNSON  O(V^2LOGV + VE)  =O(v^3)



all pair shortest path 

naive algo 

for m = 1 to n−1 
	do for i = 1 to n
	 	do for j = 1 to n 
	 		do min = ∞;
	 		for k = 1 to n 
	 			do new = d(m−1) ik + wkj; 
	 			if new < min then min = new 
	 			end 
	 		end
	 		d(m) ij = min; 
		 end 
	 end 
end

if no negative wieght cycles 
	or else after running  no dv(m-1);
0(V^4)




use this with matrix exponentiation = (V^3)logV


use flyod warsall --- 0(v^3);




















all paths from source to dest

BFS 

create a queue which will store path(s) of type vector
initialise the queue with first path starting from src

Now run a loop till queue is not empty
   get the frontmost path from queue
   check if the lastnode of this path is destination
       if true then print the path
   run a loop for all the vertices connected to the
   current vertex i.e. lastnode extracted from path
      if the vertex is not visited in current path
         a) create a new path from earlier path and 
             append this vertex
         b) insert this new path to queue

also memory exceeds
also multiple edged between 2 node will lead to diplicates



dfs

	vector<int> adj[v+1];
	int start;
	int end;
	vis[v+1]=false;
	vector<vector<int> > ans;
	dfs(vector<int> path){
		int last = path[path.size()-1];
		vis[last]=true;

		if(last==end)
			ans.pb(Path);
		else 
		{
			fr(i,0,adj[last][i])
			{
				if(!vis[adj[last][i]])
				{	vector<int> p = path;
					p.pb(adj[last][i]])
					dfs(p);
				}
			}
		}

		vis[last]=true;
	}



when dfs runs it ctreates tree like in memory memory limit exceedx
