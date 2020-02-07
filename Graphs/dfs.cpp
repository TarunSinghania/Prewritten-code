#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define fre(i,a,b) for(int i =a ; i <= b; i++)
#define fra(s) for(auto it = s.begin(); it != s.end() ; ++it)

#define mkp make_pair m
#define pb push_back
#define pii pair<int,int>
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define c(a,b) cout<<a<<"--"<<b<<endl;
#define frv(i,a,v) for(int i =  a ; i < v.size() ; ++i)
#define cp(a,i)  cout<<a[i].first<<" "<<a[i].second<<endl;
#define mp(a) cout<<a->first<<" "<<a->second<<endl;
//sum array
#define sa(n) int a[n]; int s[n];cin>>a[0];s[0]=a[0];fr(i,1,n) {cin>>a[i];s[i]=s[i-1]+a[i];}
#define sa1(n) int a[n+1]; long long s[n+1]; a[0]=0; s[0]=0;cin>>a[1];s[1]=a[1];fr(i,2,n+1) {cin>>a[i];\
s[i]=s[i-1]+a[i];}


#define MOD 1000000007

int v , wn;
int ans[100001];

void ae(vector<int> v[] , int x ,int y){
  v[x].push_back(y);
}

void dfsu(int u ,vector<int> v[], vector<bool> &vis)
{
  vis[u] = true;
  cout<<u<<" ";

  for(int i = 0; i< v[u].size(); i++)
  {
    if(vis[v[u][i]]==false)
      dfsu(v[u][i],v,vis);
  }

}

//one node dfs
void dfs(vector<int> v[],int node,int size)
{
  
  std::vector<bool> visited(size+1,false) ;
  dfsu(node,v,visited);


}
//all node dfs
void dfscomp(vector<int> adj[],int size)
{
//  std::vector<bool> (visited,false) ;
  std::vector<bool> visited(size+1,false) ;
  fr(i,1,size+1)
  if(visited[i]==false)
  dfsu(i,adj,visited);
}




int main()
{
  cin>>v>>wn;

  vector<int> adj[v+1];

int a,b;

fr(i,0,v-1)
  {
    cin>>a>>b;
    ae(adj,a,b);
  }


dfscomp(adj,v); 





return 0 ;


}   