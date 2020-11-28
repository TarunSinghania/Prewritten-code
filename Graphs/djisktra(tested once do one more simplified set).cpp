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
#define MAX 400005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define f first
#define s second
vector<pair<int,int> > adj[MAX];
int v,e;
int dis[MAX];
void dijkstra(int str){
	fr(i,1,v+1){
	dis[i]=INF;
	}
	dis[str]=0;
	set<pair<int,int> > st;
	st.insert({0,str});
	while(!st.empty()){
		int u = (*st.begin()).s;
		int w = (*st.begin()).f;
		st.erase(st.begin());
		for(auto x: adj[u]){
			if(dis[x.f] > x.s + w){
				if(dis[x.f]!=INF)
					st.erase({dis[x.f],x.f});
				dis[x.f] = x.s + w;
				st.insert({x.s+w,x.f});
			}
		}
	}
}
main(){
	cin>>v;
	cin>>e;
	fr(i,0,e){
		int x,y,z;
		cin>>x>>y>>z;
		adj[x].pb({y,z});
	//	adj[y].pb({x,z});
	}	
	dijkstra(2);
	fr(i,1,v+1){
		cout<<dis[i]<<" ";
	}
}