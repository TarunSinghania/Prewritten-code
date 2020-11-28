    //0(2^n*n)//time
    //0(2^n)//space
  //time saving approach saving in dp and graph data of vertices
//https://codeforces.com/blog/entry/337?
    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define fr(i,a,b) for(int i =a ; i < b; i++)
    #define mkp make_pair 
    #define pb push_back
    #define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
    #define sz 500;
    #define ff first
    #define ss second
    #define MAX 10005
    #define pr(a,n) fr(i,0,n){cout<<a[i]<<" ";}cout<<endl;
    #define MAXBLOCKS 10000
    #define all(x) x.begin(),x.end()
    #define INF 10000000
    #define MOD 1000000007
    #define prm(m,r,c) fr(i,0,r){fr(j,0,c){cout<<m[i][j]<<" "; }cout<<endl;}
    #define fillm(m,r,c,k) fr(i,0,r)fr(j,0,c)m[i][j]=k;
    #define endl '\n'
    #define MAXVERTICES 10
    #define prv(v) for(auto s: v){cout<<s<<" ";}cout<<endl; 
     
    // 5 6
    // 1 2 
    // 1 3
    // 1 4
    // 2 3
    // 1 5
    // 3 4
     
    int n,m;//max 16
    int dp[1<<MAXVERTICES];
    //Let dp'[mask] contain the data of the subset consisting of those vertices j for which there exists a Hamiltonian walk over the subset mask ending in j
    int g[MAXVERTICES][MAXVERTICES];
    int d[MAXVERTICES][MAXVERTICES];
    int gmask[MAXVERTICES];
     
    void init(int n)
    {
        fr(j,0,1<<n)
        dp[j]=0;
        fr(i,0,n){
          gmask[i]=0;
          fr(j,0,n)
            g[i][j]=0;
        }
    }
    void base()
    {
      fr(i,0,1<<n)
      {
        if(__builtin_popcount(i)==1)
        {
          fr(bit,0,n)
          {
            if(i&(1<<bit))
              dp[i]=(1<<bit);
          }
        }
      }
    }
    void work()
    {
      fr(mask,1,1<<n)
      {
        fr(j,0,n)
        {
            if(!(mask&(1<<j)))continue;
     
            int nmask = mask^(1<<j);
            // cout<<mask<<"nmask"<<nmask<<"j"<<j<<endl;
            // cout<<dp[nmask]<<" "<<gmask[j]<<endl;
            if(dp[nmask]&gmask[j])
            {dp[mask]+=(1<<j);}
     
          
        }   
      }
     
    }
     
    int result(){
      //return total number hamiltoian paths
      //cout<<dp[(1<<n)-1]<<endl;
      return (dp[(1<<n)-1]>0?1:0);
    }
    main() {
        speed; 
        int t ;
        cin>>t;
        while(t--){
      cin>>n>>m;
      init(n);
      set<pair<int,int> > s;
      fr(i,0,m)
      {
        int a,b;
        cin>>a>>b;
        a--;b--;
        int x = min(a,b);
        int y = max(a,b);
        if(x!=y){
        //to remove self loops
        s.insert(mkp(x,y));
     
        g[a][b]=1;g[b][a]=1;
        }
       // cin>>d[a][b];
        //d[b][a]=d[a][b];
      }
      for(auto x: s)
      {
        int a = x.first;
        int b = x.second;
        gmask[a]+=(1<<b);
        gmask[b]+=(1<<a);
      }
     
      base();
      work();
      if(result())
        cout<<"Yes"<<endl;
      else
        cout<<"No"<<endl;
     
      }
    } 