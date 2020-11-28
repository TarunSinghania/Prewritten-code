#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define fre(i,a,b) for(int i =a ; i <= b; i++)
#define fra(s) for(auto it = s.begin(); it != s.end() ; ++it)

#define mkp make_pair 
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

 


void ae(vector<int> v[] , int x ,int y){
  v[x].push_back(y);
  v[y].push_back(x);
}

const int N = 100001 ;
int dfs[N],from[N],to[N];
int sz = 0 ;

//segment tree
void dfsu(int u ,vector<int> v[], vector<bool> &vis)
{
  vis[u] = true;
  dfs[++sz] = u ;
  from[u] = sz ;
  to[u] = sz ;
  for(int i = 0; i< v[u].size(); i++)
  {
    if(vis[v[u][i]]==false){
     dfsu(v[u][i],v,vis);
     to[u]= max( to[u], to[v[u][i]] ) ;
   }
  }

}

//one node dfs
void segmentree(vector<int> v[],int size)
{
  //taking 1 as root 
  std::vector<bool> visited(size+1,false) ;
  dfsu(1,v,visited);


}



int main()
{int v ;
  cin>>v;

  vector<int> adj[v+1];

int a,b;

fr(i,0,v-1)
  {
    cin>>a>>b;
    ae(adj,a,b);
  }


segmentree(adj,v); 


//fr(i,0,8)
//cout<<from[i]<<endl;


return 0 ;


}   