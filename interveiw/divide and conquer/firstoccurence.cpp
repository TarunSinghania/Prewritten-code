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
int a[MAX];
int firstoccurence(int l,int r,int k){
	while(l<r){
		int m = (l + r) /2;
		if(a[m] > k){
			r = m -1;			
		}
		else if(a[m] < k)
		{
			l = m+1;
		}
		else{
			if(m==1)
				return m;
			else if(a[m-1]!=k)
				return m;
			else
				r = m-1;
		}
	}
	return l;
}


main(){
	int n;
	cin>>n;
	fr(i,1,n+1){
		cin>>a[i];	
	}
	sort(a,a+n);
	cout<<firstoccurence(1,n,1);
}

// 8 
// 1 2 3 3 3 3 4 4