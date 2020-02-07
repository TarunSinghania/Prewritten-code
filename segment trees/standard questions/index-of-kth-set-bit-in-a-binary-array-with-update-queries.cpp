
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
        a[id]=val;
        t[n]=val;
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

int q(int n,int s,int e,int k){
   // cout<<n<<s<<e<<t[n]<<endl;
    if(k>t[n])
        return -1;
    if(s == e)
        return s;
    int m = (s+e)/2;
    if(t[2*n]>=k)
    {
        return q(2*n,s,m,k);
    }
    else
        return q(2*n+1,m+1,e,k-t[2*n]);
}


int main()
{
    int n ;
    cin>>n;
    for(int i =0 ; i < n ; i++)
        cin>>a[i];
    b(1,0,n-1);
    //u(1,0,n-1,1,0);
    for(int i =1 ; i < 18;i++)
        cout<<t[i]<<endl;
    cout<<q(1,0,n-1,3);



    return 0;
}