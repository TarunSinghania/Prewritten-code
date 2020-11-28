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
#define prv(v) for(auto x: v)cout<<x<<",";cout<<endl;
#define MAX 105
#define all(x) x.begin(),x.end()
#define mkp make_pair 
//dfa[character][state] which state to go if I come accross character at that state
#define MAX_SYMBOLS 26
#define MAX_LENGTH 1000000
int dfa[MAX_SYMBOLS][MAX_LENGTH];

void __dfa(string s,int M=26){
	 //M denotes number of symbols in the language
	int l = s.length();
	dfa[s[0]-'a'][0]=1;
	int X=0;
	fr(j,1,l){
		fr(c,0,M){
			dfa[c][j]=dfa[c][X];
		}
		dfa[s[j]-'a'][j]=j+1;
		X = dfa[s[j]-'a'][X];
	}
 }
void prvv(int S,int L){
	fr(i,0,S){
		fr(j,0,L)
		{
			cout<<dfa[i][j]<<" ";
		}
		cout<<endl;
	}
}
int search(string s,string p){
	int j= 0;
	int pl = p.length();
	int l = s.length();
	fr(i,0,l){
		j = dfa[s[i]-'a'][j];
		if(j==pl)
			return i-pl;
	}
	return -1;
}	

main(){
	string a,b;
	cin>>a>>b;
	//search b in a
	__dfa(b);
   //	prvv(26,6);		
   	cout<<search(a,b);
}

