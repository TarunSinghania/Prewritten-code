https://cses.fi/problemset/task/1696/

//n boys and m girls assign max pair

//resources go to 
//tested at https://cses.fi/problemset/task/1695/
//https://cp-algorithms.com/graph/edmonds_karp.html
//https://www.youtube.com/watch?v=dorq_YA6plQ&list=PLEGCF-WLh2RJh2yDxlJJjnKswWdoO8gAc&ab_channel=TimRoughgardenLectures
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
#define MAX_N 1100
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define f first
#define s second
vector<int> adj[MAX_N];
bool mark[MAX_N];
int cap[MAX_N][MAX_N];
int parent[MAX_N];
int n, m;
int v, e;
int s, t;
//Ford-Fulkersonov algoritam za nalazenje maksimalnog protoka izmedju dva cvora u grafu
//Moze se koristiti i za nalazenje maksimalnog matchinga
//Slozenost: O(E * maxFlow)
// to do add dinic, push relabel template
inline int DFS()
{
    int ret = 0;
    for (int i=1;i<=v;i++) parent[i] = 0;
    stack<int> dfs_stek;
    stack<int> minCapacity;
    parent[s] = -1;
    dfs_stek.push(s);
    minCapacity.push(INF);
    while (!dfs_stek.empty())
    {
        int xt = dfs_stek.top();
        int mt = minCapacity.top();
        dfs_stek.pop();
        minCapacity.pop();
        if (xt == t)
        {
            ret = mt;
            break;
        }
        for (int i=0;i<adj[xt].size();i++)
        {
            int xt1 = adj[xt][i];
            if (cap[xt][xt1] > 0 && parent[xt1] == 0)
            {
                dfs_stek.push(xt1);
                minCapacity.push(min(mt,cap[xt][xt1]));
                parent[xt1] = xt;
            }
        }
    }
    if (ret > 0)
    {
        int currNode = t;
        while (currNode != s)
        {
 
            cap[parent[currNode]][currNode] -= ret;
            cap[currNode][parent[currNode]] += ret;
            currNode = parent[currNode];
        }
    }
    return ret;
}
 
inline int FordFulkerson()
{
    int flow = 0;
    while (true)
    {
        int currFlow = DFS();
        if (currFlow == 0) break;
        else flow += currFlow;
    }
    return flow;
}
set<int> scut,tcut;
 
void bfs(int s){
    vector<bool>  vis(v+1,false);
    queue<int> q;
    vis[s] = true;
    q.push(s);
    fr(i,1,v+1){
        tcut.insert(i);
    }
    while(!q.empty()){
        int node = q.front();
        scut.insert(node);
        tcut.erase(node);
        q.pop();
        for(auto x : adj[node]){
            if(cap[node][x] > 0 && vis[x] != true){
                vis[x] = true;
                q.push(x);
            }
        }
    }
}
 
 
int main()
{
    cin>>n>>m>>e;
    v = n + m + 2;
    s = 1;
    t = v;
    fr(i,1,n+1){
        adj[1].pb(1+i);
        adj[1+i].pb(1);
        cap[1][1+i] = 1;
    }
    fr(i,1,m+1){
        adj[t].pb(1+n+i);
        adj[1+n+i].pb(t);
        cap[1+n+i][t]=1;
    }
    set<pair<int,int> > duplicates;
    for(int i  =0 ; i < e ; i++){
        int u,v,c;
        cin>>u>>v;
        if(duplicates.find({u,v})!=duplicates.end())
            continue;
        duplicates.insert({u,v});
        u = 1 + u;
        v = 1 + n + v;  
        adj[u].pb(v);
        adj[v].pb(u);
        cap[u][v]=1;
        cap[v][u]=0;
    }
    cout<<FordFulkerson()<<endl;
    for(int i = n + 1 + 1 ; i <= n + 1 + m ; i++){
        for(auto j : adj[i])
        {
            if(cap[i][j] > 0 && j!=t){
                cout<<j-1<<" "<<i-n-1<<endl;
            }
        }
    }
        // bfs(s);
        // for(auto x: scut){
        //     for(auto y : adj[x]){
        //         if(tcut.find(y)!=tcut.end()){
        //             cout<<x<<" "<<y<<endl;
        //         }
        //     }
        // }
    return 0;
}