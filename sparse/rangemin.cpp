#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define pb push_back
#define ll long long
#define mkp make_pair 
#define MAX 200005
#define MAX_LOG 20
#define INF 1e9 +1
#define pr(a,b) fr(i,0,b){cout<<a[i]<<" ";}cout<<endl;
#define prs(s) for(auto x : s){cout<<x.first<<"#"<<x.second<<" ";}cout<<endl;
#define all(x)           x.begin(), x.end()
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define endl '\n'              
        
int st[MAX][MAX_LOG+1];
int n;
int a[MAX];
int lg[MAX];

void preprocessmin()
{
     fr(i,0,n+1)
      st[i][0]=a[i];

    fr(j,1,MAX_LOG+1)
    {
      for(int i = 0 ; i + (1<<j) <= n;i++)
      {
          st[i][j]=min(st[i][j-1],st[i+ (1<<(j-1))][j-1]);
      }
    }    
  
  lg[1] = 0;
  for (int i = 2; i <= MAX; i++)
  lg[i] = lg[i/2] + 1;
}


int rmq(int l,int r){
 
    int mn = INF;
    for (int j = MAX_LOG;j >= 0; j--)
    {
        if ((1 << j) <= r - l + 1)
        {
            mn = min(mn,st[l][j]);
            l += (1 << j);
        }
    }
    return mn;
}

int frmq(int l,int r)
{

  int j = lg[r - l + 1];
  return min(st[l][j], st[r - (1 << j) + 1][j]);
}
main()
{
    speed;
    cin>>n;
    fr(i,0,n)
    cin>>a[i];
    preprocessmin();
    int q;
    cin>>q;
    fr(i,0,q)
    {
      int a,b;
      cin>>a>>b;
      cout<<frmq(a,b)<<endl;
    }   


}            



