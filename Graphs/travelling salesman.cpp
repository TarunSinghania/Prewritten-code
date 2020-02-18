#include <bits/stdc++.h>

using namespace std;
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define pb push_back
#define ll long long
#define mkp make_pair 
#define MAX 100005
#define MAX_LOG 25
#define INF 100000000
#define pr(a,b) fr(i,0,b){cout<<a[i]<<" ";}cout<<endl;
#define prs(s) for(auto x : s){cout<<x.first<<"#"<<x.second<<" ";}cout<<endl;
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define MAXV 12
int d[MAXV][MAXV];
int dp[(1<<MAXV)+5][MAXV];

void tsp(int v){
    fr(i,1,(1<<v))
    {
        fr(j,1,v+1)
            dp[i][j]=INF;
    }
    dp[1][1]=0;

    fr(i,1,(1<<v))
    {
        for(int j = v-1 ; j>=0 ; j--)
        {
            if((i>>j)&1)
            {

                int temp = (i^(1<<j));
                //cout<<"i"<<i<<"j"<<j<<endl;
                //cout<<"te"<<temp<<endl;
                for(int k = v-1; k >= 0 ;k--)
                {
                    if((temp>>k)&1){
                //  cout<<"in"<<"t"<<temp<<"k"<<k<<"d"<<d[k+1][j+1]<<endl;
                    dp[i][j+1] = min(dp[i][j+1],dp[temp][k+1] + d[k+1][j+1]);
                    }
                }
                //cout<<dp[i][j+1]<<endl;
            }
        }

    }
}


int main()
{
   int t;
   cin>>t;
   while(t--){

        int v;
        cin>>v;
        v++;

        fr(i,1,v+1)
        {
                fr(j,1,v+1)
                {
                    if(i==j)continue;
                    cin>>d[i][j];
                }           
        }
        tsp(v);
        int ans = 1e9;
        fr(i,1,v+1)
        {       
             // cout<<((1<<v)-1)<<" "<<i<<endl;
             // cout<<dp[(1<<v)-1][i]<<endl;
            ans = min(ans,dp[(1<<v)-1][i]+d[i][1]);
        }
        cout<<ans<<endl;
   }
}                       