//pizza/07 
#include <bits/stdc++.h> 
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define fillm(m,r,c,k) fr(i,0,r)fr(j,0,c)m[i][j]=k;
#define prm(m,r,c) fr(i,0,r){fr(j,0,c){cout<<m[i][j]<<" "; }cout<<endl;}
#define pr(a,n)fr(i,0,n)cout<<a[i]<<",";cout<<endl;
#define endl '\n'
#define MOD 1000000007
#define INF 1000000000
#define prv(v) for(auto x: v)cout<<x<<",";cout<<endl;
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define MAX  1000005 
int n;
int a[MAX];
int lis[MAX];

void LIS(){
    vector<int> ml(n+1,INT_MAX);
    ml[0]= -1;
    ml[1]=a[0];
    lis[0]=1;
    for(int i = 1; i  < n ; i++){
        int l =0;
        int r =n;
        while(l<r){
            int m = l + (r-l)/2;
            if(ml[m]<a[i])
              l =m+1;
            else
              r =m;
        }
        lis[i]=l;
        ml[l]=min(ml[l],a[i]);
    }
}
main(){
    speed;
    cin>>n;
    fr(i,0,n)cin>>a[i];
    LIS();
    pr(lis,n+1);

}