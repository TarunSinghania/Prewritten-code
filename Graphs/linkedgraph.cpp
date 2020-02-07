#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for(int i =a ; i < b; i++)
#define mkp make_pair 
#define pb push_back
#define pii pair<int,int>
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)


//unidirected 
//addedge
//veector array passed as refernce by default use structure wrapper for by value
void ae(vector<int> v[] , int x ,int y){

  v[x].push_back(y);

}

void dfsu(int u ,vector<int> v[], vector<bool> &vis)
{
  vis[u] = true;
  cout<<u<<" ";

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
  std::vector<bool> visited(size+1,false) ;
  fr(i,1,size+1)
  if(visited[i]==false)
  dfsu(i,adj,visited);
}


void bfsu(int node ,vector <int> , vector<bool> &vis)
{

  visited[node] = true;
  queue<int> q ;
  q.push(node);

  while(!q.empty())
 {   int s = q.front();
    q.pop();
    for(auto i =adj[s].begin();i!=adj[s].end();++i)
    {
      if(!visited[*i])
      {
        visited[*i]=true;
        q.push(*i);
      }
    }
  }//bfs

}

void bfscomp(vector<int> adj[],int size)
{
  vector<bool> visited(size+1,false);
  fr(i,1,size+1)
  if(visited[i]==false)
  bfsu(i,adj,visited);
}


void idfsu(int node ,vector<int> adj[],vector< bool> &visited){


stack <int> s ;
s.push(node);

while(!s.empty())
  {
    node = s.top();
    s.pop();

    if(visited[node])
      continue;

    cout<<node<<" ";
    visited[node]= true;

    for(auto it = adj[node].begin(); it!= adj[node].end(); ++it)
      if(!visited[*it])
        s.push(*it);

    }

}

//complete iterative dfs 
void idfs(vector<int> adj[] , int size)
{

  vector<bool> visited (size+1,false);

  fr(i,1,size+1)
  if(visited[i]==false)
    idfsu(i,adj,visited);


}

//transpose graph
void ts(std::vector<int> adj[] ,std::vector<int> nw[], int size)
{
  size = size+1;
  //create vector<int> newone[size+1] and pass to funciton 
  fr(i,1,size)
    for(auto it = adj[i].begin(); it!= adj[i].end(); ++it)
      nw[*it].push_back(i);


}

//create stack
void crstutil(std::vector<int> adj[],stack<int> &s , int node, vector<bool> &vis)
{

  vis[node]= true;

    for(auto it = adj[node].begin(); it!= adj[node].end(); ++it)
          if(!vis[*it])
          crstutil(adj,s,*it,vis);

    s.push(node);


}

void crs(std::vector<int> adj[],stack<int> &s , vector<bool> &vis,int size)
{

  fr(i,1,size+1)
  if(vis[i]==false)
  crstutil(adj,s,i,vis);


}

void pr12(vector<int> t[],int size)
{
  fr(i,1,size){
  cout<<i<<"-->";
  for(auto it = t[i].begin(); it != t[i].end() ;++it)
  cout<<*it<<"-- ";
   cout<<endl;
  }


}

void scc(vector<int> adj[],int size)
{
  stack<int> s;
  vector<bool> visited (size+1,false);


  crs(adj,s,visited,size);

  vector<int> nw[size+1];

  ts(adj,nw,size);

 // pr12(nw,size+1);


  vector<bool> vin (size+1,false);

  while(!s.empty())
  {

      int v = s.top();
      s.pop();

      if(vin[v]==false)
        {
        dfsu(v,nw,vin);
        cout<<endl;
        }


  }

}




int main()
{
  int v = 8 ;
//linked list 
  vector<int> adj[v+1];



  ae(adj,1,2);
  ae(adj,2,3);
  ae(adj,3,4);
  ae(adj,4,1);
  ae(adj,2,5);
  ae(adj,5,6);
  ae(adj,5,8);
  ae(adj,8,7);
  ae(adj,7,5);

  dfscomp(adj,8);
  cout<<endl;
  //idfs(adj,8);
  scc(adj,8);





return 0 ;


}   