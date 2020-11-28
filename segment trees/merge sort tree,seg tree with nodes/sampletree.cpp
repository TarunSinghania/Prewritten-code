#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define F first
#define S second
#define ld long double
#define int long long 

using namespace std;

const int MAXN = 1001 * 1001 , MOD = 1e9 + 7 ; 

int a[MAXN] ; 

void solve(int s , int e , int x , vector<int> v )
{
  if(x==1)
  {
    for(int i = s ; i < e ; i ++ ) 
      a[i] = v[i-s] ; 
    return ;
  }
  int mid = (s+e) / 2 ; 
  int l = mid - s , r = e - mid ; 
  vector<int> v1 , v2 ; 
  for(int i = 0 ; i < r ; i ++ ) v2.pb(v[i]) ; 
  for(int i = r ; i < l + r ; i ++ ) v1.pb(v[i]) ; 
  x -- ; 
  if(x<=2*l)
  {
    solve(s,mid,x-1,v1) ; 
    solve(mid,e,1,v2) ; 
    return ; 
  }
  solve(s,mid,2*l-1,v1) ; 
  solve(mid,e,x-(2*l-1),v2) ; 
}

int32_t main() 
{
  ios::sync_with_stdio(0) ; 
  cin.tie(0) ;
  int n , k ; 
  cin >> n >> k ; 
  if(k%2==0||k>2*n) return cout << -1 << endl , 0 ; 
  vector<int> v ; 
  for(int i = 1 ; i <= n ; i ++ ) v.pb(i) ; 
  solve(0,n,k,v) ; 
  for(int i = 0 ; i < n ; i ++ ) cout << a[i] << ' ' ;
  cout << endl ; 
}

