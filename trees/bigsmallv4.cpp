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
//n logn instead of making nlog^2n
vector<int> vec[MAX];
int cnt[MAX];
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

void dfs(int v, int p, bool keep){
    
    int mx = -1, bigChild = -1;

    for(auto u : adj[v])
       if(u != p && sz[u] > mx)
           mx = sz[u], bigChild = u;
    
    for(auto u : adj[v]){
        //here doing dfs of non big childs before big child is important as the bigchild ones do not clear the cnt array,after every non big child the cnt is cleared
       if(u != p && u != bigChild)
           dfs(u, v, 0);
    }
    
    if(bigChild != -1)
        dfs(bigChild, v, 1), swap(vec[v],vec[bigChild]);
    
    vec[v].push_back(v);
    cnt[col[v]]++;
    
    for(auto u : adj[v])
       if(u != p && u != bigChild)
           for(auto x : vec[u]){
               cnt[ col[x] ]++;
               vec[v].push_back(x);
           }
    
    
    if(keep == 0){
        for(auto u : vec[v])
            cnt[ col[u] ]--;
        //clearing col when moving out of an non big node
        //so that fresh calculstions of the other node dfs
        //the big node is node cleared as its values are directly used  
    }

    if(v==1){
        prv(vec[1]);
        cout<<cnt[1]<<endl;
      }
    //// note that in this step *vec[v] contains all of the subtree of vertex v.
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
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
  dfs(1,0,1);
}

