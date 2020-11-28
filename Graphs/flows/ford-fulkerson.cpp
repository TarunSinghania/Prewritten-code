//resources go to 
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
#define MAX_N 100
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define f first
#define s second
struct Node
{
    vector<int> adj;
};
Node graf[MAX_N];
bool mark[MAX_N];
int cap[MAX_N][MAX_N];
int parent[MAX_N];

int v, e;
int s, t;

//Ford-Fulkersonov algoritam za nalazenje maksimalnog protoka izmedju dva cvora u grafu
//Moze se koristiti i za nalazenje maksimalnog matchinga
//Slozenost: O(E * maxFlow)
// to do add edmond karp template, dinic, push relabel template
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
        for (int i=0;i<graf[xt].adj.size();i++)
        {
            int xt1 = graf[xt].adj[i];
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

int main()
{
	cin>>v>>e;
	s = 1; t = v;
    for(int i  =0 ; i < e ; i++){
    	int u,v,c;
    	cin>>u>>v>>c;
    	graf[u].adj.pb(v);
    	graf[v].adj.pb(u);
    	cap[u][v] = c;
    }
    printf("%d\n",FordFulkerson());
    
    return 0;
}
