//pizza
// 8 
// 8 4 2 5 1 6 3 7
// 1 2 4 8 5 3 6 7 
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
int p[1000],in[1000];
int id[1000];
class node{
public:
	int v;
	node *left,*right;
	node(int a){
		v = a;
		left = NULL;
		right = NULL;
	}
};
node* construct(int l,int r,int x, int y){
	int R = p[x];
	int index = id[R];
	int left_size = index -l;
	int right_size = r - index;
	node *root = new node(R);
	if(left_size>0)
	root->left = construct(l,index-1,x+1,x+left_size);
	if(right_size>0)
	root->right = construct(index+1,r,x+left_size+1,y);
}
void postorder(node *r){
	if(!r)
		return;
	postorder(r->left);
	postorder(r->right);
	cout<<r->v<<" ";
}

main(){
	int n;
	cin>>n;
	//post order,inorder
	fr(i,0,n){
		cin>>in[i];
		id[in[i]]=i;
	}
	fr(i,0,n){
		cin>>p[i];
	}
	//inorder l p r
	//pre order =  p l r
	node* root = construct(0,n-1,0,n-1);
	postorder(root);
}