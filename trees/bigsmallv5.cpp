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
int cnt[MAX];
int col[MAX];
int sz[MAX];
bool big[MAX];

void getsz(int v, int p){
    sz[v] = 1;  // every vertex has itself in its subtree
    for(auto u : adj[v])
        if(u != p){
            getsz(u, v);
            sz[v] += sz[u];
        }
}


void add(int v, int p, int x){
  //  cout<<"Add called"<<v<<" "<<p<<" "<<x<<endl;
    cnt[ col[v] ] += x;
    for(auto u: adj[v])
        if(u != p && !big[u])
            add(u, v, x);
}
void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
   // cout<<"dfs"<<v<<" "<<p<<" "<<keep<<endl;
    for(auto u : adj[v])
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;

     // cout<<"bigChild"<<bigChild<<endl;
    for(auto u : adj[v])
        if(u != p && u != bigChild){
            dfs(u, v, 0);  
           } // run a dfs on small childs and clear them from cnt

    //cout<<"cleared"<<v<<endl;
    if(bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1;  // bigChild marked as big and not cleared from cnt

    add(v, p, 1);
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    //pr(cnt,n);
    if(v==1)
    {
      cout<<"cnt"<<cnt[1]<<endl;
    }


    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(v, p, -1);

    //cout<<"after"<<"dfs"<<v<<" "<<p<<" "<<keep<<endl;


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

