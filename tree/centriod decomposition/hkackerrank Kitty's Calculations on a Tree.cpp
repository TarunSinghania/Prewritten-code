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
#define MAX 200005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define f first
#define s second
set<int> adj[MAX];
int sz[MAX];
int v,q,a,b;
inline int add(int x,int y){
    if(x+y>=MOD)
        return  x + y - MOD;
    return x + y;
}
inline int sub(int x,int y){
    if( x- y< 0 )
        return x - y + MOD;
    return x -y;
}
inline int mul(int x, int y){
    return 1LL*x*y%MOD;
}
int dfssz(int a, int p = -1){
    sz[a]=1;
    for(auto x: adj[a]){
        if(x != p){
            sz[a] += dfssz(x,a);
        }
    }
    return sz[a];
}
int getcentriod(int u,int p,int s){
    for(auto x: adj[u]){
        if(x!=p && sz[x] > s/2)
            return getcentriod(x,u,s);
    }
    return u;
}
int ans = 0;
int curr_level = 1;
int centriod[MAX];
int _dist[MAX][30];
int _p[MAX];
int _depth[MAX];
int _sum[MAX];
void conquer_subroutine2(int u,int p,int d){
    _depth[u]+=1;	
    _dist[u][_depth[u]] = d;
    for(auto x: adj[u]){
        if(x!=p){
            conquer_subroutine2(x,u,d+1);
        }
    }
}
void conquer2(int c){
    conquer_subroutine2(c,0,0);
}

void divide2(int u,int p){
    int s = dfssz(u,0);
    int c = getcentriod(u,0,s);
	_p[c] =  p;
    conquer2(c);
    vector<int> temp(all(adj[c]));
    for(auto x: temp)
    {
        curr_level++;
        adj[x].erase(c);
        adj[c].erase(x);
        divide2(x,c);
    }
}
void propagte_up(int u){
	int node = u;
	while(node){
		_sum[node] = add(_sum[node],u);
		node = _p[node];
	}
}
void calculate(int u){
	int d = _depth[u];	
	int included = u;
	int node = u;
	while(node){
		int m1 = u;
		int m2 = sub(_sum[node],included);
		int m3 = _dist[u][d];
		int m4 = mul(m1,mul(m2,m3));
        ans = add(ans,m4);
        included = _sum[node];
        d-=1;
		node = _p[node];
	}	
}
void clear(int u){
	int node = u;
	while(node){
		_sum[node] = 0;
		node = _p[node];
	}
}
void decompose(){
	_p[1]=-1;
	_depth[1]=0;
    divide2(1,0);
}
int main(){
    speed;
    cin>>v>>q;
    fr(i,0,v-1){
        cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    decompose();
    fr(i,0,q){
        ans = 0;
        vector<int> nodes;
        int h;cin>>h;fr(i,0,h){int x;cin>>x;nodes.pb(x);}
        ans = 0;
    	for(auto x: nodes){
    		propagte_up(x);
    	}
    	for(auto x: nodes){
    		calculate(x);
    	}
    	for(auto x: nodes){
    		clear(x);
    	}
        cout<<ans<<endl;

    }
    return 0;
}
