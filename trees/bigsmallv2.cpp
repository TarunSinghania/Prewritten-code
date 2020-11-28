//pizza/18
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
#define MAX 100005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long

int n;
vector<int> adj[MAX];
map<int, int> cnt[MAX];
int col[MAX];
int sz[MAX];

void getsz(int v, int p){
    sz[v] = 1;  // every vertex has itself in its subtree
    for(auto u : adj[v])
        if(u != p){
            getsz(u, v);
            sz[v] += sz[u];
        }
}

void dfs(int v, int p){

    int mx = -1, biggest = -1;

    for(auto u : adj[v])
       if(u != p){
           dfs(u, v);
           if(sz[u] > mx)
               mx = sz[u], biggest = u;
       }

    if(biggest != -1){
        swap(cnt[v],cnt[biggest]);
    }

    cnt[v][ col[v] ]++;

    for(auto u : adj[v])
       if(u != p && u != biggest){
           for(auto x : cnt[u]){
               cnt[v][x.first] += x.second;
            }
            //you cal clear cnt[u] too if you wish to save some memory 
       }

      if(v==2)
      {
        cout<<cnt[v][1]<<endl; 
      }
    //now (*cnt[v])[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily but only at that stage of traversal
}



main(){
  speed;
  cin>>n;
  
  fr(i,0,n-1)
  {
    int u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  fr(i,1,n+1)
  { 
    cin>>col[i];
  }
  getsz(1,0);
  dfs(1,0);
}

