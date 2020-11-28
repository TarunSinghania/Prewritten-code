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
int partition(int l ,int r){
	int e  = a[r];
	int li = l;int ri = r;
	while(li < ri){
		while(a[li] < e){
			li++; 	
		}	
		while(a[ri] >= e){
			ri--;
		}
		if(li<ri){
			swap(a[li],a[ri]);
		}
	}	
	//li will the place where e is finally placed
	a[r] = a[li];
	a[li] = e;
	return li;
}
void quicksort(int l, int r){
	if(l>=r)return;
	int pivot = partition(l,r);
	quicksort(l,pivot-1);
	quicksort(pivot+1,r);
}
main(){
	int n;
	cin>>n;
	fr(i,1,n+1){
		cin>>a[i];	
	}
	quicksort(1,n);
	fr(i,1,n+1)
	cout<<a[i]<<" ";
}
