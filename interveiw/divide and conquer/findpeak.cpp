//pizza
// 10
// 1 10 9 8 7 6 5 4 3 2
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
#define prv(v) for(autxo x: v)cout<<x<<" ";cout<<endl;
#define MAX 200005
#define maxv 200005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define f first
#define s second
int a[MAX];
int n;
int findpeak(int l,int r){
	int low = l;int high = r;

	int cnt = 0;
	while(l<r){
		int m = (r+l)/2;
		if(m>1 && m <high){
			if(a[m] > a[m+1] && a[m] > a[m-1])
				return m;
		}
		if(m>1 && a[m] > a[m-1])
		{
				l = m+1;
		}
		else{
				r = m-1;
		}
	}
	return -1;
}
main(){
	speed;
	cin>>n;
	fr(i,1,n+1){
		cin>>a[i];
	}
	cout<<findpeak(1,n)<<endl;
}

