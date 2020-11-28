//pizza/17
#include <bits/stdc++.h> 
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define fillm(m,r,c,k) fr(i,0,r)fr(j,0,c)m[i][j]=k;
#define prm(m,r,c) fr(i,0,r){fr(j,0,c){cout<<m[i][j]<<" "; }cout<<endl;}
#define pr(a,n)fr(i,0,n)cout<<a[i]<<",";cout<<endl;
#define endl '\n'
#define MOD 1000000007
#define INF 1000000000
#define prv(v) for(auto x: v)cout<<x<<" ";
#define MAX 123459
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
int n,m;
vector<int> adj[MAX];
int edges[MAX];
int dis[MAX];


int populateedgecount(int node,int p){

    for(auto x: adj[node])
    {
      if(x!=p)
      {
        populateedgecount(x,node);
        edges[x]++;
        edges[node]++;
      }
    }
}


pair<int,int> centers(int node){
  populateedgecount(node,0);

  queue<pair<int,int> > q;
  fr(i,1,n+1)dis[i]=0;
  fr(i,1,n+1)
  {
    if(edges[i]==1){
      q.push(mkp(i,1));
      dis[i]=1;
    }
  }
  int c1 = -1;int c2 =-1;
  while(!q.empty())
  {
    int t = q.front().first;
    int d =  q.front().second;
    for(auto x : adj[t])
    {
      if(dis[x]==0)
      {
        edges[x]--;
         if(edges[x]==1)
          q.push(mkp(x,d+1)),dis[x]=d+1;
      }
    }
    c2 =c1;
    c1 =t;
    q.pop();
  }
  if(c1==-1){
    //tree with one node
    c1  = node;
  }
  if(dis[c1]==dis[c2])
    return mkp(c1,c2);
  else
    return mkp(c1,-1);
}


main(){
  speed;
  cin>>n>>m;
  fr(i,0,n-1)
  {
    int u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
 
  pair<int,int> c =  centers(1);
  cout<<c.first<<c.second<<endl;
}
