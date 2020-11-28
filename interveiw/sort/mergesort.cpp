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
int t[MAX];


void _merge(int l,int m ,int r){
	int ti = l;
	int li = l;
	int ri = m+1;
	while((li<=m) && (ri<=r))
	{	
		if(a[li]<=a[ri])
		{	
			t[ti] = a[li];
			ti++;li++;
		}
		else{
			t[ti] = a[ri];
			ri++;ti++;
		}
	}
	while(li<=m){
		t[ti]=a[li];li++;ti++;
	}
	while(ri<=r){
		t[ti]=a[ri];ri++;ti++;
	}
	fr(i,l,r+1){
		a[i]=t[i];
	}
}
void mergesort(int l,int r){
	if(l>=r)return;
	int m = (l + r)>>1;
	mergesort(l,m);
	mergesort(m+1,r);
	_merge(l,m,r);
}

main(){
	int n;
	cin>>n;
	fr(i,1,n+1){
		cin>>a[i];	
	}
	mergesort(1,n);
	fr(i,1,n+1)
	cout<<a[i]<<" ";

}
