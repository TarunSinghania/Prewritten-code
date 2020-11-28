//centriod decomposition
//n log^2n
#include <bits/stdc++.h> 
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define pb push_ba  ck
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define fillm(m,r,c,k) fr(i,0,r)fr(j,0,c)m[i][j]=k;
#define prm(m,r,c) fr(i,0,r){fr(j,0,c){cout<<m[i][j]<<" "; }cout<<endl;}
#define pr(a,n)fr(i,0,n)cout<<a[i]<<",";cout<<endl;
#define endl '\n'
#define MOD 1000000007
#define INF 1000000000
#define prv(v) for(auto x: v)cout<<x<<" ";cout<<endl;
#define MAX 100005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define f first
#define s second
set<pair<int,int> > adj[MAX];
ll ans = 0;
int n;int k;
int sz[MAX];
map<int,int> paths;
map<int,int> tpaths;
int dad[MAX];
int dfssz(int u,int p = -1){
    sz[u] = 1;
    for(auto x : adj[u]){
        if(x.f==p)continue;
        sz[u] += dfssz(x.f,u);  
    }
    return sz[u];
}
int getcentriod(int u,int p,int n){
    for(auto x: adj[u]){
        if(x.f != p && sz[x.f] > n/2){
            return getcentriod(x.f,u,n);
        }
    }
    return u;
}
void dfscalc(int v,int p,int d){
    tpaths[d]++;
    for(auto x: adj[v]){
        if(x.f!=p)
        dfscalc(x.f,v,d+x.s);
    }
}
void conquer(int n){
        for(auto v: adj[n]){
            dfscalc(v.f,n,v.s);
            for(auto x: tpaths){
                if(x.f==k)
                    ans = ans + x.s;
                if(paths.find(k-x.f)!=paths.end())
                ans = ans + (x.s*paths[k-x.f]);
            }
            for(auto x: tpaths)
                paths[x.f]+=x.s;
            tpaths.clear();
        }
        paths.clear();
}
void divide(int v,int p = -1){
    int n = dfssz(v);
    int c = getcentriod(v,-1,n);
    dad[c]=p;
    conquer(c);
    vector<pair<int,int> > tmp(adj[c].begin(),adj[c].end()); 
    for(auto v : tmp){
        adj[v.f].erase({c,v.s});
        adj[c].erase({v.f,v.s});
        divide(v.f);
    }
}
void decompose(int v){
    divide(1,-1);
}

main(){
    cin>>n>>k;
    fr(i,0,n){
        int u,v;
        int w  = 1;
        cin>>u>>v;
        adj[u].insert({v,w});
        adj[v].insert({u,w});
    }   
    decompose(1);
    cout<<ans<<endl;
}