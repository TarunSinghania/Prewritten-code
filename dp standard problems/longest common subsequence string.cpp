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
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int x=n;
    int y=m;
    while(x && y)
    {
        if(a[x]==b[y])
        {
            ans[++sz]=a[x];
            x--;
            y--;
        }
        else
        {
            if(dp[x][y]==dp[x-1][y])
            {
                x--;
            }
            else
            {
                y--;
            }
        }
    }
    for(int i=sz;i>=1;i--)
    {
        cout<<char(ans[i]);
    }
    cout<<"\n";
    return 0;
}