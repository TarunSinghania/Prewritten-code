#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define fre(i,a,b) for(int i =a ; i <= b; i++)
#define fra(s) for(auto it = s.begin(); it != s.end() ; ++it)

#define mkp make_pair 
#define pb push_back
#define pii pair<int,int>
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define c(a,b) cout<<a<<"--"<<b<<endl;
#define frv(i,a,v) for(int i =  a ; i < v.size() ; ++i)
#define cp(a,i)  cout<<a[i].first<<" "<<a[i].second<<endl;
#define mp(a) cout<<a->first<<" "<<a->second<<endl;
//sum array
#define sa(n) int a[n]; int s[n];cin>>a[0];s[0]=a[0];fr(i,1,n) {cin>>a[i];s[i]=s[i-1]+a[i];}
#define sa1(n) int a[n+1]; long long s[n+1]; a[0]=0; s[0]=0;cin>>a[1];s[1]=a[1];fr(i,2,n+1) {cin>>a[i];\
s[i]=s[i-1]+a[i];}



#define MOD 1000000007

const int N = 100001;

long long t[5*N];
long long l[5*N];

int a[N];

void b(int n ,int s,int e)
{
	if(s==e)
		t[n] = a[s];
	else
	{
		int m = (s+e)/2;
		b(2*n,s,m);
		b(2*n+1,s,n);
		t[n]=t[2*n]+t[2*n+1];
	}
}


void u(int n ,int a,int b,int s ,int e,long long uu)
{
	
	if(l[n]!=0)
	{

		t[n]=t[n]+(e-s+1)*l[n];

		if(s!=e)
			l[2*n] += l[n];
			l[2*n+1] += l[n];

		l[n] = 0;

	}
	if(b<s || a>e)
		return;

	if(a<=s && b>= e){
		t[n]=t[n]+(e-s+1)*uu;

		if(s!=e)
		 l[2*n]+=uu;
		 l[2*n+1]+=uu;
	return;
	}

	int	m = (s+e)/2;

	u(2*n,a,b,s,m,uu);
	u(2*n+1,a,b,m+1,e,uu);

	t[n]=t[2*n]+t[2*n+1];
}


long long int q(int n ,int a,int b,int s,int e)
{
	if(b<s || a> e)
		return 0 ;

	if(l[n]!=0)
	{
		t[n]=t[n]+(e-s+1)*l[n];

		if(s!=e)
			l[2*n] += l[n];
			l[2*n+1] += l[n];

		l[n] = 0;

	}

	if(a<=s && b >=e)
		{//cout<<"yupp"<<a<<b<<s<<e<<endl;
	return t[n];}

	int m = (s+e)/2;

	return q(2*n,a,b,s,m)+q(2*n+1,a,b,m+1,e);

}


	


int main()
{


int te;
cin>>te;
while(te--)
{

	int n , c;
	cin>>n>>c;
	//intially all zero 

	while(c--)
	{
		int qu,j,k;
		long long le;
		cin>>qu;

		if(!qu){
			cin>>j>>k>>le;
			u(1,j,k,1,n,le);
		}
		else
		{	cin>>j>>k;
			cout<<q(1,j,k,1,n)<<endl;
		}

	//fre(i,1,15)
	//	cout<<t[i]<<" ";
	//cout<<endl;
	//fre(i,1,15)
	//	cout<<l[i]<<" ";
	//cout<<endl;

	}
fr(i,0,4*N)
t[i]=l[i]=0;


}
	return 0;
}