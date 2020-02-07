  #include <bits/stdc++.h>

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


  constexpr auto PI  = 3.14159265358979323846L;
  constexpr auto oo  = numeric_limits<int>::max() / 2 - 2;
  constexpr auto eps = 1e-6;
  constexpr auto mod = 1000000007;


  #define MOD 1000000007
  #define maxv 200005
  #define mx 505





  int main()
  { //1133D
  
    int n,a,b,g;
    map < pair<int,int>,int> v;
    cin>>n;
    int a1[n],a2[n];

  //cout<<"aw"<<endl;

    fr(i,0,n)
    {
      cin>>a1[i];
    }
    fr(i,0,n)
    {

      cin>>a2[i];
    }
    int cq = 0;
    fr(i,0,n)
    { 
       a=abs(a1[i]);
       b=abs(a2[i]);
       g=__gcd(a,b);
       if(a==0 && b ==0)
        {cq++;continue;}
       if(a==0)
        continue;
      if(b==0)
        {v[mkp(0,1)]++;continue;}
       a=a1[i]/g;
       b=-a2[i]/g;
       if(a<0 && b<0){
        a=abs(a),b=abs(b);
        }
      else if(a<0 || b <0)
       {
         a=abs(a);b=abs(b);b=-b;
       }
//       cout<<b<<" "<<a<<endl;
       v[mkp(b,a)]++;
    }
 int maxm =0;
 for (auto const &entry: v)
    {
      maxm = max(maxm,entry.second);
    }
    cout<<maxm+cq<<endl;
    return 0;
  } 
    
  