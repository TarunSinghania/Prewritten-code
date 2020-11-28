#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define ll long long
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define mod 5000000
#define prm(m,r,c) fr(i,0,r){fr(j,0,c){cout<<m[i][j]<<" "; }cout<<endl;}
 
ll dp[10005][55];
//DO NOT FORGET TO SET ME
ll N;
ll a[MAX];
ll bt[MAX][55];
 
inline int add(int x,int y)
{
    if(x + y >= mod)
        return x + y - mod;
    return x + y;
}
inline int sub(int x,int y)
{
    if(x - y < 0)
        return x - y + mod;
    return x - y;
}
inline int mul(int x,int y)
{
    return 1LL * x * y % mod;
}
 
void update(ll idx,ll val,ll branch)
{
    //donot pass idx =0;
    if(idx == 0)
    {
      //exit code -2 
      exit(-2);
    }
    //currently adding
    while(idx<=N)
    {
      //  cout<<idx<<endl;
        bt[idx][branch]=add(val,bt[idx][branch]);
        idx+=idx&(-idx);
    }
}
 
ll prefixsum(int r,int branch)
{
    //currently reutrning prefix sum  
    ll res = 0;
    while(r)
    {
    res=add(res,bt[r][branch]);
    r-=r&(-r);
    }
    return res;
}
 
 
 
 
 
main()
{
 
    speed;
    ll n,K;
    cin>>n>>K;
    N = 100005;
    fr(i,1,n+1)
    {
        cin>>a[i];
        a[i]=a[i]+1;
    }
 
    fr(i,1,n+1)
    {   
 
        fr(k,1,K+1)
        {
            if(k==1)
            {
                dp[i][k]=1;
            }
            else
            {
            //    cout<<"prefixsum"<<prefixsum(a[i],k-1)<<endl;
                dp[i][k]=prefixsum(a[i]-1,k-1); 
            }
        }
        fr(k,1,K+1)
        {
                update(a[i],dp[i][k],k);
        }
 
    }
  // prm(dp,n+1,K+1);
    ll ans = 0 ;
    fr(i,1,n+1)
    {
        ans = add(ans,dp[i][K]);
    }
 
    cout<<ans<<endl;
} 