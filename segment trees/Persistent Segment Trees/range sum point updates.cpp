#include <bits/stdc++.h>
using namespace std;
 //psegtree spoj
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5+5;
const int LG = log2(N) + 1;
 
int a[N];
int n, m, ct=0, num=0;
int root[N], st[21*N], li[21*N], ri[21*N];
 
int build(int L, int R)
{
  int nid = ++ct;
  if(L==R){
    //init
    st[nid] = a[L];
    return nid;
  }
  int M = (L+R)/2;
  li[nid] = build(L, M);
  ri[nid] = build(M+1, R);
  st[nid] = st[li[nid]] + st[ri[nid]];
  return nid;
}
 
int update(int id, int L, int R, int pos,int val)
{
  int nid = ++ct;
  if(L==R)
  {
    //adding one here for increasing count 
    st[nid] = st[id] + val;
    return nid;
  }
  int M = (L+R)/2;
  li[nid] = li[id];
  ri[nid] = ri[id];

  if(pos <= M)
    li[nid] = update(li[id], L, M, pos,val);
  else
    ri[nid] = update(ri[id], M+1, R, pos,val);
  
  st[nid] = st[li[nid]] + st[ri[nid]];
  return nid;
} 
 
int query(int nodeu, int L, int R,int l,int r)
{
  if(L > r || R < l)
    return 0;
  if(L>= l && R <= r)
    return st[nodeu];
  int M = (L+R)/2;
  int p1=  query(li[nodeu],L,M,l,r);
  int p2=  query(ri[nodeu],M+1,R,l,r);
  return p1 + p2;

} 
main()
{
  speed;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
  }
  root[0] = build(1,n);
  int qu;
  cin>>qu;
  int cnt = 0;
  for(int i=1;i<=qu;i++)
  {
    int type ;
      cin>>type;
      if(type == 1)
      {
          int time,id,v;
          cin>>time>>id>>v;
          root[++cnt] = update(root[time],1,n,id,v);
      }
      else{
         int l,r,time;
         cin>>time>>l>>r;
         cout<<query(root[time],1,n,l,r)<<endl;
      }
    
  }
} 