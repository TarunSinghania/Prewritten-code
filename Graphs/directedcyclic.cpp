#define fr(i,a,b) for(int i =a ; i < b; i++)
bool dfsu(int j,int col[],vector<int> adj[])
{
    col[j]=1;
    for(auto x : adj[j])
    {
        if(col[x] == 1)
            return true;
        if(col[x] == 0){
            if(dfsu(x,col,adj))
                return true;
        }
    }
    col[j]=2;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    int colour[V+1]={0};
    
    fr(i,0,V)
    {
        if(colour[i]==0)
            if(dfsu(i,colour,adj))
                return true;
    }
      
    return false;
}
