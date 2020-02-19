#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define pb push_back
#define ll long long
#define mkp make_pair 
#define MAX 200005
#define MAX_LOG 20
#define INF 10000000000000
#define pr(a,b) fr(i,0,b){cout<<a[i]<<" ";}cout<<endl;
#define prs(s) for(auto x : s){cout<<x.first<<"#"<<x.second<<" ";}cout<<endl;
#define all(x)           x.begin(), x.end()
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define endl '\n'              
        
int st[MAX][MAX_LOG+1];
int n;
int a[MAX];

void preprocess(){

    fr(i,0,n+1)
      st[i][0]=a[i];

    fr(j,1,MAX_LOG+1)
    {
      for(int i = 0 ; i + (1<<j) <= n;i++)
      {
          st[i][j]=st[i][j-1]+ st[i+ (1<<(j-1))][j-1];
      }
    }    

}

ll sum(int l,int r){

    long long sm = 0;
    for (int j = MAX_LOG; j >= 0; j--) {
        if ((1 << j) <= r - l + 1) {
            sm += st[l][j];
            l += 1 << j;
        }
      }
        return sm;
}
main()
{
    speed;
    cin>>n;
    fr(i,0,n)
    cin>>a[i];
    preprocess();
    int q;
    cin>>q;
    fr(i,0,q)
    {
      int a,b;
      cin>>a>>b;
      cout<<sum(a,b)<<endl;

    }   
}            



