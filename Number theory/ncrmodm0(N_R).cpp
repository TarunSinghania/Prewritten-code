#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define fre(i,a,b) for(int i =a ; i <= b; i++)
#define frej(j,a,b) for(int j =a ; j <= b; j++)
#define fra(s) for(auto it = s.begin(); it != s.end() ; ++it)

#define mkp make_pair 
#define pb push_back
#define pii pair<int,int>
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define c(a,b) cout<<a<<"--"<<b<<endl;
#define frv(i,a,v) for(int i =  a ; i < v.size() ; ++i)
#define cp(a,i)  cout<<a[i].first<<" "<<a[i].second<<endl;
#define mp(a) cout<<a->first<<" "<<a->second<<endl;
//sum array
#define sa(n) int a[n]; int s[n];cin>>a[0];s[0]=a[0];fr(i,1,n) {cin>>a[i];s[i]=s[i-1]+a[i];}
#define sa1(n) int a[n+1]; long long s[n+1]; a[0]=0; s[0]=0;cin>>a[1];s[1]=a[1];fr(i,2,n+1) {cin>>a[i];\
s[i]=s[i-1]+a[i];}



#define MOD 1000000007
#define N 1001
#define R 801
int c[R+1][N+1];

int ncrmodp (  int n ,int r )
{
        //time 0(n*r);

        //space 0(n*r);
   // int c[r+1][n+1];

    fre(i,1,n)
        c[0][i] = 1;

    fre(i,1,r)
        frej(j,i,n)
            { //  cout<<i<<j<<" ";
                if(j == i)
                    c[i][j] = 1;
                else
                    c[i][j] = (c[i-1][j-1] + c[i][j-1] )% MOD ;
            }


/*
   fre(i,0,r){
        frej(j,0,n)
            {cout<<c[i][j]<<" ";
        }
  
        cout<<endl;}
    cout<<c[r][n]<<endl;
   */

        return c[r][n] ;
}
int C[1000];
int ncrmodmop(int n ,int r )
{
    //optimised 
    //Store in c[]
    ///intiliase c tp zero by dedault global initialisation
    C[0] = 1;
    fre(i,1,n)
        {
            for(int j = min(i,r); j>0 ; j--)
                C[j]=(C[j] +C[j-1] )% MOD;
        
           // for(int a = 0 ;a<=r; a ++)
             //   cout<<C[a]<<" ";
        //    cout<<endl;
        }

        return C[r];

        //geeks for geeks would give wrokng

}



int main()
{

int t,a,b ;
cin>>t;
while(t--)
{
    cin>>a>>b;
cout<<ncrmodmop(a,b)<<endl;

} 

return 0 ;
}