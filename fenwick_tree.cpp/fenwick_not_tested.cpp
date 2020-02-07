#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define ll long long

ll n;
ll a[MAX];
ll bt[MAX];



void update(ll idx,ll val)
{
    //currently adding
    while(idx<=n)
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


ll sum(int l,int r)
{
    return prefixsum(r)-prefixsum(l-1);
}

void build()
{

    fr(i,1,n+1)
    update(i,a[i]);
}

int main()
{
    
    cin>>n;

    
    fr(i,1,n+1) 
        a[i]=i;


    build();
    cout<<prefixsum(12);

}