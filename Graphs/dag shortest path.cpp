   #include<bits/stdc++.h>
  using namespace std;
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
    constexpr auto PI  = 3.14159265358979323846L;
    constexpr auto eps = 1e-6;
    constexpr auto mod = 1000000007;
    #define MOD 1000000007
    #define maxv 100005
    #define MAXN 100001

  template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
  template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }


    const int INF= 1e9 +5;

    vector<int> topsort(int v,vector<pair<int, int>  > adj[])
    {
      int in[v+1]={0};
      fr(i,1,v+1){
      for(auto x : adj[i])
      {
          in[x.first]++;
      }
      }

      vector<int> ans;
      queue<int> q ;
      fr(i,1,v+1)
      if(in[i]==0)
        q.push(i);
      while(!q.empty())
      {
          int  k= q.front();
          q.pop();
          ans.pb(k);
          for(auto x : adj[k])
            if(--in[x.first]==0)
              q.push(x.first);
      }
      if(int(ans.size()) != v)
        exit(2);//error not a dag

      return ans;
    }


int main(){
      
      speed;
      int v,e;
      cin>>v>>e; 
      vector<pair<int,int> > adj[v+1];
      int x,y,w;
      fr(i,0,e)
      { //path from x to y with weight w;

        cin>>x>>y>>w;
        adj[x].pb(mkp(y,w));
      }

      vector<int> tp = topsort(v,adj);
      int dist[v+1]={INF};
      fr(i,0,v+1)
      dist[i]={INF};//use -INF for longest paths and change comparison
      //do not use INT_max will give overflow
     
      //supply starting index 
      int start = 2;
      dist[start] = 0;

      for(auto x : tp)
      {
         
          for(auto y : adj[x])
              if(dist[y.first] > dist[x] + y.second)//use < for longest path and change -INF
                dist[y.first] = dist[x] + y.second; 
      }
      pr(dist,v+1);
      
      return 0;

  }

