#include<bits/stdc++.h>
#define ll long long
#define UB upper_bound
#define LB lower_bound
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define F first
#define S second
#define fr(i,a,b) for(int i = a;i<b;i++)
using namespace std;
double a[1005],b[1005];
double p;
int n;
 
bool ch(double m){
 
	fr(i,0,n)
	{
		double used = (m+p)/a[i];
		m-=used;
		if(m<0)
			return false;
		if(i!=n-1)
		used = (m+p)/b[i+1];
		else
		used = (m+p)/b[0];
		m-=used;
		if(m<0)
			return false;
 
	}
	return true;
}
 
int main()
{
	
	cin>>n;
	cin>>p;	
	fr(i,0,n)
		cin>>a[i];
	fr(i,0,n)
		cin>>b[i];
 
		
		double l = 0 , r = 1e9+5;
		double m;
		if(!ch(1e9+1))
			cout<<"-1"<<endl,exit(0);
		while(abs(r-l) >=1e-6)
		{
 
		//	cout<<m<<endl;
 
				  m = (r+l)/2;
			if(ch(m))
				r = m;
			else
				l = m;
		}
	cout<<fixed<<setprecision(10)<<m<<endl;
}