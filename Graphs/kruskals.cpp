#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define pb push_back
#define ll long long
#define mkp make_pair 
#define MAX 100005
#define MAX_LOG 25
#define INF 10000000000000
#define pr(a,b) fr(i,0,b){cout<<a[i]<<" ";}cout<<endl;
#define prs(s) for(auto x : s){cout<<x.first<<"#"<<x.second<<" ";}cout<<endl;
#define all(x)           x.begin(), x.end()
 
int v,e;
ll tw;
vector<pair<int,int> > adj[MAX];
vector<pair<int,int> > mstree[MAX];
vector<pair<int, pair<int,int> > > edges;
int Arr[MAX];
int size[MAX];
 
void initialize(int N)
{
    for(int i = 0;i<N;i++)
    {
        Arr[ i ] = i ;
        size[ i ] = 1;
    }
}
 
 
int root(int i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ; 
        i = Arr[ i ]; 
    }
    
    return i;
}
 
 
 
void weighted_union(int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
 
      //cout<<root_A<<"--"<<root_B<<endl;
  if(root_A == root_B)
    {
    return;
    }
    if(size[root_A] < size[root_B ])
    {
    Arr[ root_A ] = Arr[root_B];
    size[root_B] += size[root_A];
    }
    else
    {
    Arr[ root_B ] = Arr[root_A];
    size[root_A] += size[root_B];
    }
 
}
 
 
bool find(int A,int B)
{
    if( root(A)==root(B) )       //if A and B have the same root, it means that they are connected.
    return true;
    else
    return false;
}
 
 
void kruskal()
{
    sort(all(edges));
    fr(i,0,(int)edges.size())
    { 
        int w = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second; 
        if(!find(a,b))
        {
          weighted_union(a,b);
          mstree[a].pb(mkp(b,w));
          mstree[b].pb(mkp(a,w));
          tw = tw + 1LL*w;
        }
    }
} 
 
int main()
{
    cin>>v>>e;
    initialize(v+1);
    fr(i,0,e)
    {   
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].pb(mkp(y,w));
        adj[y].pb(mkp(x,w));
        edges.pb(mkp(w,mkp(x,y)));
    }
    kruskal();
    cout<<tw<<endl;    
    
    
 
 
 
}               
 
 
// differenece between djisktra and mst 
// observe case 
// 5
// 1 2 30
// 2 3 20
// 1 4 3
// 4 5 40
// 5 3 10
//http://mxwell.github.io/draw-graph
//if you use djistra edge with weight 20 will be included
//mst it wont be included