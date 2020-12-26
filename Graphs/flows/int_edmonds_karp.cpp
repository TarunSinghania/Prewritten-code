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
#define MAX 505
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
//The algorithm runs in O(VE2) time, even for irrational capacitie
//edmond karps algorithm
int v,e;
int s,t;
int cap[MAX][MAX];
//flow passed
int flow[MAX][MAX];
vector<int> adj[MAX];
set<int> dup[MAX];
int bfs(int s, int t, vector<int>& parent) {
    fr(i,1,t+1){
        parent[i]=-1;
    }
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int next : adj[cur]) {
            if (parent[next] == -1 && cap[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, cap[cur][next]);
                if (next == t){
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}
 
int maxflow(int s, int t) {
    int total_flow = 0;
    //initproperly
    vector<int> parent(t+2);
    int new_flow=0;
    while (true) {
        new_flow = bfs(s, t, parent);
        if(new_flow == 0){
            break;
        }
        total_flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            //to output flow output >0 values in flow in flow matrix
            flow[prev][cur] += new_flow;
            flow[cur][prev] -= new_flow;
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return total_flow;
}
void addedge(int u,int v,int c){
    adj[u].pb(v);
    adj[v].pb(u);
    cap[u][v] = c;
}

int main(){
    speed;    
    cin>>v>>e;
    
}