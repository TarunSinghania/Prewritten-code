#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define mkp make_pair 
#define pb push_back
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define sz 500;
#define ff first
#define ss second
#define MAX 100005
#define pr(a,n) fr(i,0,n){cout<<a[i]<<" ";}cout<<endl;
#define MAXBLOCKS 10000
#define all(x) x.begin(),x.end()

vector<int> adj[MAX];
int dfs[MAX];int from[MAX];int to[MAX];
bool vis[MAX];
int n;
int c = 0;
void f(int u)
{
  vis[u]=true;
  dfs[++c]=u;
  from[u]=c;
  to[u]=c;
  for(auto x: adj[u])
  {
 
    if(!vis[x]){
     // cout<<"pa"<<u<<"child"<<x<<endl;
      f(x);
      to[u]=to[x];
    }
  }
}
 
void inout(){
  fr(i,0,n+1)
    vis[i]=false;
  f(1);
 
}

 
int main() {
  speed; 
  cin>>n;
 
  fr(i,0,n-1) 
  {
    int x,y;
    cin>>x>>y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  inout();
  pr(dfs,n+1);
  pr(from,n+1);
  pr(to,n+1);

 
    return 0;
}