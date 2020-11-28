
#include<bits/stdc++.h>
using namespace std;

#define MAX 10000

int t[4* MAX];
int a[MAX+5];


void b( int n,int s,int e)
{
    if(s==e)
        {
            t[n]=a[s];
        }
    else
    {
        int m = (s+e)/2;
        b(2*n,s,m);
        b(2*n+1,m+1,e);
        t[n]=t[2*n]+t[2*n+1];
    }
}


void u(int n,int s,int e,int id,int val)
{
    
    if(s==e)
    {
        a[id]+=val;
        t[n]+=val;
    }
    else
    {
        int m = (s+e)/2;
        if(s<=id && id <=m)
        {
            u(2*n,s,m,id,val);
        }
        else
        {
            u(2*n+1,m+1,e,id,val);
        }

        t[n]=t[2*n]+t[2*n+1];
    }

}

int q(int n,int s,int e,int l,int r){
    
    if(r< s || e <l)
    {
        return 0;
    }
    if(l<= s && e<=r)
    {
        return t[n];
    }
    int m= (s+e)/2;

    int p1 = q(2*n,s,m,l,r);
    int p2 = q(2*n+1,m+1,e,l,r);
    return (p1+p2);

}


int main()
{
    //sum range
    int n ;
    cin>>n;
    for(int i =0 ; i < n ; i++)
        cin>>a[i];
    b(1,0,n-1);
    u(1,0,n-1,1,0);
    for(int i =1 ; i < 18;i++)
        cout<<t[i]<<endl;
  //  cout<<q(1,0,n-1,1,5);



    return 0;
}