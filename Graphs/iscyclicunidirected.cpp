bool cyclicutil(vector<int> adj[], bool vis[],int v,int p){

	vis[v] = true;
	for(int i = 0 ; i<adj[v].size() ; i++ )
	{
		if(!vis[adj[v][i]]){
			if(cyclicutil(adj,vis,adj[v][i],v))
			 return true;}
		else{
	        if(adj[v][i] != p)
			return true;}
	}
	return false;

}

bool isCyclic(vector<int> adj[], int V)
{
	bool cyclic = true;
  bool vis[V+1]={false};
  for(int i = 0 ; i<V;i++)
	{
		if(!vis[i])
		{
			if(cyclicutil(adj,vis,i,-1) == true)
				return true;
}