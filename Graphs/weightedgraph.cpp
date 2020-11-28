#include <bits/stdc++.h>
//birdirectional weighted 
using namespace std;

#define fr(i,a,b) for(int i =a ; i < b; i++)
#define mkp make_pair 
#define pb push_back
#define pii pair<int,int>
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)


//unidirected 
//addedge
//veector array passed as refernce by default use structure wrapper for by value

int w[100001];  


void ae(vector<int> v[] , int x ,int y){

  v[x].push_back(y);
  v[y].push_back(x);
}

void dfsu(int u ,vector<int> v[], vector<bool> &vis)
{
  vis[u] = true;
cout<<u<<endl;
//can pass wiegth here directl global variable
  for(int i = 0; i< v[u].size(); i++)
  {
    if(vis[v[u][i]]==false)
      dfsu(v[u][i],v,vis);
  }

}

//one node dfs
void dfs(vector<int> v[],int node,int size)
{
  
  std::vector<bool> visited(size+1,false) ;
  dfsu(node,v,visited);


}
//all node dfs
void dfscomp(vector<int> adj[],int size)
{
//  std::vector<bool> (visited,false) ;
  std::vector<int>  tents;
  //to contain the node id
  std::vector<bool> visited(size+1,false) ;
  fr(i,1,size+1){
  if(visited[i]==false)
  {
    
    dfsu(i,adj,visited);
  }
}//for
  

}



main()
{
  int v, e;
  cin>>v>>e;

  
//linked list 
  vector<int> adj[v+1];

  fr(i,1,v+1)
  cin>>w[i];

  int u,b;
  fr(i,0,e)
  {
  cin>>u>>b;
  ae(adj,u,b);
  }
  
  

  dfscomp(adj,v);

  




}   