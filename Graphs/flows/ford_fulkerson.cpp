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
#define MAX_N 600
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define f first
#define s second
vector<int> adj[MAX_N];
bool mark[MAX_N];
int cap[MAX_N][MAX_N];
int flow[MAX_N][MAX_N];
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
    //intitialiseproperly
    for (int i=1;i<=t;i++) parent[i] = 0;
    stack<int> dfs_stek;
    stack<int> minCapacity;
    parent[s] = -1;
    dfs_stek.push(s);
    minCapacity.push(INF);
    while (!dfs_stek.empty())
    {
        int xt = dfs_stek.top();
        int mt = minCapacity.top();
        //cout<<xt<<" "<<mt<<" "<<parent[xt]<<endl;
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
          //  cout<<"xt1"<<xt1<<" "<<cap[xt][xt1]<<" "<<parent[xt1]<<endl;
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
            flow[parent[currNode]][currNode]+=ret;
            flow[currNode][parent[currNode]]-=ret;
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

void addedge(int u,int v,int c){
    adj[u].pb(v);
    adj[v].pb(u);
    cap[u][v] = c;
}


int main()
{
    cin>>v>>e;
    s = 1;
    t = 1+v+v+1;
    int totalinput = 0;
    int totaloutput = 0;
    int maxcapacity = 0;
    for(int i = 1 ; i <= v ;i++){
        int c;cin>>c;
        totalinput+=c;
        addedge(1,1+i,c);
    }
    for(int i = 1 ;i <= v; i++){
        int c;cin>>c;
        maxcapacity+=c;
        addedge(1+v+i,t,c);
    }
    if(maxcapacity != totalinput){
        cout<<"NO"<<endl;
        exit(0);
    }
    for(int i =1 ; i <= v ; i++){
        addedge(1+i,1+v+i,INF);
    }

    for(int i  =0 ; i < e ; i++){
        int a,b;
        cin>>a>>b;
        addedge(1+a,1+v+b,INF);
        addedge(1+b,1+v+a,INF);
    }   
    totaloutput = FordFulkerson();
    //cout<<totalinput<<" "<<totaloutput<<endl;
    if(totaloutput == totalinput){
        cout<<"YES"<<endl;
        for(int i = 2; i<=1+v ; i++){
            for(int j = 1+v+1 ; j<=1+v+v ;j++){
                    if(flow[i][j] > 0)
                        cout<<flow[i][j]<<" ";
                    else
                        cout<<0<<" ";

            }
            cout<<endl;
        }
    }   
    else{
        
        cout<<"NO"<<endl;
    }   
    return 0;
}
