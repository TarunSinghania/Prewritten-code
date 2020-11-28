#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n,m,u,v,w;
	list<pair<int, int> > adj[100];
	cin>>n>>m;
	for(int i=0; i<m; i++){
		cin>>u>>v>>w;
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}
	bool inMst[n];
	int keys[n],parent[n];
	for(int i=0; i<n; i++){
		inMst[i]=false;
		keys[i]=INT_MAX;
		parent[i]=-1;
	}
	priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > >pq;
	int src=0;
	pq.push(make_pair(0,src));
	keys[src]=0;
	while(!pq.empty()){
		int U = pq.top().second;
		pq.pop();
		inMst[U]=true;
		for(auto it=adj[U].begin(); it!=adj[U].end(); it++){
			int V = it->first;
			int weight = it->second;
			if(inMst[V]==false && keys[V]>weight){
				keys[V]=weight;
				pq.push(make_pair(keys[V],V));
				parent[V]=U;
			}
		}
	}
	for(int i=1; i<n; i++){
		cout<<parent[i]<<" "<<i<<" "<<keys[i]<<endl;
	}
	return 0;
}