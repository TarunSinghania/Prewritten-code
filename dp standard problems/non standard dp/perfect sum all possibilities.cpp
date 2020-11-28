   #include<bits/stdc++.h>
  using namespace std;
    #define ll long long
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
    constexpr auto mod = 1000000007;
    #define MOD 1000000007
   // #define maxv 200005
    #define MAXN 100001

  template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
  template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

int dp[1005][1005];
int a[1005];
vector<vector<int> >ans;
void p(int i,vector<int> v,int sum)
{
 
if(sum-a[i]==0)
{
  //cout<<"ANS"<<" ";
  vector<int> k = v; 
  k.push_back(a[i]);
  ans.pb(k);
  //prv(k);
 
}


if(dp[i-1][sum])
    {  
     p(i-1,v,sum);
    }

if(sum>a[i] && dp[i-1][sum-a[i]])
{
  v.push_back(a[i]);
  p(i-1,v,sum-a[i]);
}



}
void solve(){
  
  int n;
  cin>>n;
  int sum=0;
  fr(i,1,n+1)
  cin>>a[i];
  cin>>sum;

  fillm(dp,n+1,sum+1,0);
  dp[1][0]=1;
  dp[1][a[1]]=1;
  fr(i,2,n+1)
  {
    frj(j,0,sum+1)
    dp[i][j]= dp[i-1][j] + ((j-a[i]>=0)?dp[i-1][j-a[i]]:0);
  }
//  prm(dp,n+1,sum+1);
  vector<int> v;
  if(dp[n][sum])
    {
      p(n,v,sum);
      sort(ans.begin(),ans.end());
      for(auto k : ans)
      {
        cout<<"(";
        cout<<k[0];
      for(int i = 1 ; i <(int)k.size() ;i++ )
        cout<<" "<<k[i];
        cout<<")";
      }
      vector<vector<int> > k2;
      ans =k2;
    }
else
  cout<<"Empty";

  cout<<endl;
}
  
    int main(){
      speed;
        

      int t;
      cin>>t;
      while(t--)
      {
        solve();        
      }
      return 0;

  }