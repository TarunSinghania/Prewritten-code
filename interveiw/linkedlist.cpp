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
#define MAX 100005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long

class node{
public:
	int data;
	node* next;

	node(){
		data =-1;
		next = NULL;
	}
	node( int v){
		data = v;
		next = NULL;
	}
	
};

class List{
public:
	int size;
	node* head;

	List(){
		size =0;
	}
	int delete_front(){
		if(size == 0)
			return -1;
		size -= 1;
		node* temp = head->next;
		delete(head);
		head = temp;
		return 0;
	}
	int delete_back(){
		if(size==0)
			return -1;
		size -= 1;
		if(size==1)
		{
			delete(head);
			head = NULL;
			return 0;
		}
		node* cur;node* prv;
		cur = head->next;
		prv = head;
		while(cur->next!=NULL)
			prv = cur,cur = cur->next;
		delete(cur);
		prv->next = NULL;
		return 0;
	}
	int delete_kth_node(int k){
		if(k<=0 || size < k)return -1;
		if(k==1){
			delete_front();
			return 0;
		}
		node* cur = head->next;
		node* prv = head;
		while(k>2)
		{
			prv = cur;
			cur = cur->next;
			k-=1;
		}
		prv->next = cur->next;
		delete(cur);
		return 0;
	}
	void front_insert(int v){
		if(size==0)
		{
			head = new node(v);
			size +=1;
		}
		else{
			node* temp = new node(v);
			temp->next = head;
			head = temp;
			size+=1;
		}
	}
	int insert_after_k_node(int v,int k){
		//0 refers to begining 
		if(size < k){
			return - 1;
		}
		if(k==0){front_insert(k);return 0;}
		node* temp = head;
		while(k>1)
		{
			temp = temp->next;
			k-=1;
		}
		node* temp2 = new node(v);
		temp2->next = temp->next;
		temp->next = temp2;
		return 0; 
	}

	void back_insert(int v){
		if(size == 0)
		{
			head = new node(v);
			size+=1;
		}
		else{

			node* temp = head;
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = new node(v);
			size+=1;
		}
	}

	void print(){
		if(size == 0)return;
		node* temp = head;
		while(temp->next != NULL){
			cout<<temp->data<<"->";
			temp = temp->next;
		}
		cout<<temp->data<<endl;
	}
};


main(){
	speed;
	int n;cin>>n;
	List l;
	fr(i,0,n){
		int x;
		cin>>x;
		cout<<x<<endl;
		l.back_insert(x);
	}
	l.print();
	l.front_insert(1);
	l.print();
	l.insert_after_k_node(0,0);
	l.insert_after_k_node(2,2);
	l.print();
	l.delete_front();
	l.print();
	l.delete_back();
	l.print();
	l.delete_kth_node(2);
	l.print();
}