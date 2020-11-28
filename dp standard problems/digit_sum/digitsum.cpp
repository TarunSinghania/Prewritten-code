//brute force digit sum (digit dp)
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
#define prv(v) for(auto x: v)cout<<x<<" ";cout<<endl;
#define MAX 400005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define f first
#define s second
string s;
int digsm(int id,int sm,bool less_before){
    if(id==s.length()){
        return sm;
    }
    int mx = 9;
    if(!less_before){
        mx = s[id]-'0';
    }
    int res = 0;
    fr(i,0,mx+1){
        if(less_before || i < mx){
            res = res + digsm(id+1,sm+i,true);
        }
        else
            res = res + digsm(id+1,sm+i,false);
    }
    return res;
}
int sm(string s){
    int res =0;
    fr(i,0,s.length()){
        res = res + (s[i]-'0');
    }
    return res;   
}   

int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        s = a;
        int cnt1 = digsm(0,0,false);
        s = b;
        int cnt2 = digsm(0,0,false);
        cout<<cnt2-cnt1+sm(a)<<endl;
    }
return 0;
}