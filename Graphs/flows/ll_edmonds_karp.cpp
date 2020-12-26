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
#define INF 1e18
#define prv(v) for(auto x: v)cout<<x<<" ";cout<<endl;
#define MAX 505
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define f first
#define s second
//The algorithm runs in O(VE2) time, even for irrational capacitie
//edmond karps algorithm
int n,m;
ll capacity[MAX][MAX];
vector<int> adj[MAX];
set<int> dup[MAX];

ll bfs(int s, int t, vector<int>& parent) {
    fr(i,1,t+1){
        parent[i]=-1;
    }
    parent[s] = -2;
    queue<pair<int, ll>> q;
    q.push({s, INF});
    while (!q.empty()) {
        int cur = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t){
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

ll maxflow(int s, int t) {
    ll flow = 0;
    vector<int> parent(n+1);
    ll new_flow=0;
    while (true) {
        new_flow = bfs(s, t, parent);
        if(new_flow == 0){
            break;
        }
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main(){
  speed;    
  cin>>n>>m;

  fr(i,0,m){
        int u,v;
        ll c;
        cin>>u>>v>>c;
        if(dup[u].find(v)==dup[u].end()){
        adj[u].pb(v);
        }
        dup[u].insert(v);
        capacity[u][v]+=c;
  }
 cout<<maxflow(1,n)<<endl;
return 0;
}