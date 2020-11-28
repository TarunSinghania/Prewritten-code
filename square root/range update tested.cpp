#include<bits/stdc++.h>
using namespace std;
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)

#define MAX 200005
#define MAXBLOCKS 500
#define ll long long
#define fr(i,a,b) for(int i = a; i < b ; i++)

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
           
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

int N,m,k;
int SZ;
int blocks[MAXBLOCKS][1005];
int lazy[MAXBLOCKS];
int a[MAX];

void init()
{
  fr(i,1,N+1)
  cin>>a[i];
    //cout<<a[i]<<endl;}
}

void build()
{
  assert(N<=MAX);  
  //sqrt returns double however precision issues are not checked yet
  SZ = ceil(sqrt(N));
  assert(SZ<=MAXBLOCKS);

// cout<<"sz"<<SZ<<endl;
  fr(i,1,SZ+1)  
  {
    int l = (i-1)*SZ+1;
    int r = i*SZ;
    r = min(r,N);
    fr(j,l,r+1)
    {
      a[j]=a[j]%k;
      blocks[i][a[j]]++;
      //cout<<i<<a[j]<<endl;
    }
  }
}

void update(int id,int val)
{ 
  assert(id<=N);
//  cout<<"update"<<id<<val<<endl;
  int blockid = id/SZ + (id%SZ==0?0:1);
  blocks[blockid][a[id]]--;
  a[id]=(a[id]+val)%k;
  blocks[blockid][a[id]]++;
}

void rangeupdate(int l,int r,int val)
{ 
  assert(l>0);
  assert(l<=r);
  assert(r<=N);
  int leftblock = ceil(1.0*l/SZ);
  int rightblock = ceil(1.0*r/SZ);
  if(leftblock == rightblock)
  {
    fr(i,l,r+1)
      update(i,val);
  }
  else{
      int x = (leftblock-1)*SZ +1;
      fr(i,l,x+SZ)
          update(i,val);
      fr(i,leftblock+1,rightblock)
      { 
          lazy[i]=(lazy[i]+val)%k;
      } 
      int y = (rightblock-1)*SZ+1;
  //    cout<<"yr"<<y<<" "<<r<<endl;
      fr(i,y,r+1){
    //      cout<<"upd<<"<<i<<endl;
          update(i,val);
        }   
  }
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
      if((a[i]+lazy[leftblock])%k==0)
        temp++;
  }   
  else{

    int x = (leftblock-1)*SZ +1;
    fr(i,l,x+SZ){

        if((a[i]+lazy[leftblock])%k==0)
        temp++;
    }
    fr(i,leftblock+1,rightblock)
    {
        temp+= blocks[i][(k - lazy[i])%k];
    }
    int y = (rightblock-1)*SZ+1;
    fr(i,y,r+1)
    {
        if((a[i]+lazy[rightblock])%k==0)
        temp++;
    }

  }
  return temp;
}


main()
{
  speed;
  cin>>N>>m>>k;
  init();
  build();
  fr(i,1,m+1)
  {
    int t,l,r;
    cin>>t>>l>>r;
    l++;
    r++;
  //  cout<<t<<" "<<l<<" "<<r<<endl;
    if(t==1)
    {
      //cout<<l<<r<<endl;
      cout<<query(l,r)<<endl;
    } 
    else if(t==2)
    {
      int v;
      cin>>v;
    //  cout<<v<<endl;
      rangeupdate(l,r,v);
    }
  }
}