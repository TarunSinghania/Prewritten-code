#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define ll long long
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
//rangw update point query 
//which is nothinf but add v to l sub v from r+1
//prefix sum till i ill give value at i 
ll N;
//DO NOT FORGET TO SET ME

ll a[MAX];
ll bt[MAX];
void print(int n,int mx);
void printsubroutine(int n,int mxbit);


void update(ll idx,ll val)
{
    //donot pass idx =0;
    if(idx == 0)
    {
      //exit code -2 
      exit(-2);
    }
    //currently adding
    while(idx<=N)
    {
        bt[idx]+=val;
        idx+=idx&(-idx);
    }
}
ll prefixsum(int r)
{
    //currently reutrning prefix sum  
    ll res = 0;
    while(r)
    {
    res+=bt[r];
    r-=r&(-r);
    }
    return res;
}

void update2(ll idx,ll val)
{
    //setting a particular value at a index
    int past = prefixsum(idx)-prefixsum(idx-1);
    update(idx,-past);
    update(idx,val);
}

void update3(ll l,ll r ,ll val)
{
    update(l,val);
    update(r+1,-val);

}

ll pointquery(int i)
{
    return prefixsum(i);
}

void build()
{

    fr(i,1,N+1)
    update(i,a[i]);
}

void slow_clear(int n=N)
{
 //   cout<<n<<endl;
    fr(i,1,n+1)
    {
    //    cout<<"upd"<<i<<endl;
        update2(i,0);
    }

}


int main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
      //use co-ordinate compresssion for large numbers
        cin>>N;    
        // add a val to i 
        update3(1,5,4);
        update3(3,3,3);
        // replace i to val[i]
        cout<<pointquery(3)<<endl;
        cout<<pointquery(4)<<endl;

      //size of tree
      slow_clear(N);
    }

}



void print(int n,int mx)
{
    for(int i = mx-1 ; i >=0 ; i--)
    {
        if((n&(1<<i)))
        cout<<1;
        else
        cout<<0;
    }
    cout<<endl;
}

void printsubroutine(int n,int mxbit)
{

    fr(i,0,n)
    {
        cout<<i<<" ";
        int cnt = __builtin_popcount(i);
        fr(i,0,cnt-1)
        {
            fr(j,0,mxbit)
            cout<<" ";

            cout<<" ";
        }
        print(i,mxbit);
        cout<<"bit tree val at index "<<i<<" "<<bt[i]<<endl;
    }


}
