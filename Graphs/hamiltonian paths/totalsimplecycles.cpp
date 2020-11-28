#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define mkp make_pair 
#define pb push_back
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define sz 500;
#define ff first
#define ss second
#define MAX 10005
#define pr(a,n) fr(i,0,n){cout<<a[i]<<" ";}cout<<endl;
#define MAXBLOCKS 10000
#define all(x) x.begin(),x.end()
#define INF 10000000
#define MOD 1000000007
#define prm(m,r,c) fr(i,0,r){fr(j,0,c){cout<<m[i][j]<<" "; }cout<<endl;}
#define fillm(m,r,c,k) fr(i,0,r)fr(j,0,c)m[i][j]=k;
#define endl '\n'
#define MAXVERTICES 19
#define prv(v) for(auto s: v){cout<<s<<" ";}cout<<endl; 

// 5 5
// 1 2 1
// 2 3 5
// 3 4 2
// 4 5 6
// 2 5 2


int n,m;//max 16
ll dp[1<<MAXVERTICES][MAXVERTICES];
//Let dp[mask][i] be the number of Hamiltonian walks over the subset mask, starting at the vertex first(mask) and ending at the vertex i.
int g[MAXVERTICES][MAXVERTICES];
int d[MAXVERTICES][MAXVERTICES];


void init()
{
  fr(i,0,MAXVERTICES)
  {
    fr(j,0,1<<MAXVERTICES)
    dp[j][i]=0;
  }
  
}
void base()
{
  fr(i,0,1<<n)
  {
    if(__builtin_popcount(i)==1)
    {
      fr(bit,0,n)
      {
        if(i&(1<<bit))
          dp[i][bit]=1;
      }
    }
  }
}
int fbit(int nmask)
{
    int first = 0;
    for(int bit = n-1 ; bit>=0 ; bit--)
    {
      if((1<<bit)&nmask){
        first = bit;break;
      }
    }
    return first;
}
void work()
{
  fr(i,1,1<<n)
  {
    int first=fbit(i);
    
    fr(j,0,n)
    {
      if(j==first)continue;
  
      int nmask = (i^(1<<j));

      if(!(i&(1<<j)))continue;
      fr(k,0,n)
      {
        if(!(i&(1<<k)))continue;
        if(!g[k][j])continue;
        dp[i][j]+=dp[nmask][k];
      }
    }   
  }

}

ll result(){
  //return total number simple cycles
  ll ans = 0;
  fr(mask,1,1<<n)
  {
    int first = fbit(mask);
    fr(j,0,n)
    {
      if(j==first)continue;
      if(__builtin_popcount(mask)>=3)
        if(mask&(1<<j))
        {
          if(g[first][j]){
            ans+=dp[mask][j];
          }
        }
    }
  }
  return ans/2;
}
main() {
    speed; 
    
  cin>>n>>m;
  init();

  fr(i,0,m)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    g[a][b]=1;g[b][a]=1;
   // cin>>d[a][b];
    //d[b][a]=d[a][b];
  }

  base();
  work();



  cout<<result();
} 