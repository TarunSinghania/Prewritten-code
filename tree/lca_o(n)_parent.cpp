#include <bits/stdc++.h>

using namespace std;
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define pb push_back
#define mkp make_pair 
#define MAX 100005
#define INF 1000000
#define pr(a,b) fr(i,0,b){cout<<a[i]<<" ";}cout<<endl;
int v;
vector<int> adj[MAX];
int p[MAX];

void parent(int n,int b){
    p[n]=b;
    for(auto x : adj[n])
        if(!p[x])
            parent(x,n);
}

int lca(int u,int v)
{
    bool vis[MAX];
    memset(vis,false,sizeof(vis));
    int lca;

    while(1){
        vis[u] = true ; 
        if(u == 1){
            break ; 
        }
        u = p[u] ; 
    }

    while(1){
        if(vis[v]){
            lca = v;    
            break ;  
        }
        v = p[v] ; 
    }
    return lca ; 

}
    
int main()
{
    cin>>v;
    fr(i,0,v-1)
    {   
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    parent(1,INF);
    pr(p,v+1);
    cout<<lca(4,3)<<endl;

}