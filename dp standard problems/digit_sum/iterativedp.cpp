//dp versoin
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
#define base 9
string s;
ll dp[11][100][2];
//dp[idx][prefixsum][lessbefore]
//digit sum of numbers if i have prefix sum previos to index idx {
		//with a less number at an any index set till prev index
		//with no less number at any previous index 	
//} 
// ll calc(int id,int prefixsum,bool lessbefore){
// 	if(id==s.size())
// 		return prefixsum;
// 	if(dp[id][prefixsum][lessbefore] != -1)
// 		return dp[id][prefixsum][lessbefore];
// 	int mx = base;
// 	if(!lessbefore)
// 		mx = s[id]-'0';
// 	dp[id][prefixsum][lessbefore]=0;
// 	fr(i,0,mx+1){
// 		if(lessbefore || i < mx)
// 		dp[id][prefixsum][lessbefore]+=calc(id+1,prefixsum+i,true);
// 		else
// 		dp[id][prefixsum][lessbefore]+=calc(id+1,prefixsum+i,false);		
// 	}
// 	return dp[id][prefixsum][lessbefore];
// }
void calc(){
	// //base 
	fr(i,0,100){
		fr(j,0,2){
			dp[(int)s.size()][i][j]=i;
		}
	}
	for(int idx = s.size()-1; idx >=0 ; idx--){
		for(int prefixsum = 0 ; prefixsum<=90 ; prefixsum++){

			//k==0
			int val = s[idx]-'0';
			for(int add  = 0 ; add < 10; add++)
				dp[idx][prefixsum][1]+=dp[idx+1][prefixsum+add][1];

			dp[idx][prefixsum][0] += dp[idx+1][prefixsum+val][0];
			for(int add = 0; add < val ; add++)
			 	dp[idx][prefixsum][0] += dp[idx+1][prefixsum+add][1];
			
		}
	}
}
int sm(string s){
    int res =0;
    fr(i,0,s.length()){
        res = res + (s[i]-'0');
    }
    return res;   
}   

int main(){
    // int t;
    // cin>>t;
    while(true){
        string a,b;
        cin>>a>>b;
        if(a=="-1" && b=="-1")
        	break;

        memset(dp,0,sizeof(dp));
        s = a;
        calc();
       // ll cnt1 = calc(0,0,false);
       ll cnt1 = dp[0][0][0];
        memset(dp,0,sizeof(dp)); 
       	s = b;
       	calc();
       ll cnt2 = dp[0][0][0]; 
        //ll cnt2 = calc(0,0,false);
        cout<<cnt2-cnt1+sm(a)<<endl;
    }
return 0;
}