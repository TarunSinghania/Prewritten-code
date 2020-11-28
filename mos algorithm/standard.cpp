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

const int N = 2e5 + 5;
const int Q = 2e5 + 5;
const int M = 1e6 + 5;
const int SZ = sqrt(N) + 1;
int mp[1000005];
int q;
int ans[Q];
int a[N];
int cnt;
struct data
{
  int l, r, idx;
}qr[Q];


bool comp(struct data &d1, struct data &d2)
{
  int b1 = d1.l / SZ;
  int b2 = d2.l / SZ;
  if(b1 != b2)
    return b1 < b2;
  else
    return d1.r < d2.r ;
}

inline void add(int x)
{
  mp[x]++;
  //cout<<"added"<<x<<endl;
  if(mp[x]==1){
    cnt++;
    }
  
}

inline void remove(int x){
  mp[x]--;
  if(mp[x]==0){
    cnt--;
  }
}
 

void mo()
{
  sort(qr + 1, qr + q + 1, comp);
  int l = 1, r = 0;
  for(int i=1;i<=q;i++)
  {
  //  out<<qr[i].l<<" "<<qr[i].r<<endl;
   /// cout<<"stage 1"<<endl;
    while(r < qr[i].r) add(a[++r]);
  //  cout<<"stage 2"<<endl;
    while(r > qr[i].r) remove(a[r--]);
   // cout<<"stage 3"<<endl;
    while(l < qr[i].l) {remove(a[l++]);}
    //cout<<"stage 4"<<endl;
    while(l > qr[i].l) add(a[--l]);
    
    ans[qr[i].idx] = cnt;
  }
}
int main() {
  speed; 
  int n;
  cin>>n;
  fr(i,1,n+1)
  cin>>a[i];

  cin>>q;
  fr(i,1,q+1)
  {
    cin>>qr[i].l>>qr[i].r;
    qr[i].idx=i;
  }
  mo();
  fr(i,1,q+1)
  {
      cout<<ans[i]<<endl;
  }
    return 0;
}