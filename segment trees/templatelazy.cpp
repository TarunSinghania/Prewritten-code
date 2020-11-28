#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define fre(i,a,b) for(int i =a ; i <= b; i++)
#define fra(s) for(auto it = s.begin(); it != s.e() ; ++it)

#define mkp make_pair 
#define pb push_back
#define pii pair<int,int>
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define c(a,b) cout<<a<<"--"<<b<<el;
#define frv(i,a,v) for(int i =  a ; i < v.size() ; ++i)
#define cp(a,i)  cout<<a[i].first<<" "<<a[i].second<<el;
#define mp(a) cout<<a->first<<" "<<a->second<<el;



#define COUNT 10
#define INF 1e17

ll limit;



#define MOD 1000000007

const int N = 100001;

long long t[5*N];
long long l[5*N];

long long a[N];


void p2d(int n , int space)  
{  
     
    if(n>limit)
        return;
  
  
    space += COUNT;  
  
   
    p2d(2*n + 1, space);  
  
      
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<"(t"<<t[n]<<",l"<<l[n]<<")"<<"\n";  
  
    p2d(2*n, space);  
}  
  
// Wrapper over print2DUtil()  
void pst(int l)  
{  
    limit = l;
    // Pass initial space count as 0  
    p2d(1, 0);  
}  


void b(int n ,int s,int e)
{
    if(s==e)
        t[n] = a[s];
    else
    {
    int m = s + (e -s) / 2;
    
        b(2*n,s,m);
        b(2*n+1,m+1,e);
        t[n]=t[2*n]+t[2*n+1];
    }
}


void u(int n, int s, int e, int l1, int r1, ll val)
{
    if(l[n] != 0)
    { 
        // This n needs to be updated
        t[n] += (e-s+1)*l[n];    // Update it
        if(s != e)
        {
            l[n*2] += l[n];                  // Mark child as l
            l[n*2+1] += l[n];                // Mark child as l
        }
        l[n] = 0;                                  // Reset it
    }
    if(s > e or s > r1 or e < l1)              // Current segment is not within range [l, r]
        return;
    if(s >= l1 and e <= r1)
    {
        // Segment is fully within range
        t[n] += (e-s+1)*val;
        if(s != e)
        {
            // Not leaf n
            l[n*2] += val;
            l[n*2+1] += val;
        }
        return;
    }
    int m = s + (e -s) / 2;
    u(n*2, s, m, l1, r1, val);        // Updating left child
    u(n*2 + 1, m + 1, e, l1, r1, val);   // Updating right child
    t[n] =t[n*2]+ t[n*2+1];        // Updating root with max value 
}


ll q(int n, int s, int e, int l1, int r1)
{
   
    if(s > e or s > r1 or e < l1)
        return 0;         // Out of range//return accordingly 0 for sum range
    if(l[n] != 0)
    {
        // This n needs to be updated
        t[n] += (e-s+1)*l[n];            // Update it
        if(s != e)
        {
            l[n*2] += l[n];         // Mark child as l
            l[n*2+1] += l[n];    // Mark child as l
        }
        l[n] = 0;                 // Reset it
    }
    if(s >= l1 and e <= r1)             // Current segment is totally within range [l, r]
        return t[n];
    int m = s + (e -s) / 2;
    
    ll p1 = q(n*2, s, m, l1, r1);         // Q child
    ll p2 = q(n*2 + 1, m + 1, e, l1, r1); // Qt child
    return p1+p2;
}
    


int main()
{
int tests;
cin>>tests;
while(tests--)
{
    int n,q1;
    cin>>n>>q1;

    fr(i,0,4*n)
        t[i]=0,l[i]=0;
    fr(i,0,n+5)   
        a[i]=0;
    b(1,0,n-1);
    //fr(i,1,15)cout<<t[i]<<el;
    //pst(15);
    /*
    1
    8 6
    0 2 4 26
    0 4 8 80
    0 4 5 20
    1 8 8 
    0 5 7 14
    1 4 8

    */

    fr(i,0,q1){
        int x;
        cin>>x;
        if(x==1)
                {int a,b;
                    cin>>a>>b;
                    cout<<q(1,0,n-1,a-1,b-1)<<endl;
                }
        else{
            int a,b; ll r;
            cin>>a>>b>>r;
            u(1,0,n-1,a-1,b-1,r);


        }

    }

}
    return 0;
}