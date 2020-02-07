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
    #define pii pair<int,int>
    #define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
    //#define c(a,b) cout<<a<<"--"<<b<<endl;
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
    constexpr auto mod = 1000000007;
    #define MOD 1000000007
    #define maxv 100005
    #define MAXN 100001

  template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
  template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }


int wordBreak(string a, vector<string> &b) {


  unordered_map<string,int> mp;
  int s = INT_MIN;
for(auto x : b)
 {
    s=max(s,(int)x.length());
      mp[x]=1;
 } 

int n = a.length();
//dp (i,j)is pooss
bool dp[n][n];
fillm(dp,n,n,false);

for(int i = n-1 ; i >=0 ; i--)
{
     frj(j,i,n)
    {
        if(mp[a.substr(i,j-i+1)]==1)
            dp[i][j]=true;
        for(int k = 1 ; k < j-i+1 && k <=s  ; k++)
        {  // cout<<i<<k<<j<<endl;
            if(mp[a.substr(i,k)] && dp[i+k][j])
                dp[i][j]=true;
        }
    }

}

prm(dp,n,n);  


if(dp[0][n-1])
    return 1;
else
    return 0 ;



}

    

int main(){
    int t;cin>>t;
    while(t--)
    {
vector<string> b ;


string a;
        int k;
        cin>>k;
        while(k--)
        {
            string s;
            cin>>s;
            b.pb(s);
        }
        cin>>a;

cout<<wordBreak(a,b)<<endl;

    }


  }

