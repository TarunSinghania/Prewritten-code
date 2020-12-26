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
#define MAX_NODES 505

int v,e,s,t;

// represents the capacities of the edges
int capacities[MAX_NODES][MAX_NODES];
// shows how much flow has passed through an edge
int flow[MAX_NODES][MAX_NODES];
// represents the adj. The adj must contain the negative edges too!
vector<int> adj[MAX_NODES];
// shows the parents of the nodes of the path built by the BFS
int parentsList[MAX_NODES];
// shows the maximum flow to a node in the path built by the BFS
int currentPathCapacity[MAX_NODES];

int bfs(int startNode, int endNode)
{
  memset(parentsList, -1, sizeof(parentsList));
  memset(currentPathCapacity, 0, sizeof(currentPathCapacity));

  queue<int> q;
  q.push(startNode);

  parentsList[startNode]=-2;
  currentPathCapacity[startNode]=INF;

  while(!q.empty())
  {
      int currentNode = q.front(); q.pop();
      for(int i=0; i<adj[currentNode].size(); i++)
      {
        int to = adj[currentNode][i];
        if(parentsList[to] == -1)
        {
          if(capacities[currentNode][to] - flow[currentNode][to] > 0)
          {
          // we update the parent of the future node to be the current node
          parentsList[to] = currentNode;
          // we check which is the minimum residual edge capacity so far
          currentPathCapacity[to] = min(currentPathCapacity[currentNode],
          capacities[currentNode][to] - flow[currentNode][to]);
          // if we have reached the end node the bfs should terminate
          if(to == endNode) return currentPathCapacity[endNode];
          // we add our future node to the queue
          q.push(to);
        }
      }
  }
}

return 0;
}

int edmondsKarp(int startNode, int endNode)
{
  int maxFlow=0;

  while(true)
  {
  // we find an augmented path and the maximum flow corresponding to it
    int cur_flow=bfs(startNode, endNode);

    // if we can't find anymore paths the flow will be 0
    if(cur_flow==0)
    {
      break;
    }

    maxFlow +=cur_flow;
    int currentNode=endNode;

    // we update the passed flow matrix
    while(currentNode != startNode)
    {
      int previousNode = parentsList[currentNode];
      flow[previousNode][currentNode] += cur_flow;
      flow[currentNode][previousNode] -= cur_flow;
      currentNode=previousNode;
    }
  }

  return maxFlow;
}
void addedge(int u,int v,int c){
  capacities[u][v] = c;
  adj[u].pb(v);
  adj[v].pb(u);
}

int main()
{
    cin>>v>>e;
    s = 1;
    t = 1+ v+ v + 1;
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
        addedge(1+i,1+v+i,10000);
    }
    for(int i  =0 ; i < e ; i++){
        int a,b;
        cin>>a>>b;
        addedge(1+a,1+v+b,10000);
        addedge(1+b,1+v+a,10000);
    }
    totaloutput = edmondsKarp(s,t);
    if(totaloutput == totalinput){
        cout<<"YES"<<endl;
        for(int i = 2; i<=1+v ; i++){
            for(int j = 1+v+1 ; j<=1+v+v ;j++){
                if(flow[i][j]> 0)
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
