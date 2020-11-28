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

void sieve() 
{ 
    spf[1] = 1; 

    for (int i=2; i<MAXN; i++) 
        spf[i] = i; 
  
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
         if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
   
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 


int main()
{
  sieve();
int t;
cin>>t;
while(t--)
{ 
    ll n,p,s;
    cin>>n;
    vector<int> a,b;
    if(n < MAXN)
    {
    
    if(n%2==0){
      a = getFactorization(n);
      b = getFactorization((n+1/2));}
    else  {
      a = getFactorization(n+1);
      b = getFactorization(n/2);
    }

    fr(i,0,a.size())
        cout<<a[i]<<endl;

    a.push_back(b);


    }

}

return 0 ;
}