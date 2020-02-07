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


void px(int x){

vector<int> v;
for(int i = 19 ; i>=0 ;i--)
    v.pb((x>>i)&1);
prv(v);
}

void px(int x,int d){
//d is number of digits
vector<int> v;
for(int i = d-1 ; i>=0 ;i--)
    v.pb((x>>i)&1);
prv(v);
}
//let the total digits be D
//if D =3 111 110 101 011 010 011...
//1<<D = 1000 == 8
//dp[mask][d]
//sum over subsets of a particular mask[] by changing the first [d] digits
#define D 20
ll dp[(1<<D)][D+1];
ll dp2[1<<D];
int main(){



int n;
cin>>n;
int total = pow(2,n);

int a[total]={0};
fr(i,0,total){
    int x;
    cin>>x;
    a[i]=x;

}

//base case

for(int mask = 0;mask<(1<<D) && mask < total;mask++)
{
        //cout<<mask<<a[mask]<<endl;
        dp[mask][0]+=a[mask];
        dp2[mask]=a[mask];
    
}

for(int mask = 0;mask<(1<<D) && mask < total;mask++)
{   
        //considering i+1 bits to have changed starting from 1 bit to have changed
        for(int i = 0 ; i <D ; i ++)
        {
            dp[mask][i+1] = dp[mask][i];
            if(mask&(1<<i)){
                dp[mask][i+1] +=  + dp[mask^(1<<i)][i];
            }
        }
}

//cout<<dp[7][9]<<endl;
  
//optimised dp for the same thing 
//here abouve we have a matrix of n*D 
//----------------------D
//|
//|
//n
//for each mask we call a mask of upeer row and D
//so insteadof formulating it foe each row 
//we can do it for each coloumn
//we can see calls are being made for each coloumn to a prevoius coloumn D
//one can reduce this to n*2 as all calss as we move from top to n for a d to preious d
//one extra point we can reduce the state to n*1
//as all calss while moving from top to bottom row wise are made to one upper row(if dth bit bit is set during the dth iteration) ans itslef
//                                                                 []
//                                                                 []
//                                                                 []---|
//                                                                 []   |
//                                                                 []---|
// example for d = 3 101 calls 101 ans 001 and updates it,and hence it cannot be used for d= 3 however no more calls will be made do it during d = 3 ; hence
//dp doesnt invlaidate ,when d= 4 it will be called;


for(int i = 0  ; i < D ; i++)
    {
        for(int mask =  0 ; mask<(1<<D); mask++)
        {
            if(mask&(1<<i))
            dp2[mask] +=dp2[mask^(1<<i)];               
        }
    }
cout<<dp2[3]<<endl;
/*
    ll ans=0;
    ll xr=(1<<20)-1;
    for(ll i=0;i<total;i++){
        ans+=(dp2[v[i]^(xr)]);
    }
    cout<<ans<<"\n";
*/
}