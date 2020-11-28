#include <iostream>
#include <cstdio>
 
using namespace std;
 
const int N=3000+5;
 
int n,a[N];
int m,b[N];
int dp[N][N];
int ans[N],sz=0;

string s,t;
 
int main()
{
    cin>>s>>t;
    n=s.size();
    m=t.size();
    for(int i=1;i<=n;i++)
    {
        a[i]=(s[i-1]);
    }
    for(int i=1;i<=m;i++)
    {
        b[i]=(t[i-1]);
    }
    int mx = 0,r=0,c=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
                if(dp[i][j]>mx)
                {
                    mx = dp[i][j];
                    r= i;
                    c =j;
                }
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    for(int i  =1 ; i <=n;i++)
    {
        for(int j =1; j <=m ; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    if(mx == 0)
    {
        cout <<"nocommonsubstring"<<endl;
    }
    int x=r;
    for(int i = 1 ; i <= mx ; i ++)
    {
        ans[++sz] = s[--x];
    }
    for(int i=sz;i>=1;i--)
    {
        cout<<char(ans[i]);
    }
    cout<<"\n";
    return 0;
}