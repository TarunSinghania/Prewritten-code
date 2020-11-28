void shotestpath(int start,int v){
	
	
	int dist[v+1]={INF};

	queue<int> q;
	dist[start]=0;
	q.push(0);
	while(!q.empty())
	{	
		int node =q.top();
		q.pop();
		fr(i,0,adj[node].size())
		{
			if(adj[node][i]!=INF)
			{
				dist[adj[node][i]]=dist[node]+1;
				q.push(adj[node][I])
			}
		}
	}
	//all minimum ditsances calculated
}