//pizza/19
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
#define prv(v) for(auto x: v)cout<<x<<",";cout<<endl;
#define MAX 500005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
int n,m,x,y;

vector<int> adj[MAX];

//required always 
int sz[MAX];
int biggest[MAX];
bool big[MAX];
//required to save answers 
vector<pair<int,int> > q[MAX];
int ans[MAX];
//depends upon question
int col[MAX];
//countof each colour in the subtree
int cnt[MAX];


int preprocess(int u,int p){
  sz[u]=1;
  biggest[u]=-1;
  int __mx =0;
  for(auto x: adj[u]){
    if(x==p)continue;
    preprocess(x,u);
    sz[u]+=sz[x];
    if(sz[x]>__mx)
      biggest[u]=x,__mx = sz[x];
  }
}

void add(int u,int p,int val)
{
  //adding step
    cnt[ col[u] ] += val;
    for(auto x: adj[u])
    if(x!=p && !big[x])
      add(x,u,val);
}

void dfs(int v,int p,bool keep){
  for(auto x: adj[v])
  {
    //running dfs of small subtrees and erasing them it has no effect on the current nde
    if(x!=p && x!= biggest[v])
      dfs(x,v,0);
  }
  if(biggest[v]!=-1)
    dfs(biggest[v],v,1),big[biggest[v]] = 1;
  //bigChild marked as big and not cleared from cnt
  add(v,p,1);
  //traversing all nodes in all the small subtrees
  //now cnt has value
  //run your queries
  for(auto x: q[v])
  {
    ans[x.second]=cnt[x.first];
  }
  if(biggest[v]!=-1)
    big[biggest[v]]=0;
  //clear it as a big child as it can be a small for other nodes
  if(keep == 0)
        add(v, p, -1);
    //clear all nodes in small subtreess if not largest
}


main(){
  speed;
  cin>>n>>m;
  fr(i,2,n+1){
    cin>>x>>y;
    adj[i].pb(x);adj[x].pb(i);
  }
  fr(i,1,n+1)
  { 
    cin>>col[i];
  }
  fr(i,0,m){
    cin>>x>>y;
    q[x].pb(mkp(y,i));
  }
  preprocess(1,0);
  dfs(1,0,1);
  fr(i,0,m)
  {
    cout<<ans[i]<<endl;
  }
}

// 6 1
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 1 1 1 1 1 1
// 1 1
