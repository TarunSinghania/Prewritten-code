#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fr(i,a,b) for(int i =a ; i < b; i++)
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


#define MOD 1000000007


void ae(vector<int> v[] , int x ,int y){

  v[x].push_back(y);

}


void pr12(vector<int> t[],int size)
{
  fr(i,1,size){
  cout<<i<<"-->";
  for(auto it = t[i].begin(); it != t[i].end() ;++it)
  cout<<*it<<"-- ";
   cout<<endl;
  }


}

void pre(vector< pair< int ,  pair < int ,int> > >v )
{
  for(auto it  =v.begin() ; it!= v.end() ; ++it)
  {
    cout<<it->first<<" "<<it->second.first<<"--"<<it->second.second<<endl;
  }
}



bool cmp(pair<int, pair<int ,int> > a ,pair<int, pair<int ,int> > b ){
if(a.first!=b.first)
  return(a.first<b.first);
else
  return(a.first+ a.second.first + a.second.second)<(b.first+b.second.first+b.second.second);

}

//modified initialize function:
  void initialize( int Arr[ ], int size[ ],int N)
    {
        for(int i = 0;i<N;i++)
        {
    Arr[ i ] = i ;
    size[ i ] = 1;
    }
    }




     //finding root of an element
  int root(int Arr[ ],int i)
    {
        while(Arr[ i ] != i)           //chase parent of current element until it reaches root
        {
         i = Arr[ i ];
        }
        return (int)i;
    }


 bool find(int A, int B,int Arr[])
    {
        if( root(Arr,A) == root(Arr,B) )       //if A and B have the same root, it means that they are connected.
        return true;
        else
        return false;
    }


  void weighted_union(int Arr[ ],int size[ ],int A,int B)
    {
        int root_A = root(Arr,A);
        int root_B = root(Arr,B);
    
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


void pr(int arr[],int r){
    for (int i = 0; i < r; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

  
void kruskals(  vector< pair< int ,  pair < int ,int> >  > e,int v)
{


int arr[v+1];
int size[v+1];
auto it = e.begin();
int ce =0 ;//current edges
int tw = 0;//total wiegth
initialize(arr,size,v+1);
while(it!=e.end()&& ce <v)
{

    int w = it->first;
    int i = it->second.first;
    int j = it->second.second;

    if(!find(i,j,arr))
      {weighted_union(arr,size,i,j);
      ce++;
      tw+=w;}
    ++it;
}

pr(arr,v+1);
cout<<tw<<endl;


}
 



int main()
{
  int v,edges;
  cin>>v>>edges;


  vector< pair< int ,  pair < int ,int> >  > e;

  int w,a,b;

  fr(i,0,edges){
    cin>>a>>b>>w;
    e.push_back(mkp(w, mkp(a,b)));
  }



sort(e.begin(),e.end(),cmp);

kruskals(e,v);


return 0 ;


}   