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
#define MAXN 5000005
#define PI 3.14159265358979323846;
#define MAX 1005
int INF = 2000000007;
ll MOD  = 998244353;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ll f[MAXN];

void init()
{
    f[1]=1;
    fr(i,2,MAXN)
    {
        f[i]=(((1LL*i)%MOD)*(f[i-1]%MOD))%MOD;
    }
}


ll gcd(ll a, ll b); 

  
ll me(ll x,ll n)
{
    ll r=1;
    while(n>0)
    {
        if(n % 2 ==1)
        r=(r * x)%MOD;
        x=(x*x)%MOD;
        n=n/2;
    }
    return r ;
}

ll mi(ll a) 
{ 
    ll g = gcd(a,MOD); 
    if (g != 1) 
        return 1;
    else
    { 
        // If a and m are relatively prime, then modulo inverse 
        // is a^(m-2) mode m 
        return me(a,MOD-2); 
    } 
} 



ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b;

    return gcd(b%a, a); 
} 
  

ll ncr(ll n,ll r)
{
    //do not forget init
    if(n<0)return 0;
    if(n<r)return 0;
    ll ans = ((f[n]%MOD)*(mi(f[n-r])%MOD))%MOD;
    ans = (ans*(mi(f[r])%MOD))%MOD;
    return ans;
}
int main()
{


    speed;
    init();
    int t;
    cin>>t;
    while(t--)
    {

        ll n,m,k;
        cin>>n>>m>>k;
      
        ll ans = 0;
        fr(i,0,m+1)
        {
            ll temp = (ncr(m-1+k-n*i,m-1)*ncr(m,i))%MOD;
            //cout<<temp;
            if(i&1){
                //-
                ans=(ans-temp+MOD)%MOD;
            } 
            else{
                ans=(ans+temp)%MOD;


            }

        }
        cout<<ans<<endl;
    }
   return 0;

}