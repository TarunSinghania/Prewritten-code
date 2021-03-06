#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
//https://codeforces.com/contest/546/problem/E
//Push-Relabel Algorithm for Flows, Complexity: O(V^2 √E)
//To obtain the actual flow values, look at all edges with capacity > 0
//Zero capacity edges are residual edges

struct edge
{
    int from, to, cap, flow, index;
    edge(int from, int to, int cap, int flow, int index):
        from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel
{
    static const long long INF=1e18;

    int n;
    vector<vector<edge> > g;
    vector<long long> excess;
    vector<int> height;

    PushRelabel(int n):
        n(n), g(n), excess(n), height(n) {}

    void addEdge(int from, int to, int cap)
    {
        g[from].push_back(edge(from, to, cap, 0, g[to].size()));
        if(from==to)
            g[from].back().index++;
        g[to].push_back(edge(to, from, 0, 0, g[from].size()-1));
    }

    void push(edge &e)
    {
        int amt=(int)min(excess[e.from], (long long)e.cap - e.flow);
        if(height[e.from]<=height[e.to] || amt==0)
            return;
        e.flow += amt;
        g[e.to][e.index].flow -= amt;
        excess[e.to] += amt;
        excess[e.from] -= amt;
    }

    void relabel(int u)
    {
        int d=2e5;
        for(auto &it:g[u])
        {
            if(it.cap-it.flow>0)
                d=min(d, height[it.to]);
        }
        if(d<INF)
            height[u]=d+1;
    }

    vector<int> find_max_height_vertices(int source, int dest)
    {
        vector<int> max_height;
        for(int i=0;i<n;i++)
        {
            if(i!=source && i!=dest && excess[i]>0)
            {
                if(!max_height.empty() && height[i] > height[max_height[0]])
                    max_height.clear();
                if(max_height.empty() || height[i] == height[max_height[0]])
                    max_height.push_back(i);
            }
        }
        return max_height;
    }

    long long max_flow(int source, int dest)
    {
        excess.assign(n, 0);
        height.assign(n, 0);
        height[source]=n;
        excess[source]=INF;
        for(auto &it:g[source])
            push(it);

        vector<int> current;
        while(!(current = find_max_height_vertices(source, dest)).empty())
        {
            for(auto i:current)
            {
                bool pushed=false;
                for(auto &e:g[i])
                {
                    if(excess[i]==0)
                        break;
                    if(e.cap - e.flow>0 && height[e.from] == height[e.to] + 1)
                    {
                        push(e);
                        pushed=true;
                    }
                }
                if(!pushed)
                {
                    relabel(i);
                    break;
                }
            }
        }

        long long max_flow=0;
        for(auto &e:g[source])
            max_flow+=e.flow;

        return max_flow;
    }
};

const int N=205;

int n, m;
int a[N], b[N];
int ans[N][N];
vector<int> g[N];

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    PushRelabel flow(2*n+2);
    for(int i=1;i<=m;i++)
    {
        int u, v;
        cin>>u>>v;  
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int reqd1=0, reqd2=0;
    for(int i=1;i<=n;i++)
    {
        reqd1+=a[i];
        reqd2+=b[i];
        flow.addEdge(0, i, a[i]);
        flow.addEdge(i, i+n, 1e5);
        flow.addEdge(i+n, 2*n+1, b[i]);
        for(auto j:g[i])
            flow.addEdge(i, j+n, 1e5);
    }
    int maxflow=flow.max_flow(0, 2*n+1);
    if(reqd1==reqd2 && reqd1==maxflow)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<=2*n+1;i++)
        {
            for(auto &e:flow.g[i])
            {
                if(e.cap!=0 && e.to>n && e.to-n!=i && e.to!=2*n+1)
                {
                    ans[i][e.to-n]=e.flow;
                    ans[i][i]-=e.flow;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                    ans[i][j]+=a[i];
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
        cout<<"NO";
    return 0;
}