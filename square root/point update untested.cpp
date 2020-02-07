#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000
#define MAXBLOCKS 10000
#define ll long long
#define fr(i,a,b) for(int i = a; i < b ; i++)
int N;
int SZ;
int blocks[MAXBLOCKS];
int sum[MAXBLOCKS];
int a[MAX];
int m[MAX];

void init()
{
  fr(i,1,N+1)
  cin>>a[i];
}

void build()
{
  assert(N<=MAX);  
  //sqrt returns double however precision issues are not checked yet
  SZ = ceil(sqrt(N));
  assert(SZ<=MAXBLOCKS);


  fr(i,1,SZ+1)  
  {
    int l = (i-1)*SZ+1;
    int r = i*SZ;
    fr(j,l,r+1)
    {
      m[j]=a[j];
      sum[i]+=a[j];
    }
  }
}

void update(int id,int val)
{ 
  assert(id<=N);
  int blockid = id/SZ + (id%SZ==0?0:1);
  sum[blockid]+= (val-m[id]);
  m[id]=val;

}


long long query(int l ,int r)
{
  int leftblock = ceil(1.0*l/SZ);
  int rightblock = ceil(1.0*r/SZ);
  assert(l>0 && r<=N);
  assert(l<=r);
  ll temp = 0;
  if(leftblock == rightblock)
  {
    fr(i,l,r+1)
      temp += m[i]; 
  }
  else{

    int x = (leftblock-1)*SZ +1;
    fr(i,l,x+SZ)
      temp+=m[i];
    fr(i,leftblock+1,rightblock)
      temp += sum[i];

    int y = (rightblock-1)*SZ+1;
    fr(i,y,r+1)
    {
      temp+=m[i];
    }
  }
  return temp;

}


main()
{
  cin>>N;
  init();
  build();
  update(1,11);
  cout<<query(1,10)<<endl;




}