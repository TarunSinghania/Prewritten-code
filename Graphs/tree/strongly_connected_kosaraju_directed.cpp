#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define ll long long
#define int long long
#define ull unsigned long long
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define FR(i,a,b) for(int i =a ; i > b; i--) 
#define frj(j,a,b) for(int j =a ; j < b; j++)
#define FRE(i,a,b) for(int i =a ; i >= b; i--) 
#define fre(i,a,b) for(int i =a ; i <= b; i++)
#define fra(s) for(auto it = s.begin(); it != s.end() ; ++it)
 
#define mkp make_pair 
#define pb push_back
#define pii pair<int,int>
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
//#define c(a,b) cout<<a<<"--"<<b<<endl;
#define frv(i,a,v) for(int i =  a ; i < v.size() ; ++i)
#define cp(a,i)  cout<<a[i].first<<" "<<a[i].second<<endl;
#define pp(a) cout<<a.first<<" "<<a.second<<endl;
//sum array
#define sa(n) int a[n]; int s[n];cin>>a[0];s[0]=a[0];fr(i,1,n) {cin>>a[i];s[i]=s[i-1]+a[i];}
#define sa1(n) int a[n+1]; long long s[n+1]; a[0]=0; s[0]=0;cin>>a[1];s[1]=a[1];fr(i,2,n+1) {cin>>a[i];\
s[i]=s[i-1]+a[i];}
 
#define pr(a,n) fr(i,0,n){cout<<a[i]<<" ";}cout<<endl;
#define prv(v)   for(auto it = v.begin() ; it!= v.end() ;++it){cout<<*it<<" ";}cout<<endl;
#define prs(s)   for(auto x : s){cout<<x<<" ";}cout<<endl;
#define all(x)           x.begin(), x.end()
 
#define prm(m,r,c) fr(i,0,r){frj(j,0,c){cout<<m[i][j]<<" "; }cout<<endl;}
#define fillm(m,r,c,k) fr(i,0,r)frj(j,0,c)m[i][j]=k;
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;
#define MOD 1000000007
#define maxv 100005
#define MAXN 100001
#define PI 3.14159265358979323846;
#define MAX 100005
#define INF 1e9
stack<int> s;
vector<int> adj[MAX],adjr[MAX];
vector<vector<int> > cc;
vector<int> temp;
int c[MAX];
bool vi[MAX];
int v;

void dfsu(int n){
    vi[n]=true;
    for(auto x: adj[n])
    {
        if(!vi[x])
            dfsu(x);
    }
    s.push(n);
}

void dfs()
{
    fr(i,1,v+1)
        vi[i]=false;

    fr(i,1,v+1){
        if(!vi[i])
            dfsu(i);
    }
}

void dfscc(int n)
{
    vi[n]=true;
    for(auto x: adjr[n])
    {
        if(!vi[x])
            dfscc(x);
    }
    temp.pb(n);
}


void dfsc(){

    fr(i,1,v+1)
        vi[i]=false;
    while(!s.empty())
    {   int n = s.top();s.pop();
        if(!vi[n]){
            dfscc(n);
            cc.pb(temp);
            temp.clear();
        }
    }
}




main()
{
    
    cin>>v;
    fr(i,1,v+1)
        cin>>c[i];      
    int e;
    cin>>e;
    fr(i,0,e)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adjr[b].pb(a);
    }
    dfs();
    dfsc();
    //strongly connected components in vector cc;
  
    
}