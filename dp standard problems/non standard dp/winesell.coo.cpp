#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define ll long long
#define ull unsigned long long
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define FR(i,a,b) for(int i =a ; i > b; i--) 
#define frj(j,a,b) for(int j =a ; j < b; j++)
#define FRE(i,a,b) for(int i =a ; i >= b; i--) 
#define fre(i,a,b) for(int i =a ; i <= b; i++)
#define fra(s) for(auto it = s.begin(); it != s.end() ; ++it)
 
#define mkp make_pair 
#define pb push_back
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
//#define c(a,b) cout<<a<<"--"<<b<<endl;
#define frv(i,a,v) for(int i =  a ; i < v.size() ; ++i)
#define cp(a,i)  cout<<a[i].first<<" "<<a[i].second<<endl;
#define pp(a) cout<<a.first<<" "<<a.second<<endl;

 
#define pr(a,n) fr(i,0,n){cout<<a[i]<<" ";}cout<<endl;
#define prv(v)   for(auto it = v.begin() ; it!= v.end() ;++it){cout<<*it<<" ";}cout<<endl;
#define prpv(v)   for(auto it = v.begin() ; it!= v.end() ;++it){cout<<"("<<it->first<<","<<it->second<<")";}cout<<endl;
//#define prs(s)   for(auto x : s){cout<<(*x).first<<","<<(*x).second<<")";}cout<<endl;
#define all(x)           x.begin(), x.end()
 
#define prm(m,r,c) fr(i,0,r){frj(j,0,c){cout<<m[i][j]<<" "; }cout<<endl;}
#define fillm(m,r,c,k) fr(i,0,r)frj(j,0,c)m[i][j]=k;
 
 
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;
#define maxv 100005
#define MAXN 100001
#define PI 3.14159265358979323846;
#define MAX 100005
int INF = 2000000007;
ll MOD  = 1000000007;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);



int main()
{
    speed;
    ll n;
    cin>>n;
    ll c[n+1];
    fr(i,1,n+1)
        cin>>c[i];
    ll dp[n+2][n+2];   
    fillm(dp,n+2,n+2,0);
    for(int i = n ; i> 0 ; i--)
    {
        for(int j = i ;j<=n ;j++)
        {   

            if(i>j)continue;
            //cout<<i<<j<<endl;
            ll y = n - (j-i+1) + 1;
            
            dp[i][j]= max(dp[i+1][j] + y*c[i],dp[i][j-1]+ y*c[j]);
        }
    }
   // prm(dp,n+2,n+2);
    cout<<dp[1][n]<<endl;
    
    return 0;
}
