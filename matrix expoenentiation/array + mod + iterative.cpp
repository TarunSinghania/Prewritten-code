
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



//#define MOD 1000000007
//#define MOD 998244353
ll MOD ;

#define N 10000001

void ml(ll a[3][3] , ll b[3][3])
{
  ll mm[3][3] ;
  fr(i,0,3)
    frj(j,0,3)
        {
          mm[i][j] = 0 ;
            frk(k,0,3)
              mm[i][j]+= (a[i][k] * b[k][j]) %MOD;
       }


      fr(i,0,3)
        frj(j,0,3)
          a[i][j] = mm[i][j];
   
      
   
}


void pow( ll a[3][3] , int n)
{
  ll r[3][3]={{1,0,0},{0,1,0},{0,0,1}};

  while(n>0){
    if(n%2 == 1)
        ml(r,a);
    ml(a,a);
    n=n/2;
  }

  fr(i,0,3)
    frj(j,0,3)
      a[i][j] = r[i][j];
      
    
  
  
}


ll solve(ll a[3][3] , int n ,int c )
{
  if(n<=2)
    return 1 ;

  pow(a,n-2);

//  cout<<a[0][0]<<a[0][1]<<a[0][2]<<endl;

  return (a[0][0] + a[0][1] + a[0][2]*c ) %MOD;
 
}




int main()
{

int t;cin>>t;

while(t--)
{
ll a,b,c,n;

cin>>a>>b>>c>>n>>MOD ;
ll m[3][3];

fr(i,0,3)
  frj(j,0,3)
    m[i][j] = 0;

m[0][0] = a ;
m[0][1] = b ;
m[0][2] = 1 ;
m[1][0] = 1 ;
m[2][2] = 1 ;

//ll r[3][3]={{1,0,0},{0,1,0},{0,0,1}};
//ml(r,m);
cout<<solve(m,n,c)<<endl;



}

return 0 ;
}