  #include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define frj(i,a,b) for(int j =a ; j < b; j++)
#define frk(i,a,b) for(int k = a; k<b;k++)
#define fre(i,a,b) for(int i =a ; i <= b; i++)
#define frej(j,a,b) for(int j =a ; j <= b; j++)
#define fra(s) for(auto it = s.begin(); it != s.end() ; ++it)
#define pr(x) std::cout << #x << ':' << x << std::endl
#define mkp make_pair 
#define pb push_back
#define pii pair<int,int>
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define c(a,b) cout<<a<<"--"<<b<<endl;
#define frv(i,a,v) for(int i =  a ; i < v.size() ; ++i)
#define cp(a,i)  cout<<a[i].first<<" "<<a[i].second<<endl;
#define mp(a) cout<<a->first<<" "<<a->second<<endl;
#define pp(a) cout<<a.first<<" "<<a.second<<endl;
//sum array
#define sa(n) int a[n]; int s[n];cin>>a[0];s[0]=a[0];fr(i,1,n) {cin>>a[i];s[i]=s[i-1]+a[i];}
#define sa1(n) int a[n+1]; long long s[n+1]; a[0]=0; s[0]=0;cin>>a[1];s[1]=a[1];fr(i,2,n+1) {cin>>a[i];\
s[i]=s[i-1]+a[i];}



#define MOD 1000000007
//#define max 1000000009
#define MAXN  1000001

int spf[MAXN];

   
vector<int> getFactorization(int x) 
 {  
    vector<int> ret;    
   
    if(x == 1){
        ret.push_back(1);
        return ret;
    }

    int n = x;
    while(n%2 == 0){
        ret.push_back(2);
        n = n/2;
    }

    for(int i = 3; i<=sqrt(n) ;i=i+2)
    { 

        while(n%i == 0)
            {
                n = n/i;
                ret.push_back(i);
            }
    } 
    if(n>2)
        ret.push_back(n);

    return ret; 
} 


int main()
{
    int n;
   
    vector<int> a;
    cin>>n;
      a = getFactorization(n);
 
        

    fr(i,0,a.size())
        cout<<a[i]<<endl;


return 0 ;
}

vector<ll> getFactorization(ll x) 
 {  
    vector<ll> ret;    
   
    if(x == 1){
        ret.push_back(1);
        return ret;
    }

    ll n = x;
    while(n%2 == 0){
        ret.push_back(2);
        n = n/2;
    }
    for(int i = 3; i<=sqrt(n) ;i=i+2)
    { 
    //cout<<i<<" "<<n<<endl;

        while(n%i == 0)
            {
                n = n/i;
                ret.push_back(i);
            }
    } 
    if(n>2)
        ret.push_back(n);

    return ret; 
} 