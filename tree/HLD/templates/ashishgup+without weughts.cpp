//clean
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
#define prv(v) for(auto x: v)cout<<x<<" ";cout<<endl;
#define MAX 400005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define f first
const int N = 5e5+5;
const int LG = log2(N) + 1;

int n, tim=0;
int a[N], level[N]; 
int tin[N], tout[N];//tin gives segment tree index for the ith tree node//tout gives the last index of the subtree of that node 
int treenode[N], head[N];
//tree node gives index for node of tree for ith locatin of segment tree
//head gives head of the current chain
int sz[N], parent[LG][N];
//question specific adj list,datastructures
vector<int> adj[N];



struct data
{
  //Use required attributes
  int mn;

  //Default Values
  data() : mn(0) {};
};
  vector<data> st;
  vector<bool> cLazy;
  vector<int> lazy;

  void init(int N)
  {
    st.resize(4 * N + 5);
    cLazy.assign(4 * N + 5, false);
    lazy.assign(4 * N + 5, 0);
  }

  
  //Write reqd merge functions
  void merge(data &cur, data &l, data &r) 
  {
    cur.mn = max(l.mn, r.mn);
  }
  
  //Handle lazy propagation appriopriately
  void propagate(int node, int L, int R)
  {
    if(L != R)
     {
       cLazy[node*2] = 1;
       cLazy[node*2 + 1] = 1;
       lazy[node*2] = lazy[node];
       lazy[node*2 + 1] = lazy[node]; 
    }
    //do work here in segment tree node then propagte values down
    st[node].mn = lazy[node];
    lazy[node] = 0;
    cLazy[node] = 0;//unset lazy too
  }

  void build(int node, int L, int R)
  {
    if(L==R)
    {
      st[node].mn = a[treenode[L]];
      return;
    }
    int M=(L + R)/2;
    build(node*2, L, M);
    build(node*2 + 1, M + 1, R);
    merge(st[node], st[node*2], st[node*2+1]);
  }

  data Query(int node, int L, int R, int i, int j)
  {
    if(cLazy[node])
      propagate(node, L, R);
    if(j<L || i>R)
      return data();
    if(i<=L && R<=j)
      return st[node];
    int M = (L + R)/2;
    data left=Query(node*2, L, M, i, j);
    data right=Query(node*2 + 1, M + 1, R, i, j);
    data cur;
    merge(cur, left, right);
    return cur;
  }

  data pQuery(int node, int L, int R, int pos)
  {
    if(cLazy[node])
      propagate(node, L, R);
    if(L == R)
      return st[node];
    int M = (L + R)/2;
    if(pos <= M)
      return pQuery(node*2, L, M, pos);
    else
      return pQuery(node*2 + 1, M + 1, R, pos);
  } 

  void Update(int node, int L, int R, int i, int j, int val)
  {
    //even when not in range prpagate because values being used bwhile merging
    if(cLazy[node])
      propagate(node, L, R);
    if(j<L || i>R)
      return;
    if(i<=L && R<=j)
    {
      cLazy[node] = 1;
      lazy[node] = val;
      propagate(node, L, R);//this seets clazy to zero 
      return;
    }
    int M = (L + R)/2;
    Update(node*2, L, M, i, j, val);
    Update(node*2 + 1, M + 1, R, i, j, val);
    merge(st[node], st[node*2], st[node*2 + 1]);
  }

  void pUpdate(int node, int L, int R, int pos, int val)
  {
    if(cLazy[node])
      propagate(node, L, R);
    if(L == R)
    {
      cLazy[node] = 1;
      lazy[node] = val;
      propagate(node, L, R);
      return;
    }
    int M = (L + R)/2;
    if(pos <= M)
      pUpdate(node*2, L, M, pos, val);
    else
      pUpdate(node*2 + 1, M + 1, R, pos, val);
    merge(st[node], st[node*2], st[node*2 + 1]);
  }

  data query(int pos)
  {
    return pQuery(1, 1, n, pos);
  }

  data query(int l, int r)
  {
    return Query(1, 1, n, l, r);
  }

  void update(int pos, int val)
  {
    pUpdate(1, 1, n, pos, val);
  }

  void update(int l, int r, int val)
  {
    Update(1, 1, n, l, r, val);
  }




//Heavy Light Decomposition

void dfs(int u, int par, int lvl)
{ 
  parent[0][u] = par;
  level[u] = lvl;
  for(auto it:adj[u])
  {
    if(it ==par)
      continue;
    dfs(it, u, lvl+1);
  }
}
void dfs1(int u, int par)
{
  sz[u] = 1;
  int bi = -1;
  int bs = 0;
  //withot & swap wont work properly
  for(int id = 0; id < adj[u].size() ; id++)    
  {
    auto it = adj[u][id];
    if(it==par)
      continue;
    dfs1(it, u);
    sz[u] += sz[it];
    if(sz[it] > bs)
      bs = sz[it],bi =id; 
  }
  if(bi>0)
  swap(adj[u][0], adj[u][bi]);
}
void dfs_hld(int u, int par)
{
  tin[u] = ++tim;
  treenode[tim] = u;
  for(auto v :adj[u])
  {
    if(v==par)
      continue; 
    head[v] = (v==adj[u][0] ? head[u]:v);
    dfs_hld(v, u);
  }
  tout[u] = tim;
}

//LCA

int walk(int u, int h)
{
  for(int i=LG-1;i>=0;i--)
  {
    if((h>>i) & 1)
      u = parent[i][u];
  }
  return u;
}

void precompute(int n)
{
  for(int i=1;i<LG;i++)
    for(int j=1;j<=n;j++)
      if(parent[i-1][j])
        parent[i][j]=parent[i-1][parent[i-1][j]];
}

int LCA(int u, int v)
{
  if(level[u]<level[v])
    swap(u,v);
  int diff=level[u]-level[v];
  for(int i=LG-1;i>=0;i--)
  {
    if((1<<i) & diff)
    {
      u=parent[i][u];
    }
  }
  if(u==v)
    return u;
  for(int i=LG-1;i>=0;i--)
  {
    if(parent[i][u] && parent[i][u]!=parent[i][v])
    {
      u=parent[i][u];
      v=parent[i][v];
    }
  }
  return parent[0][u];
}

int dist(int u, int v)
{
  return level[u] + level[v] - 2 * level[LCA(u, v)];
}

void upd(int l, int r, int val)
{
  //cout<<"upd"<<l<<r<<val<<endl;
  update(l, r, val);
}

int get(int l, int r)
{
  return query(l, r).mn;
}

void subtree_update(int n){
  int l = tin[n];
  int r = tout[n];
  update(l,r,1);
}


//Utility Functions
int go_up(int u,int h){
  //rise h hieght above where 0 returns same node
  while(level[u]-level[head[u]]<h && head[u]!=0){
    h -=  level[u] - level[head[u]];
    u = parent[0][head[u]];
    h =h - 1;
  }
  //int r = tin[u] - tin[head[u]];
  //  int find = tin[head[u]] + (r-h);
  int find = tin[u] - h;
  return query(find).mn;
}


int query_up(int x, int y) //Assuming Y is an ancestor of X
{
 //int res = 0;
  int res = 0;
  while(head[x] != head[y])
  {
    //res += get(tin[head[x]], tin[x]);
    res = max(res,get(tin[head[x]], tin[x]));
    x = parent[0][head[x]];
  }
  res = max(res,get(tin[y]+1, tin[x]));
  //res += get(tin[y] + 1, tin[x]); //use tin[y] to include Y
  return res;
}


int query_hld(int x, int y)
{
  int lca = LCA(x, y);
  int res = max(query_up(x, lca),query_up(y, lca));
  return res;
}

void update_up(int x, int y, int val) //Assuming Y is an ancestor of X
{
  while(head[x] != head[y])
  {
    upd(tin[head[x]], tin[x], val);
    x = parent[0][head[x]];
  }
  upd(tin[y], tin[x], val); //use tin[y]+1 to not include Y
 //upd(tin[y] + 1, tin[x], val); //use tin[y] to include Y
}
void root_update(int n){
  update_up(n,1,0);
} 
void update_hld(int x, int y, int val)
{
  int lca = LCA(x, y);
  update_up(x, lca, val);
  update_up(y, lca, val);
}
void hld(int n)
{
   dfs(1, 0, 1);
   dfs1(1, 0);
   dfs_hld(1, 0);
   precompute(n);
   init(n);
   build(1, 1, n);
}
void clear(int v){
  tim = 0;
  fr(i,1,v+1)
  { 
    a[i]=0;level[i]=0;tin[i]=0;tout[i]=0;treenode[i]=0;head[i]=0;
    sz[i]=0;
    adj[i].clear();
    fr(j,0,LG)
      parent[j][i]=0;
  }
}
int main(){
 speed;
 int t=1;
 //cin>>t;
 while(t--){
  int v;
  cin>>v;
  n = v;
  fr(i,1,v)
  {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);adj[y].pb(x);
  }
  hld(v);
  int q;
  cin>>q;
  // fr(i,1,n+1){
  //  cout<<i<<" "<<tin[i]<<endl;
  // }
  fr(i,1,q+1){
    int t,n;
    cin>>t>>n;
    if(t==1){
      //fill
      subtree_update(n);
    }
    else if(t==2){
      //empty
      root_update(n); 
    }
    else{
      // fr(i,1,v+1){
      //  cout<<i<<" "<<query(tin[i]).mn<<endl;
      // }
      cout<<query(tin[n]).mn<<endl;
    }
  }
  //clear(v);
  }
}
  

