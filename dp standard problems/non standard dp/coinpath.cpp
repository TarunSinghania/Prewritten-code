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


vector<int>  coinpath(vector<int>& v, int jmp) {
       
        int n = v.size();
        int dp[n];
        int lv[n];//last vertice befor visiting this;
        fr(i,0,n)
            lv[i]=-1;
        lv[0]=0;
        fr(i,0,n)
            dp[i]=INT_MAX;
        //dp i represents minimum coins needed to reach there
        dp[0]=0;//v[0];
        fr(i,0,n)
        {
            if(dp[i]==INT_MAX || v[i] == -1)
                continue;
            for(int  j = 1 ; j <= jmp ; j++)
            {

                if(i+j<n)
                {
                    if(dp[i]+v[i] < dp[i+j])
                    lv[i+j]=i;                        
                    dp[i+j]=min(dp[i]+v[i],dp[i+j]);
                }
            }
        }

        pr(dp,n);
        pr(lv,n);
        vector<int> path,np;
        int i = n-1;
        path.pb(i+1);
        while(lv[i]!=i)
        {
            i = lv[i];  
            if(i==-1)
                return np;
            path.pb(i+1);   
        }
        return path;
       // select path
            
    }

int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    fr(i,0,n)
    {
    cin>>v[i];
    }
    int maxjump;
    cin>>maxjump;
    vector<int> path = coinpath(v,maxjump);
    reverse(all(path));
    prv(path);

return 0;

  }

