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
#define prv(v) for(auto x: v)cout<<x<<" ";cout<<endl;
#define MAX 400005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long

class Stack{
public:
	int a[100];
	int c = 0;

	void push(int x){
		a[++c] = x;
	}
	int pop(){
		c-=1;
		return a[c+1];
	}
	bool empty(){
		return (c>0?false:true);
	}
	void insert_at_bottom(int k){
		if(empty()){push(k);return;}
		int v = pop();
		insert_at_bottom(k);
		push(v);
	}
	void reverse(){
		if(empty())return;
		int v = pop();
		reverse();
		insert_at_bottom(v);
	}
	int middle_element_subroutine(int k){
		if(k==0)
		{
			return pop();
		}
		int v = pop();
		int re = middle_element_subroutine(--k);
		push(v);
		return re;
	}

	int pop_middle_element(){

		return  middle_element_subroutine(c/2);
	}
};
main(){
	Stack s;
	s.push(1);
	s.push(2);
    s.push(3);
    s.insert_at_bottom(4);
    s.insert_at_bottom(5);
    s.reverse();
    s.pop_middle_element();	
    fr(i,1,s.c+1)
    cout<<s.a[i]<<endl;
}