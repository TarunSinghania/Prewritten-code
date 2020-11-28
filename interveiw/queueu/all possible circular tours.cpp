//pizza
// 3
// 3 1 2
// 2 2 2
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

main(){
	speed;
	int n;
	cin>>n;
	int p[n+n];
	int d[n+n];
	fr(i,0,n)
	cin>>p[i];
	fr(i,0,n)
	cin>>d[i];

	fr(i,0,n)
	p[i+n]=p[i],d[i+n]=d[i];

	int pr[n+n];
	pr[0]=0;
	fr(i,1,n+n)
	{	
		pr[i]=pr[i-1]+p[i-1]-d[i-1];
	}
	//next smaller element
	int next[n+n];
	stack<int> s;
	fr(i,0,n+n){
		while(!s.empty() && pr[s.top()] > pr[i])
		{
			next[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()){
		int t = s.top();
		next[t] = n+n;
		s.pop();
	}
	fr(i,0,n+n){
		cout<<pr[i]<<" ";
	}
	cout<<endl;
	fr(i,0,n+n){
		cout<<next[i]<<" ";
		if(next[i] >= i + n -1 )
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}