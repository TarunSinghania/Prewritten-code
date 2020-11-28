//pizza
#include <bits/stdc++.h> 
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define fillm(m,r,c,k) fr(i,0,r)fr(j,0,c)m[i][j]=k;
#define prm(m,r,c) fr(i,0,r){fr(j,0,c){cout<<m[i][j]<<" "; }cout<<endl;}
#define pr(a,n)fr(i,0,n)cout<<a[i]<<",";cout<<endl;
#define endl '\n'
#define MOD 1000000007
#define INF 1000000000
#define prv(v) for(auto x: v)cout<<x<<" ";
#define MAX 100005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define eb emplace_back


vector<pair<int,int> > t[4*MAX];
int a[MAX+5];


pair<int,int> binary_s(int n,int time){
        //the vector is at a postition n search for  largest element less than or eqaul the time stamp
        int l = 0 ; int r = t[n].size()-1;
        while(l<r){
            int m = l + (r-l+1)/2;
            if(t[n][m].first <=  time)
                l = m;
            else
                r = m - 1;
        }
        return t[n][l];
}
void b( int n,int s,int e)
{
    if(s==e)
        {
            t[n].eb(mkp(0,a[s]));
        }
    else
    {
        int m = (s+e)/2;
        b(2*n,s,m);
        b(2*n+1,m+1,e);
        t[n].eb(mkp(0,t[2*n].back().second+t[2*n+1].back().second));
    }
}


void u(int n,int s,int e,int id,int val,int time,int prev_time)
{
    if(s==e)
    {
        pair<int,int> temp = binary_s(n,prev_time);
        t[n].eb(mkp(time,temp.second+val));
    }
    else
    {
    
        int m = (s+e)/2;
      pair<int,int> pl,pr;
        if(s<=id && id <=m)
        {
             u(2*n,s,m,id,val,time,prev_time);
             pl = binary_s(2*n,time);
             pr = binary_s(2*n+1,prev_time);
        }
        else
        {
            u(2*n+1,m+1,e,id,val,time,prev_time);
             pl = binary_s(2*n,prev_time);
             pr = binary_s(2*n+1,time);
        }
    t[n].eb(mkp(time,pl.second+pr.second));
    }
}

int q(int n,int s,int e,int l,int r,int time){
    
    if(r< s || e <l)
    {
        return 0;
    }
    if(l<= s && e<=r)
    {
        pair<int,int> temp  = binary_s(n,time);
        return temp.second;
    }
    int m= (s+e)/2;
    int p1 = q(2*n,s,m,l,r,time);
    int p2 = q(2*n+1,m+1,e,l,r,time);
    return (p1+p2);
}


main()
{
    //sum range
    speed;
    int n ;
    cin>>n;
    for(int i =0 ; i < n ; i++)
        cin>>a[i];
    b(1,0,n-1);
    int up;
    cin>>up;
    int cnt = 0;
    fr(i,0,up){
      int type ;
      cin>>type;
      if(type == 1)
      {
          int time,id,v;
          cin>>time>>id>>v;
          id--;
          u(1,0,n-1,id,v,++cnt,time);
      }
      else{
         int l,r,time;
         cin>>time>>l>>r;
          l--;r--;
         cout<<q(1,0,n-1,l,r,time)<<endl;
      }
    }
}
