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
#define MAX 200005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define f first
#define s second
//article link
//https://codeforces.com/topic/76681/en17
// problem calculate subtree size for each node , (taking each node as a root once)
int n;
int N;
ll c[MAX];
vector<int> adj[MAX];
ll sz[MAX];
ll ans;
void dfs(int n,int p){
  //change acording to question
  sz[n]+=1;
  for(auto x : adj[n]){
    if(x!=p){
        dfs(x,n);
        sz[n] += sz[x];
    }
  }
}
void reroot(int n,int p){
  //when we enter this function the dp corresponds to root being at n
 // ans = max(ans,dp[n]);
  fr(i,1,N+1)
  cout<<i<<" "<<sz[i]<<endl;

  for(auto to: adj[n]){
      if(to == p)continue;  
      //first modify state of the current node
      ll sub = sz[to];
      sz[n] -= sub;
      //now change the state of outgoing node

      //handle n as if it was the child of out going child 
      ll add = sz[n];
      sz[to] += add;
      // to check the algo is correct verify output of first child of first root
      reroot(to,n); 
      //just put reverse here
      sz[to] -= add;
      sz[n] += sub;
  }
}

int main(){

  cin>>n;
  N = n;
  fr(i,0,n-1){
    int u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(1,0);
  reroot(1,0);
  cout<<ans<<endl;
  return 0;
} 