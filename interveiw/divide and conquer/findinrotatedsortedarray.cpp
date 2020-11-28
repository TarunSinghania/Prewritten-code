//pizza
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
#define maxv 200005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define f first
#define s second
// 10
// 15 17 1 3 5 7 8 9 11 13 
//1
int a[MAX];
int find_pivot(int l,int r){
	int low = l;int high = r;
	while(l<r){
		int m = (l+r)/2;
		if(m<high && a[m] >a[m+1])
			return m;
		if(m>low && a[m] < a[m-1])
			return m-1;
		if(a[l] > a[m]){
			r = m-1;	
		}
		else if(a[l] <= a[m])
		{
			l = m+1;
		}
	}
	return l;
}
int _find(int l,int r,int k){
	while(l<=r){
		int m = (l+r)/2;
		if(a[m] == k)
			return m;
		else if(a[m] > k)
			r = m-1;
		else
			l=m+1;
	}
	return -1;
}


int findoccurence(int l,int r,int k){
	int m = find_pivot(l,r);
	int a = _find(l,m,k);
	int b = _find(m+1,r,k);
	int ans = -1;
	if(a>0)
		ans = a-1;
	if(b>0 && ans > 0)
		ans = min(ans,b-1);
	else if(b>0)
		ans=b-1;
	return ans;
}
main(){
	int t;
	cin>>t;
	
	while(t--){
	int n;
	cin>>n;
	fr(i,1,n+1){
		cin>>a[i];	
	}
	int x;
	cin>>x;
	//sorted rotated array
	cout<<findoccurence(1,n,x)<<endl;
	}	
}

