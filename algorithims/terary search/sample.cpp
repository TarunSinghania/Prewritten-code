//upsolve o(n + log^2(n))
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
ll n,k;
ll a[MAX];
ll p[MAX];
ll cost(int v){
	//set v,v+ks
	ll id1 = lower_bound(a,a+n,v)-a;
	ll id2 = upper_bound(a,a+n,v+k)-a;
	//cout<<v<<" "<<v+k<<" "<<id1<<" "<<id2<<endl;
	ll prefix_cost =0;
	ll suffix_cost =0;
	if(id1!=0 && id1!=n){
		prefix_cost = id1*v - p[id1-1];
	}
	if(id2!=n){
		suffix_cost = p[n-1] - (id2==0?0:p[id2-1]) - (n-id2)*(v+k);
	}
	//cout<<prefix_cost<<" "<<suffix_cost<<endl;
	return prefix_cost + suffix_cost;
}
main(){
	speed;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		fr(i,0,n){
			cin>>a[i];
		}
		sort(a,a+n);
		p[0]=a[0];
		fr(i,1,n){
			p[i]=p[i-1]+a[i];
		}
		ll ans = LONG_LONG_MAX;
		//ternary search
		int l  =a[0]; int r = a[n-1];
		while(r-l>2){
			ll m1 = cost(l+ (r-l)/3);
			ll m2 = cost(r- (r-l)/3);
			if(m1>m2)
				l = l+ (r-l)/3;
			else
				r = r- (r-l)/3;
		}
		ans = cost(l);
		fr(i,l+1,r+1){
			ans  = min(ans,cost(i));
		}
		cout<<ans<<endl;
	}	
}		