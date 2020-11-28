#include<bits/stdc++.h>
using namespace std;
#define all(x)           x.begin(), x.end()
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define pb push_back
#define MAX 1000000
#define MAXBLOCKS 10000
#define ll long long
#define fr(i,a,b) for(int i = a; i < b ; i++)
#define prv(v)   for(auto it = v.begin() ; it!= v.end() ;++it){cout<<*it<<" ";}cout<<endl;

int N;
int SZ;
//int sum[MAXBLOCKS];
vector<int> blocks[MAXBLOCKS];
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
  int r = min(i*SZ,N);
  fr(j,l,r+1)
  {
    m[j]=a[j];
    blocks[i].pb(a[j]);
    //sum[i]+=a[j];
  }
  sort(all(blocks[i]));
}
}

void update(int id,int val)
{ 
assert(id<=N);
int blockid = id/SZ + (id%SZ==0?0:1);
int to_find =   m[id];
fr(i,0,(int)blocks[blockid].size())
if(blocks[blockid][i]==to_find)
{
  blocks[blockid][i]=val;    
}
m[id]=val;
sort(all(blocks[blockid]));
}


long long query(int l ,int r,int k )
{
int leftblock = ceil(1.0*l/SZ);
int rightblock = ceil(1.0*r/SZ);
assert(l>0 && r<=N);
assert(l<=r);
ll temp = 0;
if(leftblock == rightblock)
{

  fr(i,l,r+1)
  if(m[i]>=k)temp++;

  //  temp += m[i]; 
}
else{
  int x = (leftblock-1)*SZ +1;
  fr(i,l,x+SZ)
    if(m[i]>=k)temp++;
    
   // temp+=m[i];
  fr(i,leftblock+1,rightblock)
    {
        temp += blocks[i].end() - lower_bound(all(blocks[i]),k);

    //temp += sum[i];
    }

  int y = (rightblock-1)*SZ+1;
  fr(i,y,r+1)
  {
    if(m[i]>=k)temp++;

    //temp+=m[i];
  }
}
return temp;

}


main()
{
speed;
cin>>N;
init();
build();
//update(1,11);
//cout<<query(1,10)<<endl;
int q;
cin>>q;

fr(i,0,q)
{
  int in;
  cin>>in;
  if(in==0)
  {
    int l,r,k;
    cin>>l>>r>>k;
    //elements greater than equal to k
    cout<<query(l,r,k)<<endl;
  }
  else
  {
    int id,val;
    cin>>id>>val;
    //point updates
    update(id,val);
  }
}

}