   #include<bits/stdc++.h>
     using namespace std;
    #define ll long long
    #define fr(i,a,b) for(int i =a ; i < b; i++)
    #define frj(j,a,b) for(int j =a ; j < b; j++)
    #define fre(i,a,b) for(int i =a ; i <= b; i++)
    #define fra(s) for(auto it = s.begin(); it != s.end() ; ++it)

    #define mkp make_pair 
    #define pb push_back
    #define pii pair<int,int>
    #define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
    #define c(a,b) cout<<a<<"--"<<b<<endl;
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
    constexpr auto PI  = 3.14159265358979323846L;
    constexpr auto eps = 1e-6;
    constexpr auto mod = 1000000007;
    #define MOD 1000000007
   // #define maxv 200005
    #define MAXN 1000001

  template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
  template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

  void bellman_ford(vector<pair<pair<int,int>,int> >e,int v,int source) 
{  
   ll dist [v+1]={INT_MAX};
    dist[source]=0;
    //self negative loops will be detected
    //negatiev  wieight cycles will be detected fir disconnected also from the vertex
    fr(i,0,v)
    {
      for(auto a : e)
      if(dist[a.first.second]>dist[a.first.first] + a.second) //note if you use int max with int then add will negative number error
          dist[a.first.second]=dist[a.first.first]+a.second;
    }
    ll check[v+1];
    fr(i,0,v+1)
    check[i]=dist[i];

      for(auto a : e){
      if(check[a.first.second]>check[a.first.first] + a.second)
          check[a.first.second]=check[a.first.first]+a.second;        
      }
    //pr(dist,v+1); 
    //pr(check,v+1); 
    bool negative_cycles_exist=false;
    fr(i,0,v+1)
    if(check[i]<dist[i])
      negative_cycles_exist = true;
    //use dist for minimumdistance between 
    if(negative_cycles_exist)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;

}
  int main(){

    int v,E,x,y,z;
    cin>>v>>E;
    vector<pair<pair<int,int>,int> >e;
    fr(i,0,E)
    { //x--y with wiegth w for directed 
      //for unidireected add two y--x with w
      cin>>x>>y>>z;
      e.pb(mkp(mkp(x,y),z));
     // e.pb(mkp(mkp(y,x),z));
    }
    bellman_ford(e,2,1);
    return 0;
  }