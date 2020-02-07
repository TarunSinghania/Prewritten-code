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
#define mp(a) cout<<a->first<<" "<<a->second<<endl;
//sum array
#define sa(n) int a[n]; int s[n];cin>>a[0];s[0]=a[0];fr(i,1,n) {cin>>a[i];s[i]=s[i-1]+a[i];}
#define sa1(n) int a[n+1]; long long s[n+1]; a[0]=0; s[0]=0;cin>>a[1];s[1]=a[1];fr(i,2,n+1) {cin>>a[i];\
s[i]=s[i-1]+a[i];}

constexpr auto PI  = 3.14159265358979323846L;
constexpr auto oo  = numeric_limits<int>::max() / 2 - 2;
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;


#define MOD 1000000007
#define maxv 200005


int Arr[maxv];
int size[maxv];

void initialize(int N)
{
    for(int i = 0;i<N;i++)
    {
        Arr[ i ] = i ;
        size[ i ] = 1;
    }
}


int root(int i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ; 
        i = Arr[ i ]; 
    }
    
    return i;
}



void weighted_union(int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);

      //cout<<root_A<<"--"<<root_B<<endl;
  if(root_A == root_B)
    {
    return;
    }
    if(size[root_A] < size[root_B ])
    {
    Arr[ root_A ] = Arr[root_B];
    size[root_B] += size[root_A];
    }
    else
    {
    Arr[ root_B ] = Arr[root_A];
    size[root_A] += size[root_B];
    }

}


bool find(int A,int B)
{
    if( root(A)==root(B) )       //if A and B have the same root, it means that they are connected.
    return true;
    else
    return false;
}

int main(){
    int a,b;
    cin>>a,b;
  
    weighted_union(a,b);    
    find(a,b);
    root(a);

    return 0;
}