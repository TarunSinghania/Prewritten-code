#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define ll long long
#define ull unsigned long long
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define FR(i,a,b) for(int i =a ; i > b; i--) 
#define frj(j,a,b) for(int j =a ; j < b; j++)
#define FRE(i,a,b) for(int i =a ; i >= b; i--) 
#define fre(i,a,b) for(int i =a ; i <= b; i++)
#define fra(s) for(auto it = s.begin(); it != s.end() ; ++it)
 
#define mkp make_pair 
#define pb push_back
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
//#define c(a,b) cout<<a<<"--"<<b<<endl;
#define frv(i,a,v) for(int i =  a ; i < v.size() ; ++i)
#define cp(a,i)  cout<<a[i].first<<" "<<a[i].second<<endl;
#define pp(a) cout<<a.first<<" "<<a.second<<endl;
 
 
#define pr(a,n) fr(i,0,n){cout<<a[i]<<" ";}cout<<endl;
#define prv(v)   for(auto it = v.begin() ; it!= v.end() ;++it){cout<<*it<<" ";}cout<<endl;
#define prpv(v)   for(auto it = v.begin() ; it!= v.end() ;++it){cout<<"("<<it->first<<","<<it->second<<")";}cout<<endl;
//#define prs(s)   for(auto x : s){cout<<(*x).first<<","<<(*x).second<<")";}cout<<endl;
#define all(x)           x.begin(), x.end()
 
#define prm(m,r,c) fr(i,0,r){frj(j,0,c){cout<<m[i][j]<<" "; }cout<<endl;}
#define fillm(m,r,c,k) fr(i,0,r)frj(j,0,c)m[i][j]=k;
#define rep(x) int x;cin>>x;while(x--)
 
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;
 
#define PI 3.14159265358979323846;
#define MAXK 505
ll INF = 1e17;
ll MOD  = 998244353;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
           
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
#define MAXN  1005

void px(int x,int d){
//d is number of digits
vector<int> v;
for(int i = d-1 ; i>=0 ;i--)
    v.pb((x>>i)&1);
prv(v);
}


int main(){

        int mask = 31;
        px(mask,5);

        for(int i = mask; i > 0 ;  i = (i-1)&mask)
        {
            px(i,5);
        }
        return 0;
}