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
#define f first
#define s second
#define ll long long

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

void preorder(node *r){
	if(!r)
		return;
	cout<<r->v<<" ";
	preorder(r->left);
	preorder(r->right);
}
pair <node*,node*> convert(node* n){
	pair<node*,node*> p(n,n);
	if(n->left){
	pair<node*,node*> l = convert(n->left);
	(l.s)->right = n; 	
	 n->left = l.s;
	 p.f = l.f;
	}
	if(n->right){
	pair<node*,node*> r = convert(n->right);
	(r.f)->left = n;
	n->right = r.f;
	p.s = r.s;
	}
	return p;
}
void printlist(node *n){
	while(n!=NULL){
		cout<<n->v<<" ";
		n = n->right;
	}
}

main(){
	int n;
	cin>>n;

	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(7);
	root->right->right = new node(8);

	preorder(root);
	cout<<endl;
	node* list = convert(root).f;
	printlist(list);
}