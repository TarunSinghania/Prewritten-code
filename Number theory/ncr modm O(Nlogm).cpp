  #include <bits/stdc++.h>

  using namespace std;
  #define ll long long
  #define fr(i,a,b) for(int i =a ; i < b; i++)
  #define frj(j,a,b) for(int j =a ; j < b; j++)
  #define fre(i,a,b) for(int i =a ; i <= b; i++)
  #define fra(s) for(auto it = s.begin(); it != s.end() ; ++it)



 #define MOD 1000000007
 // #define MOD 998244353
 
  #define maxv 200005
  #define mx 505
  #define N 2005
  ll fac[N];

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

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b;

    return gcd(b%a, a); 
} 
 

ll mi(ll a) 
{ 
    ll g = gcd(a,MOD); 
    if (g != 1) 
        return -1;
    else
    { 
        return me(a,MOD-2); 
    } 
} 






  int main()
  { 
    int n,r;
    cin>>n>>r;
    fac[0]=1;fac[1]=1;
    fr(i,2,N)
    fac[i]=fac[i-1]*i%MOD;
    //O n foc calculating factorials 
    //o(log m) ---a inverse p == a^(p-2)--modular exponentiaion o(power)
    ll ans = fac[n]*mi(fac[n-r])%MOD;
    ans = ans*mi(fac[r])%MOD;

    cout<<ans<<endl;

    return 0;

  } 
   