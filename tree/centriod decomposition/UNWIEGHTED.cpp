//centriod decomposition 
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
#define s second
set<int> adj[MAX];
set<int> cdtree[MAX];
int sz[MAX];
int root;
int dad[MAX];
int v;
int ans[MAX];
int dfssz(int a,int p= -1){
  sz[a]=1;
  for(auto x: adj[a]){
    if(x!=p)
      sz[a]+=dfssz(x,a);
  }
  return sz[a];
}
int getcentriod(int v,int p,int n){
  for(auto x: adj[v]){
    if(x!=p && sz[x] > n/2)
        return getcentriod(x,v,n);
  }
  return v;
}
void divide(int a,int p){
  int n = dfssz(a,p);
  int c = getcentriod(a,p,n);
  if(p!=-1){
  dad[c]= p;
  cdtree[p].insert(c);
  cdtree[c].insert(p);
  }
  else root = c;
  //conquer();
  vector<int> temp (adj[c].begin(),adj[c].end());
  for(auto x: temp){
    adj[x].erase(c);
    adj[c].erase(x);
    divide(x,c);
  }
}
void conquer(){

}
void decompose(){
  divide(1,-1);
}

void dfsans(int n,int p,int h){
  ans[n] = h;
  //cout<<n<<h<<endl;
  for(auto x: cdtree[n])
    if(x!=p)
      dfsans(x,n,h+1);
}
void print(){
  fr(i,1,v+1){
    cout<<((char)('A'+ans[i]))<<" ";
  }
}
main(){
  cin>>v;
  fr(i,0,v){
    int a,b;
    cin>>a>>b;
    adj[a].insert(b);
    adj[b].insert(a);
  }
    decompose();
    dfsans(root,-1,0);
    print();
}