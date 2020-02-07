#include<bits/stdc++.h>
using namespace std;
  #define ll long long
  #define fr(i,a,b) for(int i =a ; i < b; i++)
  #define frj(j,a,b) for(int j =a ; j < b; j++)
  #define fre(i,a,b) for(int i =a ; i <= b; i++)
  #define fra(s) for(auto it = s.begin(); it != s.end() ; ++it)

  #define mkp make_pair 
  #define pb push_back
  #define pii pair<int,int>
  #define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
  #define c(a,b) cout<<a<<"--"<<b<<endl;
  #define frv(i,a,v) for(int i =  a ; i < v.size() ; ++i)
  #define cp(a,i)  cout<<a[i].first<<" "<<a[i].second<<endl;
  #define pp(a) cout<<a.first<<" "<<a.second<<endl;
  //sum array
  #define sa(n) int a[n]; int s[n];cin>>a[0];s[0]=a[0];fr(i,1,n) {cin>>a[i];s[i]=s[i-1]+a[i];}
  #define sa1(n) int a[n+1]; long long s[n+1]; a[0]=0; s[0]=0;cin>>a[1];s[1]=a[1];fr(i,2,n+1) {cin>>a[i];\
  s[i]=s[i-1]+a[i];}

  #define pr(a,n) fr(i,0,n){cout<<a[i]<<" ";}cout<<endl;
  #define prv(v)   for(auto it = v.begin() ; it!= v.end() ;++it){cout<<*it<<" ";}cout<<endl;
  #define prs(s)   for(auto x : s){cout<<x<<" ";}cout<<endl;
  
  #define all(x)           x.begin(), x.end()
  #define prm(m,r,c) fr(i,0,r){frj(j,0,c){cout<<m[i][j]<<" "; }cout<<endl;}
  #define fillm(m,r,c,k) fr(i,0,r)frj(j,0,c)m[i][j]=k;
  constexpr auto PI  = 3.14159265358979323846L;
  constexpr auto eps = 1e-6;
//  constexpr auto mod = 1000000007;
  #define MOD 1000000007
  #define maxv 200005
  #define MAXN 1000001

template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

long long mod = 1000000007;

vector<vector<long long > > mul(vector<vector<long long > > a, vector<vector<long long > > b) {
    int m = a.size();
    vector<vector<long long > > res(m, vector<long long> (m, 0));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < m; ++k)
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
    return res;
}

vector<vector<long long > > pow(vector<vector<long long > > a, long long n) {
    int m = a.size();
    vector<vector<long long > > res(m, vector<long long> (m, 0));
    for (int i = 0; i < m; ++i)
        res[i][i] = 1;
    while(n>0)
    {
      if(n%2 == 1)
        res = mul(res,a);
     a = mul(a,a);
     n=n/2;
    }
    return res;
}


int main(){
    int t;
    cin>>t;
    while(t--)
    {
    int a,b,c,n,m;

    cin>>a>>b>>c>>n>>m;
   // cout<<a<<b<<c<<n<<m<<endl;
    mod = m;
    if(n==1)
      cout<<1<<endl,exit(0);
    if(n==2)
      cout<<1<<endl,exit(0);

    vector<vector<ll> > v ={{a,b,1},{1,0,0},{0,0,1}};

    v=pow(v,n-2);
    //cout<<v[0][0]<<v[0][1]<<v[0][2]<<endl;
    ll ans = (v[0][0] + v[0][1] + c*v[0][2])%mod;
    cout<<ans<<endl;
    }
    return 0;
}