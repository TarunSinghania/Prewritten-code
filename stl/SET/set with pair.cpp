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

  constexpr auto PI  = 3.14159265358979323846L;
  constexpr auto oo  = numeric_limits<int>::max() / 2 - 2;
  constexpr auto eps = 1e-6;
  constexpr auto mod = 1000000007;


 #define MOD 1000000007
  #define maxv 200005
  #define mx 505
struct cmp1
{
      bool operator()(const pair<int,int> &a ,const pair<int,int> &b)
  {
      return(a.first- a.second >= b.first - b.second);
  }

};

  set< pair<int, int>,cmp1> v1;
    
   



  struct comp{

    bool operator()(const pair<long long ,long long> &a,const pair<long long ,long long > &b){
        if(a.first == b.first)
            return a.second < b.second;
        else
            return a.first > b.first;
    //equality when !(a<b) && !(b<a)
}

    
  set<pair<ll,ll> > v;

  //remember to always return false when two elements are equal or else they will
  //get inserted multiple times
  //struct comp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
      if(a.first==b.first)
        //i used <= 2 times 7,2 will be inserted and find wont work
        return (a.second<b.second);
      else
        return a.first<b.first;        
    }
};

int main()
{
set<pair<int,int>,comp>s;
s.insert({7,2});
s.insert({7,2});
for(auto x : s){
  cout<<x.first<<" "<<x.second<<endl;
}


#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i =a ; i < b; i++)

struct comp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
      if(a.first==b.first)
        return (a.second<=b.second);
      else
        return a.first<b.first;        
    }
};

int main()
{
set<pair<int,int>,comp>s;
s.insert({7,2});
s.insert({7,2});
for(auto x : s){
  cout<<x.first<<" "<<x.second<<endl;
}
auto it = s.find({7,2});
if(it == s.end())
  cout<<"ne"<<endl;

  return 0;
}



///reason insertion in set takes place using comparator or by default using <

#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i =a ; i < b; i++)
struct t{
  int a;  
  t(int x){
    a=x;
  }

  bool operator==(const t& rhs)const{
    return a==rhs.a;
  }
  bool operator < (const t& rhs )const{
      return a<=rhs.a;
  }

};

int main()
{
 set<t>s2;

 fr(i,0,10){
  t t2 = t(i);
  t t3 = t(i);

  s2.insert(t2);
  s2.insert(t3);
  }

for(auto x: s2){
   cout<<x.a<<endl;
}
  return 0;
}
//
//https://codeforces.com/blog/entry/9604
//http://www.cplusplus.com/reference/algorithm/lexicographical_compare/
//now less than < or comp would insert comparing a<b
and where false
it checks if!(a<b) && !(b<a)
  if this is true that means elements are equal
  or else 
  it inserts


