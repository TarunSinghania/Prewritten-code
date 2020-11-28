   #include<bits/stdc++.h>
  using namespace std;
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

      ll dp[101][maxv];

    const long long  INF = 1e15 +5;

int main(){
      
      speed;
      int n;
      cin>>n;
      
      int w;
      cin>>w;

      //input is as w , v
      vector<pair<int,int> > h;
      
      int x,y;
      fr(i,0,n)
      { cin>>x>>y;
        h.pb(mkp(x,y));
      }
        

      //dp[i][j]
      //minimum wight to get j value with  elements till i  knapsack 
     //  maxv at end of n items
      fillm(dp,n,maxv,INF);

      fr(i,0,maxv)
      {
        if(i<=h[0].second)
          dp[0][i]=h[0].first;
      }
      fr(i,0,n)
      {
        dp[i][0]=0;
      }

      fr(i,1,n)
      {
      //prm(dp,n,w+1);

          fr(j,1,maxv)
          { 

            if((j-h[i].second)>=0)
            dp[i][j] = dp[i-1][j-h[i].second]+h[i].first;
            else
            dp[i][j]=h[i].first;
        //    cout<<dp[i][j]<<" "<<i-1<<j-h[i].first<<dp[i-1][j-h[i].first]<<endl;
            dp[i][j]=min(dp[i-1][j],dp[i][j]);
          }
      }
      //prm(dp,n,141);
      ll ans =0;
      fr(i,0,maxv)
      if(dp[n-1][i]>0 && dp[n-1][i] <= w)
        ans = i;
      
      cout<<ans<<endl;

      return 0;

  }

