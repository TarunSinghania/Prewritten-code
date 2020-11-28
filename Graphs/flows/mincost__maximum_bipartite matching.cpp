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


int cost[205][410];
void mincost_maxmatching(int n,int m){
vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
for (int i=1; i<=n; ++i) {
	p[0] = i;
	int j0 = 0;
	vector<int> minv (m+1, INF);
	vector<char> used (m+1, false);
	do {
		used[j0] = true;
		int i0 = p[j0],  delta = INF,  j1;
		for (int j=1; j<=m; ++j)
			if (!used[j]) {
				int cur = cost[i0][j]-u[i0]-v[j];
				if (cur < minv[j])
					minv[j] = cur,  way[j] = j0;
				if (minv[j] < delta)
					delta = minv[j],  j1 = j;
			}
		for (int j=0; j<=m; ++j)
			if (used[j])
				u[p[j]] += delta,  v[j] -= delta;
			else
				minv[j] -= delta;
		j0 = j1;
	} while (p[j0] != 0);
	do {
		int j1 = way[j0];
		p[j0] = p[j1];
		j0 = j1;
	} while (j0);
}

//who is matched were ?
int ans[n+1];
fr(i,1,m+1){
	ans[p[i]] = i;
}
//pr(ans,n+1);
//total cost
cout<<-v[0]<<endl;
}
int main(){
  	speed;
  	int t;cin>>t;
  	while(t--){
  		int n;
  		cin>>n;
  		int tm[n+1];
  		fr(i,1,n+1){
  			cin>>tm[i];
  		}
  		int m  = 2*n+2;
  		fr(i,1,n+1){
  			fr(j,1,m+1)
  			{
  				cost[i][j] = abs(tm[i]-j);
  			}
  		}
  		mincost_maxmatching(n,m);
  	}
   	return 0;
}