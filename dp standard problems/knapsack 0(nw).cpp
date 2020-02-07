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
  constexpr auto mod = 1000000007;
  #define MOD 1000000007
  #define maxv 200005
  #define MAXN 1000001

template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
int n;

int mv[1001][1001];

void solve(){
  int n,W;
  cin>>n>>W;
  int w[n];
  int v[n];
  fr(i,0,n)
  cin>>v[i];
  fr(i,0,n)
  cin>>w[i];
  
  fillm(mv,W+1,n,0);
  //first row automatic zero
  fr(i,0,W+1)
  { 
    if(i>=w[0])
      mv[i][0]=v[0];
  }
  fr(i,1,n)
  {
    frj(j,0,W+1)
    { int x =0,y=0;
      if(j-w[i]>=0)
      {
        x = mv[j-w[i]][i-1]+v[i];
      }
      y = mv[j][i-1];
      mv[j][i]=max(x,y);
    }
  }
  //prm(mv,W+1,n);
  cout<<mv[W][n-1]<<endl;

}
int main(){

  int t;
  cin>>t;
  while(t--)
  {
    solve();

  }
    return 0;
}