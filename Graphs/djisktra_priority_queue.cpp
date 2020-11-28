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
#define maxv 100001
int parent[maxv] = {-1};
void ae(vector<pair<int,int> > v[] , int x ,int y ,int w){

  v[x].push_back(mkp(y,w));
  v[y].pb(mkp(x,w));

}
void dijkstra(int v, vector<pair<int,int> > adj[],int start)
{
  bool vis[v+1] ={false};
  long long dis[v+1];
  fill(dis,dis+v+1,LONG_LONG_MAX);
  dis[start] = 0;
  priority_queue<pair<ll,int> >q;
  q.push(mkp(0,start));

  while(!q.empty())
  {
    pair<int,int> p = q.top();
    q.pop();
    //here second stroing in pq first weight then vertice
    //not sute VlogE FOR eachverite + ElogE decreasekey is basically add ket(eachedge getting inside queue log E)
    int x = p.second;
    if(vis[x])
      continue;
    vis[x] = true;
    int e, w;
    fr(i,0,adj[x].size())
      { e = adj[x][i].first; w = adj[x][i].second;
        if(dis[e] > dis[x] +w )
          parent[e] = x,dis[e] = dis[x]+w,q.push(mkp(-dis[e],e));
      }
}


}

int main()
{
  speed;

  int v,edges;
  cin>>v>>edges;

  //linked list 
  vector<pair<int,int> > adj[v+1];

int a ,b,w;
  fr(i,0,edges){
  cin>>a>>b>>w;
  ae(adj,a,b,w);
}
//prw(adj,v);

  int s =1;
  dijkstra(v,adj,s);
    
    vector<int> path;
    int i = v;
    bool flag = false;
    while(i!=1){
       
        path.push_back(i);
        i = parent[i];
        if(i== -1 && i != 1)
        {flag = true;goto h;}
    }
    path.push_back(1);
    for(auto it = path.rbegin();it!=path.rend();it++)
        cout<<*it<<" ";

    if(flag)
    {    h:
    cout<<"-1"<<endl;
    return 0 ;
    }

return 0 ;


}   