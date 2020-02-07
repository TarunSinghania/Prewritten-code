#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define ll long long
#define pb push_back
#define mkp make_pair
#define all(x)           x.begin(), x.end()

#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
//multiple edges //self loops handled
int n; // number of nodes
vector<int> adj[MAX]; // adjacency list of graph
vector<pair<int,int> > ans;
vector<bool> visited;
vector<int> tin, low;
//map<pair<int,int> ,int >edges;


int timer;
int time_;

void IS_BRIDGE(int a,int b)
{
    //cout<<a<<b<<endl;
    
//  if(edges[mkp(a,b)]==1)
    if(a>b)
        swap(a,b);
    ans.pb(mkp(a,b));

}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        //part of the tree 
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);
    for (int i = 1; i <= n; ++i) {
       if (!visited[i])
            dfs(i);

    }
}

void clear2()
{
    fr(i,1,n+1)
        adj[i].clear();

    ans.clear();
    //edges.clear();

}


int main()
{
    speed;
    int k;
    cin>>k;
    fr(i,1,k+1)
    {

    int m;

    cin>>n>>m;      
    clear2();
    fr(i,0,m)
    {
        int a,b;
        cin>>a>>b;
 // cout<<a<<b<<endl;
        // if(edges.find(mkp(a,b)) == edges.end()){
        // edges[mkp(a,b)]=1;
        // edges[mkp(b,a)]=1;
        // }
        // else{
        // edges[mkp(a,b)]++;
        // edges[mkp(b,a)]++;

        // }
         adj[a].pb(b);
         adj[b].pb(a);
    }
    find_bridges();
    //fr(i,1,n+1)
 //     cout<<tin[i]<<" ";
 //     cout<<endl;
    // fr(i,1,n+1)
 //     cout<<low[i]<<" ";
 //     cout<<endl;
    sort(all(ans));
    cout<<"Caso #"<<i<<endl;
    if(ans.size() == 0)
        cout<<"Sin bloqueos"<<endl;
    else
    {
        cout<<ans.size()<<endl;
        for(auto x: ans)
            cout<<x.first<<" "<<x.second<<endl;
    }

    }
}



