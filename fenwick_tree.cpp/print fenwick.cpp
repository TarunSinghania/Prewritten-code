#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define ll long long

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
   // cout<<bt[i]<<endl;
        
    }


}

main()
{

    printsubroutine(32,5);
}